// Included libraries
#include "subsystems/Drive.h"

// Constructor definitions ------------------------------------------------
Drive::Drive(float startX, float startY, float startTheta) 
            : distancePID(8.3, 0.5, 0.15, 0.0, -127.0, 127.0, 40.0, 0.0),
            anglePID(1.0, 0.01, 0.02, 0.0, -30.0, 30.0, 10.0, 0.0),
            turnPID(7.3, 0.35, 0.10, 0.0, -127.0, 127.0, 40.0, 0.0),
            position(startX, startY, startTheta) {}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    // Initialize the tracking sensors
    DriveConfig::leftTrackingSensor.set_position(0.0);
    DriveConfig::rightTrackingSensor.set_position(0.0);
    DriveConfig::strafeTrackingSensor.set_position(0.0);

    // Initialize the motor brake modes
    DriveConfig::leftFrontDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftMiddleDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftRearDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightFrontDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightMiddleDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightRearDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Drive::SetDrive(float leftPower, float rightPower)
{
    // Move the left side of the drive
    DriveConfig::leftFrontDriveMotor.move(leftPower);
    DriveConfig::leftMiddleDriveMotor.move(leftPower);
    DriveConfig::leftRearDriveMotor.move(leftPower);

    // Move the right side of the drive
    DriveConfig::rightFrontDriveMotor.move(rightPower);
    DriveConfig::rightMiddleDriveMotor.move(rightPower);
    DriveConfig::rightRearDriveMotor.move(rightPower);
}

void Drive::GoToPosition(float targetX, float targetY)
{
    // Calculate the current polar position from the robot
    float distance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
    float angle = atan2(targetX - position.GetX(), targetY - position.GetY());

    // Set the PID controllers
    distancePID.SetTargetValue(distance);
    anglePID.SetTargetValue(angle);
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

void Drive::UpdatePosition()
{
    // Get the left, right, and strafe values in inches
    float leftValue = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    float rightValue = DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION;
    float strafeValue = DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;

    // Input those values to the tracking algorithm
    position.UpdatePosition(leftValue, rightValue, strafeValue);
}