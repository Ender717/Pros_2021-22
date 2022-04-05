// Included libraries
#include "subsystems/Drive.hpp"

// Constructor definitions ----------------------------------------------------
Drive::DriveBuilder::DriveBuilder()
{
    wheelSize = -1.0;
}

// Public method definitions --------------------------------------------------
Drive::DriveBuilder Drive::DriveBuilder::WithLeftMotor(pros::Motor motor)
{
    leftMotorList.push_back(motor);
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithRightMotor(pros::Motor motor)
{
    rightMotorList.push_back(motor);
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithTrackingSensor(pros::Rotation sensor)
{
    trackingList.push_back(sensor);
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithDistancePID(PID pid)
{
    this->distancePID = pid;
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithAnglePID(PID pid)
{
    this->anglePID = pid;
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithTurnPID(PID pid)
{
    this->turnPID = pid;
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithPosition(Position position)
{
    this->position = position;
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithWheelSize(double wheelSize)
{
    this->wheelSize = wheelSize;
    return *this;
}

Drive Drive::DriveBuilder::Build()
{
    return Drive(*this);
}

// Constructor definitions ----------------------------------------------------
Drive::Drive()
{
    PID::PIDBuilder builder;
    distancePID = builder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    anglePID = builder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    turnPID = builder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
}

Drive::Drive(DriveBuilder builder)
{
    // Set the left motors
    while(builder.leftMotorList.size() > 0)
    {
        this->leftMotorList.push_back(builder.leftMotorList.front());
        builder.leftMotorList.pop_front();
    }

    // Set the right motors
    while(builder.rightMotorList.size() > 0)
    {
        this->rightMotorList.push_back(builder.rightMotorList.front());
        builder.rightMotorList.pop_front();
    }

    // Set the tracking sensors
    while(builder.trackingList.size() > 0)
    {
        this->trackingList.push_back(builder.trackingList.front());
        builder.trackingList.pop_front();
    }

    // Set the PID controllers
    this->distancePID = builder.distancePID;
    this->anglePID = builder.anglePID;
    this->turnPID = builder.turnPID;

    // Set the position tracking
    this->position = builder.position;

    // Set the wheel size
    if(builder.wheelSize != -1.0)
        this->wheelSize = builder.wheelSize;
    else
        this->wheelSize = 2.75;
}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    // Initialize the motors
    for (std::list<pros::Motor>::iterator iterator = leftMotorList.begin(); 
        iterator != leftMotorList.end(); iterator++)
    {
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }
    for (std::list<pros::Motor>::iterator iterator = rightMotorList.begin(); 
        iterator != rightMotorList.end(); iterator++)
    {
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    // Initialize the tracking wheels
    for (std::list<pros::Rotation>::iterator iterator = trackingList.begin(); 
        iterator != trackingList.end(); iterator++)
    {
        iterator->set_position(0.0);
    }
}

void Drive::SetDrive(double leftPower, double rightPower)
{
    // Move the left side of the drive
    for (std::list<pros::Motor>::iterator iterator = leftMotorList.begin(); 
        iterator != leftMotorList.end(); iterator++)
    {
        iterator->move(leftPower);
    }

    // Move the right side of the drive
    for (std::list<pros::Motor>::iterator iterator = rightMotorList.begin(); 
        iterator != rightMotorList.end(); iterator++)
    {
        iterator->move(rightPower);
    }
}

void Drive::DriveStraight(double distance)
{
    // Create and initialize variables
    double startPosition = trackingList.front().get_position() / 36000.0 * 3.1415 * wheelSize;
    double targetPosition = startPosition + distance;
    double startAngle = position.GetAngle();
    double currentPosition = startPosition;
    double currentAngle = startAngle;
    double power = 127.0;

    // Initialize the PID controllers
    distancePID.SetTargetValue(targetPosition);
    anglePID.SetTargetValue(startAngle);

    // Loop until finished
    while(abs(currentPosition - targetPosition) > 0.5)
    {
        // Update the current position
        currentPosition = trackingList.front().get_position() / 36000.0 * 3.1415 * wheelSize;
        currentAngle = position.GetAngle();

        // Update the control values
        double distanceControl = distancePID.GetControlValue(currentPosition);
        double angleControl = anglePID.GetControlValue(currentAngle);
        distanceControl *= (power / 127.0);
        angleControl *= (power / 127.0);

        // Update the motor power levels
        SetDrive(distanceControl - angleControl, distanceControl + angleControl);
        pros::delay(5);
    }

    // Cut the power
    SetDrive(0.0, 0.0);
}

void Drive::TurnToAngle(double targetAngle, double power)
{

}

void Drive::SetX(double x)
{
    position.SetX(x);
}

void Drive::SetY(double y)
{
    position.SetY(y);;
}

void Drive::SetTheta(double theta)
{
    position.SetAngle(theta);
}

void Drive::SetPosition(double x, double y, double theta)
{
    position.SetPosition(x, y, theta * 0.0175);
}

double Drive::GetX() const
{
    return position.GetX();
}

double Drive::GetY() const
{
    return position.GetY();
}

double Drive::GetTheta() const
{
    return position.GetAngle() * 3.1415 / 180.0;
}

void Drive::UpdatePosition()
{
    // Get the left, right, and strafe values in inches
    std::list<pros::Rotation>::iterator iterator = trackingList.begin(); 
    double leftValue = iterator->get_position() * wheelSize * 3.1415 / 36000.0;
    iterator++;
    double rightValue = iterator->get_position() * wheelSize * 3.1415 / -36000.0;
    iterator++;
    double strafeValue = iterator->get_position() * wheelSize * 3.1415 / -36000.0;

    // Input those values to the tracking algorithm
    position.UpdatePosition(leftValue, rightValue, strafeValue);
}