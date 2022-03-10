// Included libraries
#include "subsystems/Drive.h"

// Constructor definitions ----------------------------------------------------
Drive::DriveBuilder::DriveBuilder() : position(0.0, 0.0, 0.0)
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

Drive::DriveBuilder Drive::DriveBuilder::WithPosition(PositionCalculation position)
{
    this->position = position;
    return *this;
}

Drive::DriveBuilder Drive::DriveBuilder::WithWheelSize(float wheelSize)
{
    this->wheelSize = wheelSize;
    return *this;
}

Drive Drive::DriveBuilder::Build()
{
    return Drive(*this);
}

// Constructor definitions ----------------------------------------------------
Drive::Drive() : position(0.0, 0.0, 0.0) 
{
    PID::PIDBuilder builder;
    distancePID = builder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    anglePID = builder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    turnPID = builder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
    
    taskInitialized = false;
    taskCompleted = false;
    startDistance = 0.0;
}

Drive::Drive(DriveBuilder builder) : position(0.0, 0.0, 0.0)
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

void Drive::SetDrive(float leftPower, float rightPower)
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

void Drive::GoToPosition(float targetX, float targetY, float power)
{
    // Calculate the current polar position from the robot
    float startDistance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
    float distance = startDistance;
    float angle = atan2(targetX - position.GetX(), targetY - position.GetY());
    float controlDistance = distance * cos(angle - position.GetTheta());
    if (angle > (3.1415 / 2.0))
        angle = 3.1415 - angle;
    else if (angle < -(3.1415 / 2.0))
        angle = -3.1415 - angle;
    float controlAngle = distance * sin(angle - position.GetTheta());

    // Set the PID controllers
    distancePID.SetTargetValue(controlDistance);
    anglePID.SetTargetValue(controlAngle);

    // Get the control values
    float controlValue = distancePID.GetControlValue(0.0);
    float adjustValue = anglePID.GetControlValue(0.0);
    if (controlValue > power)
        controlValue = power;
    else if (controlValue < -power)
        controlValue = -power;
    if (adjustValue > power)
        adjustValue = power;
    else if (adjustValue < -power)
        adjustValue = -power;

    // Set the motors for the control motion
    int timer = 0;
    while((distance > 1.5 || abs(controlValue) > 3.0) && timer < (startDistance * 80))
    {
        // Calculate all the variables
        UpdatePosition();
        distance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
        angle = atan2(targetY - position.GetY(), targetX - position.GetX());
        controlDistance = distance * cos(angle - position.GetTheta());
        if (angle > (3.1415 / 2.0))
            angle += 3.1415;
        else if (angle < -(3.1415 / 2.0))
            angle -= 3.1415;
        controlAngle = distance * sin(angle - position.GetTheta());

        // Set the PID controllers
        distancePID.SetTargetValue(controlDistance);
        anglePID.SetTargetValue(controlAngle);
        controlValue = distancePID.GetControlValue(0.0);
        adjustValue = anglePID.GetControlValue(0.0);

        // Control the motors
        SetDrive(controlValue - adjustValue, controlValue + adjustValue);

        // Update the loop
        //timer += 10;
        pros::delay(10);
    }
    SetDrive(0.0, 0.0);
}

void Drive::GoToPositionTask(float targetX, float targetY, float power)
{
    if(!taskInitialized)
    {
        startDistance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
        distancePID.SetMin(-power);
        distancePID.SetMax(power);
        anglePID.SetMin(-power);
        anglePID.SetMax(power);
        timer = 0;
        taskInitialized = true;
    }

    // Calculate the current polar position from the robot
    UpdatePosition();
    float distance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
    float angle = atan2(targetY - position.GetY(), targetX - position.GetX());
    float controlDistance = distance * cos(angle - position.GetTheta());
    if (angle > (3.1415 / 2.0))
        angle += 3.1415;
    else if (angle < -(3.1415 / 2.0))
        angle -= 3.1415;
    float controlAngle = distance * sin(angle - position.GetTheta());

    // Set the PID controllers
    distancePID.SetTargetValue(controlDistance);
    anglePID.SetTargetValue(controlAngle);
    float controlValue = distancePID.GetControlValue(0.0);
    float adjustValue = anglePID.GetControlValue(0.0);

    // Update the task
    if((distance > 1.5 || abs(controlValue) > 3.0) && timer < (startDistance * 40))
    {
        SetDrive(controlValue - adjustValue, controlValue + adjustValue);
        timer += 10;
    }
    else
    {
        taskCompleted = true;
        SetDrive(0.0, 0.0);
    }
}

void Drive::TurnToAngle(float targetAngle)
{
    // Initialize variables
    timer = 0;
    float angle = position.GetTheta() / 0.0175;
    float turnSize = abs(targetAngle - angle);
    turnPID.SetTargetValue(targetAngle);
    float controlValue = turnPID.GetControlValue(angle);

    // Loop until the target is reached
    while((abs(targetAngle - angle) > 0.1 || abs(controlValue) > 1.0) && timer < (turnSize * 20))
    {
        UpdatePosition();
        angle = position.GetTheta() / 0.0175;
        controlValue = turnPID.GetControlValue(angle);
        SetDrive(-controlValue, controlValue);
        timer += 10;
        pros::delay(10);
    }
    SetDrive(0.0, 0.0);
}

void Drive::TurnToAngleTask(float targetAngle, float power)
{
    if(!taskInitialized)
    {
        startAngle = abs(targetAngle - (position.GetTheta() / 0.0175));
        turnPID.SetMin(-power);
        turnPID.SetMax(power);
        timer = 0;
        taskInitialized = true;
    }

    // Calculate variables
    UpdatePosition();
    float angle = position.GetTheta() / 0.0175;

    // Get the PID control value
    turnPID.SetTargetValue(targetAngle);
    float controlValue = turnPID.GetControlValue(angle);

    // Update the task
    if((abs(targetAngle - angle) > 0.1 || abs(controlValue) > 1.0) && timer < (startAngle * 20))
    {
        SetDrive(-controlValue, controlValue);
        timer += 10;
    }
    else
    {
        taskCompleted = true;
        SetDrive(0.0, 0.0);
    }
}

bool Drive::TaskComplete()
{
    return taskCompleted;
}

void Drive::NewTask()
{
    taskInitialized = false;
    taskCompleted = false;
}

void Drive::SetX(float x)
{
    position.SetPosition(x, position.GetY(), position.GetTheta());
}

void Drive::SetY(float y)
{
    position.SetPosition(position.GetX(), y, position.GetTheta());
}

void Drive::SetTheta(float theta)
{
    position.SetPosition(position.GetX(), position.GetY(), theta * 0.0175);
}

void Drive::SetPosition(float x, float y, float theta)
{
    position.SetPosition(x, y, theta * 0.0175);
}

float Drive::GetX() const
{
    return position.GetX();
}

float Drive::GetY() const
{
    return position.GetY();
}

float Drive::GetTheta() const
{
    return position.GetTheta();
}

void Drive::UpdatePosition()
{
    // Get the left, right, and strafe values in inches
    std::list<pros::Motor>::iterator iterator = leftMotorList.begin(); 
    float leftValue = iterator->get_position() * wheelSize * 3.1415 / 36000.0;
    iterator++;
    float rightValue = iterator->get_position() * wheelSize * 3.1415 / -36000.0;
    iterator++;
    float strafeValue = iterator->get_position() * wheelSize * 3.1415 / -36000.0;

    // Input those values to the tracking algorithm
    position.UpdatePosition(leftValue, rightValue, strafeValue);
}