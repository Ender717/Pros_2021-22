// Included libraries
#include "subsystems/Drive.h"

// Private method definitions -------------------------------------------------
float Drive::CalculateAngle(float startX, float startY, float endX, float endY)
{
    return atan2(endY - startY, endX - startX) / DriveConfig::DEGREES_TO_RADIANS;
}

float Drive::CalculateDistance(float startX, float startY, float endX, float endY)
{
    return sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));
}

// Constructor definitions ------------------------------------------------
Drive::Drive(int n) {}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    DriveConfig::leftTrackingSensor.set_position(0.0);
    DriveConfig::rightTrackingSensor.set_position(0.0);
    DriveConfig::strafeTrackingSensor.set_position(0.0);
    DriveConfig::leftFrontDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftMiddleDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::leftRearDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightFrontDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightMiddleDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    DriveConfig::rightRearDriveMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

float Drive::GetDistance()
{
    return DriveConfig::leftTrackingSensor.get_position();
}

// Public method definitions --------------------------------------------------
void Drive::DriveStraight(float inches, float power, PositionCalculation& position)
{
    PID distancePID(8.3, 0.5, 0.15, 0.0, -power, power, (power / 3.0), 0.0);
    PID anglePID(1.0, 0.01, 0.02, 0.0, -(power / 4.0), (power / 4.0), (power / 12.0), position.GetTheta());
    float startValue = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    distancePID.SetTargetValue(inches + startValue);
    anglePID.SetTargetValue(position.GetTheta());
    float distance = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    float controlValue = distancePID.GetControlValue(distance);
    float adjustValue = anglePID.GetControlValue(position.GetTheta());

    while(abs(inches + startValue - distance) > 1.2 || controlValue > 3)
    {
        distance = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
        controlValue = distancePID.GetControlValue(distance);
        adjustValue = anglePID.GetControlValue(position.GetTheta());
        SetLeftDrive(controlValue + adjustValue);
        SetRightDrive(controlValue - adjustValue);
        pros::delay(2);
    }
    SetLeftDrive(0.0);
    SetRightDrive(0.0);
}

void Drive::SpinTurn(float degrees, float power, PositionCalculation& position)
{
    PID turnPID(7.3, 0.35, 0.10, 0.0, -power, power, (power / 3.0), 0.0);
    position.UpdatePosition();
    float targetAngle = position.GetTheta() + degrees;
    turnPID.SetTargetValue(targetAngle);
    float angle = position.GetTheta();
    float controlValue = turnPID.GetControlValue(angle);

    while(abs(targetAngle - angle) > 0.1 || controlValue > 1)
    {
        position.UpdatePosition();
        angle = position.GetTheta();
        controlValue = turnPID.GetControlValue(angle);
        SetLeftDrive(controlValue);
        SetRightDrive(-controlValue);
    }
}

void Drive::SetLeftDrive(float power)
{
    DriveConfig::leftRearDriveMotor.move(power);
    DriveConfig::leftMiddleDriveMotor.move(power);
    DriveConfig::leftFrontDriveMotor.move(power);
}

void Drive::SetRightDrive(float power)
{
    DriveConfig::rightRearDriveMotor.move(power);
    DriveConfig::rightMiddleDriveMotor.move(power);
    DriveConfig::rightFrontDriveMotor.move(power);
}

void Drive::DriveToPoint(float targetX, float targetY, float power, bool reversed, PositionCalculation& position)
{
    // Set up the control variables
    PID distancePID(10.5, 0.5, 0.1, 0.0, -power, power, (power / 3.0), 0.0);
    PID anglePID(4.5, 0.2, 0.1, 0.0, -power, power, (power / 3.0), 0.0);
    position.UpdatePosition();
    float distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);
    distancePID.SetTargetValue(distance);
    anglePID.SetTargetValue(angle);
    float distanceControl = distancePID.GetControlValue(0.0);
    float angleControl = anglePID.GetControlValue(position.GetTheta());

    // Loop until the target is reached
    while(distance > 1.0)
    {
        position.UpdatePosition();
        distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
        angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);

        pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "Distance: %f", distance);
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Angle: %f", angle);

        distancePID.SetTargetValue(distance);
        anglePID.SetTargetValue(angle);
        distanceControl = distancePID.GetControlValue(0.0);
        angleControl = anglePID.GetControlValue(position.GetTheta());
        SetLeftDrive(distanceControl - angleControl);
        SetRightDrive(distanceControl + angleControl);
        pros::delay(2);
    }
}

void Drive::DriveThroughPoint(float targetX, float targetY, float power, bool reversed, PositionCalculation& position)
{
    // Set up the control variables
    PID anglePID(0.5, 0.0, 0.01, 0.0, -(power / 3.0), (power / 3.0), (power / 9.0), 0.0);
    position.UpdatePosition();
    float distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);

    // Loop until the target is reached
    while(distance > 0.1)
    {
        position.UpdatePosition();
        distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
        angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);
        // Control for forward motion
        if(!reversed)
        {
            anglePID.SetTargetValue(angle);
            SetLeftDrive(power + anglePID.GetControlValue(position.GetTheta()));
            SetRightDrive(power - anglePID.GetControlValue(position.GetTheta()));
        }
        // Control for backward motion
        else
        {
            angle = angle + 180.0;
            if(angle > 360.0)
                angle = angle - 360.0;
            anglePID.SetTargetValue(angle);
            SetLeftDrive(-power + anglePID.GetControlValue(position.GetTheta()));
            SetRightDrive(-power - anglePID.GetControlValue(position.GetTheta()));
        }
    }
}

void Drive::TurnToAngle(float angle, float power, PositionCalculation& position)
{
    PID turnPID(3.7, 0.05, 0.05, 0.0, -power, power, (power / 4.0), position.GetTheta());
    turnPID.SetTargetValue(angle);
    position.UpdatePosition();
    float controlValue = turnPID.GetControlValue(position.GetTheta());

    while(fabs(angle - position.GetTheta()) > 0.7 || controlValue > 1)
    {
        position.UpdatePosition();
        controlValue = turnPID.GetControlValue(position.GetTheta());
        SetLeftDrive(controlValue);
        SetRightDrive(-controlValue);
        pros::delay(2);
    }
    SetLeftDrive(0.0);
    SetRightDrive(0.0);
}

void Drive::TurnTowardsPoint(float targetX, float targetY, float power, PositionCalculation& position)
{
    PID turnPID(4.3, 0.05, 0.20, 0.0, -power, power, (power / 3.0), position.GetTheta());
    position.UpdatePosition();
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);
    turnPID.SetTargetValue(angle);
    float controlValue = turnPID.GetControlValue(position.GetTheta());

    while(fabs(angle - position.GetTheta()) > 0.1 || controlValue > 1)
    {
        position.UpdatePosition();
        controlValue = turnPID.GetControlValue(position.GetTheta());
        SetLeftDrive(controlValue);
        SetRightDrive(-controlValue);
    }
}