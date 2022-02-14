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
    float startDistance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
    float distance = startDistance;
    float angle = atan2(targetX - position.GetX(), targetY - position.GetY());
    float controlDistance = distance * cos(angle - position.GetTheta());

    // Set the PID controllers
    distancePID.SetTargetValue(controlDistance);
    anglePID.SetTargetValue(angle);

    // Get the control values
    float controlValue = distancePID.GetControlValue(0.0);
    float adjustValue = anglePID.GetControlValue(position.GetTheta());

    // Set the motors for the control motion
    int timer = 0;
    while((distance > 0.5 || controlValue > 3.0) && timer < (startDistance * 30))
    {
        // Calculate all the variables
        distance = sqrt(pow(targetX - position.GetX(), 2) + pow(targetY - position.GetY(), 2));
        angle = atan2(targetX - position.GetX(), targetY - position.GetY());
        controlDistance = distance * cos(angle - position.GetTheta());

        // Set the PID controllers
        distancePID.SetTargetValue(controlDistance);
        controlValue = distancePID.GetControlValue(0.0);
        adjustValue = anglePID.GetControlValue(position.GetTheta());

        // Control the motors
        SetDrive(controlValue - adjustValue, controlValue + adjustValue);

        // Update the loop
        timer += 10;
        pros::delay(10);
    }
    SetDrive(0.0, 0.0);
}

void Drive::TurnToAngle(float targetAngle)
{
    // Initialize variables
    int timer = 0;
    float angle = position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS;
    turnPID.SetTargetValue(targetAngle);
    float controlValue = turnPID.GetControlValue(angle);

    // Loop until the target is reached
    while((abs(targetAngle - angle) > 1.0 || controlValue > 3.0) && timer < 3000)
    {
        angle = position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS;
        controlValue = turnPID.GetControlValue(angle);
        SetDrive(-controlValue, controlValue);
        timer += 10;
        pros::delay(10);
    }
    SetDrive(0.0, 0.0);
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

void Drive::PrintPosition()
{
    // Write the coordinates
    pros::screen::set_pen(COLOR_WHITE);
    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 32, "X: %.2f", position.GetX());
    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 72, "Y: %.2f", position.GetY());
    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 112, "Theta: %.2f", (position.GetTheta() / DriveConfig::DEGREES_TO_RADIANS));

    // Draw the field
    pros::screen::set_pen(COLOR_LIGHT_GRAY);
    pros::screen::fill_rect(224, 16, 464, 256);

    // Draw the tape lines
    pros::screen::set_pen(COLOR_WHITE);
    pros::screen::draw_line(304, 16, 304, 256);
    pros::screen::draw_line(343, 16, 343, 256);
    pros::screen::draw_line(345, 16, 345, 256);
    pros::screen::draw_line(384, 16, 384, 256);
    pros::screen::draw_line(264, 256, 304, 216);
    pros::screen::draw_line(384, 56, 424, 16);

    // Draw the red platform
    pros::screen::set_pen(COLOR_RED);
    for(int i = 0; i < 5; i++)
        pros::screen::draw_rect(227 + i, 91 + i, 262 - i, 181 - i);

    // Draw the blue platform
    pros::screen::set_pen(COLOR_BLUE);
    for(int i = 0; i < 5; i++)
        pros::screen::draw_rect(426 + i, 91 + i, 461 - i, 181 - i);

    // Draw the field perimeter
    pros::screen::set_pen(COLOR_BLACK);
    for(int i = 0; i < 2; i++)
        pros::screen::draw_rect(223 + i, 15 + i, 465 - i, 257 - i);

    // Draw the robot
    pros::screen::set_pen(COLOR_ORANGE);
    pros::screen::draw_circle(position.GetX(), position.GetY(), 15);

    // Draw an arrow to show the direction of the robot
    pros::screen::set_pen(COLOR_BLACK);
    float robotX = 344 + (position.GetX() * 5.0 / 3.0);
    float robotY = 136 + (position.GetY() * 5.0 / 3.0);
    float lineX = 12 * cos(position.GetTheta());
    float lineY = 12 * sin(position.GetTheta());
    pros::screen::draw_line(robotX - lineX, robotY - lineY, 
                            robotX + lineX, robotY + lineY);
    pros::screen::draw_line(robotX + lineX, robotY + lineY, 
                            robotX + (lineX / 3) + (5 * cos(position.GetTheta() + (3.1415 / 2))), 
                            robotY + (lineY / 3) + (5 * sin(position.GetTheta() + (3.1415 / 2))));
    pros::screen::draw_line(robotX + lineX, robotY + lineY, 
                            robotX + (lineX / 3) + (5 * cos(position.GetTheta() - (3.1415 / 2))), 
                            robotY + (lineY / 3) + (5 * sin(position.GetTheta() - (3.1415 / 2))));
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