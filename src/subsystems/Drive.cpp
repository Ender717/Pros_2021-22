// Included libraries
#include "subsystems/Drive.hpp"

// Constructor definitions ----------------------------------------------------
Drive::DriveBuilder::DriveBuilder()
{
    leftMotorList = nullptr;
    rightMotorList = nullptr;
    leftTrackingSensor = nullptr;
    rightTrackingSensor = nullptr;
    strafeTrackingSensor = nullptr;
    distancePID = nullptr;
    anglePID = nullptr;
    turnPID = nullptr;
    position = nullptr;
    wheelSize = nullptr;
}

// Destructor definitions -----------------------------------------------------
Drive::DriveBuilder::~DriveBuilder()
{
    if (leftMotorList != nullptr)
    {
        delete leftMotorList;
        leftMotorList = nullptr;
    }
    if (rightMotorList != nullptr)
    {
        delete rightMotorList;
        rightMotorList = nullptr;
    }
    leftTrackingSensor = nullptr;
    rightTrackingSensor = nullptr;
    strafeTrackingSensor = nullptr;
    distancePID = nullptr;
    anglePID = nullptr;
    turnPID = nullptr;
    position = nullptr;
    if (wheelSize != nullptr)
    {
        delete wheelSize;
        wheelSize = nullptr;
    }
}

// Public method definitions --------------------------------------------------
Drive::DriveBuilder* Drive::DriveBuilder::WithLeftMotor(pros::Motor* motor)
{
    if (leftMotorList == nullptr)
        leftMotorList = new std::list<pros::Motor*>();
    leftMotorList->push_back(motor);
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithRightMotor(pros::Motor* motor)
{
    if (rightMotorList == nullptr)
        rightMotorList = new std::list<pros::Motor*>();
    rightMotorList->push_back(motor);
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithLeftTrackingSensor(pros::Rotation* sensor)
{
    leftTrackingSensor = sensor;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithRightTrackingSensor(pros::Rotation* sensor)
{
    rightTrackingSensor = sensor;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithStrafeTrackingSensor(pros::Rotation* sensor)
{
    strafeTrackingSensor = sensor;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithDistancePID(PID* pid)
{
    distancePID = pid;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithAnglePID(PID* pid)
{
    anglePID = pid;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithTurnPID(PID* pid)
{
    turnPID = pid;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithPosition(Position* position)
{
    this->position = position;
    return this;
}

Drive::DriveBuilder* Drive::DriveBuilder::WithWheelSize(double wheelSize)
{
    if (this->wheelSize == nullptr)
        this->wheelSize = new double;
    *this->wheelSize = wheelSize;
    return this;
}

Drive* Drive::DriveBuilder::Build()
{
    return new Drive(this);
}

// Constructor definitions ----------------------------------------------------
Drive::Drive(DriveBuilder* builder)
{
    // Create the pointers
    leftMotorList = new std::list<pros::Motor*>();
    rightMotorList = new std::list<pros::Motor*>();
    wheelSize = new double;

    // Set the left motors
    if (builder->leftMotorList != nullptr)
        for (std::list<pros::Motor*>::iterator iterator = builder->leftMotorList->begin(); 
            iterator != builder->leftMotorList->end(); iterator++)
            this->leftMotorList->push_back(*iterator);

    // Set the right motors
    if (builder->rightMotorList != nullptr)
        for (std::list<pros::Motor*>::iterator iterator = builder->rightMotorList->begin(); 
            iterator != builder->rightMotorList->end(); iterator++)
            this->rightMotorList->push_back(*iterator);

    // Set the tracking sensors
    this->leftTrackingSensor = builder->leftTrackingSensor;
    this->rightTrackingSensor = builder->rightTrackingSensor;
    this->strafeTrackingSensor = builder->strafeTrackingSensor;

    // Set the PID controllers
    this->distancePID = builder->distancePID;
    this->anglePID = builder->anglePID;
    this->turnPID = builder->turnPID;

    // Set the position tracking
    this->position = builder->position;

    // Set the wheel size
    if(builder->wheelSize != nullptr)
        *this->wheelSize = *builder->wheelSize;
    else
        *this->wheelSize = 2.75;
}

// Destructor definitions -------------------------------------------------
Drive::~Drive()
{
    if (leftMotorList != nullptr)
    {
        for (std::list<pros::Motor*>::iterator iterator = leftMotorList->begin(); 
            iterator != leftMotorList->end(); iterator++)
        {
            delete *iterator;
            *iterator = nullptr;
        }
        delete leftMotorList;
        leftMotorList = nullptr;
    }
    if (rightMotorList != nullptr)
    {
        for (std::list<pros::Motor*>::iterator iterator = rightMotorList->begin(); 
            iterator != rightMotorList->end(); iterator++)
        {
            delete *iterator;
            *iterator = nullptr;
        }
        delete rightMotorList;
        rightMotorList = nullptr;
    }
    if (leftTrackingSensor != nullptr)
    {
        delete leftTrackingSensor;
        leftTrackingSensor = nullptr;
    }
    if (rightTrackingSensor != nullptr)
    {
        delete rightTrackingSensor;
        rightTrackingSensor = nullptr;
    }
    if (strafeTrackingSensor != nullptr)
    {
        delete strafeTrackingSensor;
        strafeTrackingSensor = nullptr;
    }
    if (distancePID != nullptr)
    {
        delete distancePID;
        distancePID = nullptr;
    }
    if (anglePID != nullptr)
    {
        delete anglePID;
        anglePID = nullptr;
    }
    if (turnPID != nullptr)
    {
        delete turnPID;
        turnPID = nullptr;
    }
    if (position != nullptr)
    {
        delete position;
        position = nullptr;
    }
    if (wheelSize != nullptr)
    {
        delete wheelSize;
        wheelSize = nullptr;
    }
}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    // Initialize the motors
    for (std::list<pros::Motor*>::iterator iterator = leftMotorList->begin(); 
        iterator != leftMotorList->end(); iterator++)
    {
        (*iterator)->tare_position();
        (*iterator)->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }
    for (std::list<pros::Motor*>::iterator iterator = rightMotorList->begin(); 
        iterator != rightMotorList->end(); iterator++)
    {
        (*iterator)->tare_position();
        (*iterator)->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    // Initialize the tracking wheels
    leftTrackingSensor->set_position(0.0);
    rightTrackingSensor->set_position(0.0);
    strafeTrackingSensor->set_position(0.0);
}

void Drive::SetDrive(double leftPower, double rightPower)
{
    // Move the left side of the drive
    for (std::list<pros::Motor*>::iterator iterator = leftMotorList->begin(); 
        iterator != leftMotorList->end(); iterator++)
        (*iterator)->move(leftPower);

    // Move the right side of the drive
    for (std::list<pros::Motor*>::iterator iterator = rightMotorList->begin(); 
        iterator != rightMotorList->end(); iterator++)
        (*iterator)->move(rightPower);
}

void Drive::DriveStraight(double distance)
{
    // Create and initialize variables
    double startPosition = leftTrackingSensor->get_position() / 36000.0 * 3.1415 * *wheelSize;
    double targetPosition = startPosition + distance;
    double startAngle = position->GetAngle();
    double currentPosition = startPosition;
    double currentAngle = startAngle;
    double power = 127.0;
    int timer = 0;

    // Initialize the PID controllers
    distancePID->SetTargetValue(targetPosition);
    anglePID->SetTargetValue(startAngle);

    // Loop until finished
    while(timer < 5000)
    {
        // Update the current position
        currentPosition = leftTrackingSensor->get_position() / 36000.0 * 3.1415 * *wheelSize;
        currentAngle = position->GetAngle();

        // Update the control values
        double distanceControl = distancePID->GetControlValue(currentPosition);
        double angleControl = anglePID->GetControlValue(currentAngle);
        distanceControl *= (power / 127.0);
        angleControl *= (power / 127.0);

        // Update the motor power levels
        SetDrive(distanceControl - angleControl, distanceControl + angleControl);

        // Update the timer
        if (abs(currentPosition - targetPosition) < 0.1)
            timer += 5;
        else
            timer = 0;
        pros::delay(10);
    }

    // Cut the power
    SetDrive(0.0, 0.0);
}

void Drive::TurnToAngle(double targetAngle)
{

}

void Drive::SetX(double x)
{
    position->SetX(x);
}

void Drive::SetY(double y)
{
    position->SetY(y);;
}

void Drive::SetTheta(double theta)
{
    position->SetAngle(theta);
}

void Drive::SetPosition(double x, double y, double theta)
{
    position->SetPosition(x, y, theta * 0.0175);
}

double Drive::GetX() const
{
    return position->GetX();
}

double Drive::GetY() const
{
    return position->GetY();
}

double Drive::GetTheta() const
{
    return position->GetAngle() * 3.1415 / 180.0;
}

void Drive::UpdatePosition()
{
    // Get the left, right, and strafe values in inches
    double leftValue = leftTrackingSensor->get_position() * (*wheelSize) * 3.1415 / 36000.0;
    double rightValue = rightTrackingSensor->get_position() * (*wheelSize) * 3.1415 / -36000.0;
    double strafeValue = strafeTrackingSensor->get_position() * (*wheelSize) * 3.1415 / 36000.0;

    // Input those values to the tracking algorithm
    position->UpdatePosition(leftValue, rightValue, strafeValue);
}