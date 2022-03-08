// Included libraries
#include "subsystems/Drive.h"

// Constructor definitions ------------------------------------------------
Drive::Drive() : position(0.0, 0.0, 0.0) 
{
    PIDBuilder builder;
    distancePID = builder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    anglePID = builder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    turnPID = builder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
    
    taskInitialized = false;
    taskCompleted = false;
    startDistance = 0.0;
}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    // Initialize the tracking sensors
    DriveConfig::leftTrackingSensor.set_position(0.0);
    DriveConfig::rightTrackingSensor.set_position(0.0);
    DriveConfig::strafeTrackingSensor.set_position(0.0);
    DriveConfig::strafeTrackingSensor.set_reversed(true);

    // Initialize the motor brake modes
    DriveConfig::leftDrive1Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftDrive2Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftDrive3Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftDrive4Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightDrive1Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightDrive2Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightDrive3Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightDrive4Motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Drive::SetDrive(float leftPower, float rightPower)
{
    // Move the left side of the drive
    DriveConfig::leftDrive1Motor.move(leftPower);
    DriveConfig::leftDrive2Motor.move(leftPower);
    DriveConfig::leftDrive3Motor.move(leftPower);
    DriveConfig::leftDrive4Motor.move(leftPower);

    // Move the right side of the drive
    DriveConfig::rightDrive1Motor.move(rightPower);
    DriveConfig::rightDrive2Motor.move(rightPower);
    DriveConfig::rightDrive3Motor.move(rightPower);
    DriveConfig::rightDrive4Motor.move(rightPower);
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
    float angle = position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS;
    float turnSize = abs(targetAngle - angle);
    turnPID.SetTargetValue(targetAngle);
    float controlValue = turnPID.GetControlValue(angle);

    // Loop until the target is reached
    while((abs(targetAngle - angle) > 0.1 || abs(controlValue) > 1.0) && timer < (turnSize * 20))
    {
        UpdatePosition();
        angle = position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS;
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
        startAngle = abs(targetAngle - (position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS));
        turnPID.SetMin(-power);
        turnPID.SetMax(power);
        timer = 0;
        taskInitialized = true;
    }

    // Calculate variables
    UpdatePosition();
    float angle = position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS;

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
    position.SetPosition(position.GetX(), position.GetY(), theta * DriveConfig::DEGREES_TO_RADIANS);
}

void Drive::SetPosition(float x, float y, float theta)
{
    position.SetPosition(x, y, theta * DriveConfig::DEGREES_TO_RADIANS);
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
    float leftValue = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    float rightValue = DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION;
    float strafeValue = DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;

    // Input those values to the tracking algorithm
    position.UpdatePosition(leftValue, rightValue, strafeValue);
}