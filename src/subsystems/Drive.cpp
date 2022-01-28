// Included libraries
#include "subsystems/Drive.h"

// Private method definitions -------------------------------------------------
float Drive::CalculateAngle(float startX, float startY, float endX, float endY)
{
    float angle;
    // Run the normal calculation if the values are not equal
    if(startX != endX && startY != endY)
    {
        angle = atan2f(fabs(endY - startY), fabs(endX - startX));

        // Place the angle in the correct quadrant
        if(endX < startX && endY > startY)
            angle = 180.0 - angle;
        else if (endX < startX && endY < startY)
            angle += 180.0;
        else if (endX > startX && endY < startY)
            angle = 360.0 - angle;
    }
    // Find the angle if both points lie on the same y-axis
    else if (startX == endX)
    {
        if(endY > startY)
            angle = 90.0;
        else
            angle = 270.0;
    }
    // Find the angle if both points lie on the same x-axis
    else
    {
        if(endX > startX)
            angle = 0.0;
        else
            angle = 180.0;
    }

    // return the result
    return angle;
}

float Drive::CalculateDistance(float startX, float startY, float endX, float endY)
{
    return sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));
}

// Constructor definitions ------------------------------------------------
Drive::Drive() {}

// Public method definitions ----------------------------------------------
void Drive::Initialize()
{
    DriveConfig::leftTrackingSensor.set_position(0.0);
    DriveConfig::rightTrackingSensor.set_position(0.0);
    DriveConfig::strafeTrackingSensor.set_position(0.0);
}

// Public method definitions --------------------------------------------------
void Drive::DriveStraight(float inches, PositionCalculation& position)
{
    PID distancePID(5.5, 0.1, 0.3, 0.0, -125.0, 125.0, 40.0, 0.0);
    float startValue = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    distancePID.SetTargetValue(inches + startValue);
    float distance = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
    float controlValue = distancePID.GetControlValue(distance);

    while(abs(inches + startValue - distance) > 0.1 || controlValue > 1)
    {
        distance = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
        controlValue = distancePID.GetControlValue(distance);
        SetLeftDrive(controlValue);
        SetRightDrive(controlValue);
    }
}

void Drive::SpinTurn(float degrees, PositionCalculation& position)
{
    PID turnPID(4.3, 0.05, 0.20, 0.0, -125.0, 125.0, 40.0, 0.0);
    position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    float targetAngle = position.GetTheta() + degrees;
    turnPID.SetTargetValue(targetAngle);
    float angle = position.GetTheta();
    float controlValue = turnPID.GetControlValue(angle);

    while(abs(targetAngle - angle) > 0.1 || controlValue > 1)
    {
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
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
    PID distancePID(5.5, 0.1, 0.3, 0.0, -power, power, (power / 3.0), 0.0);
    PID anglePID(0.5, 0.0, 0.01, 0.0, -(power / 3.0), (power / 3.0), (power / 9.0), 0.0);
    position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    float distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);

    // Loop until the target is reached
    while(distance > 0.1)
    {
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
        distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
        angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);
        // Control for forward motion
        if(!reversed)
        {
            distancePID.SetTargetValue(distance);
            anglePID.SetTargetValue(angle);
            SetLeftDrive(distancePID.GetControlValue(0.0) + anglePID.GetControlValue(position.GetTheta()));
            SetRightDrive(distancePID.GetControlValue(0.0) - anglePID.GetControlValue(position.GetTheta()));
        }
        // Control for backward motion
        else
        {
            angle = angle + 180.0;
            if(angle > 360.0)
                angle = angle - 360.0;
            distancePID.SetTargetValue(-distance);
            anglePID.SetTargetValue(angle);
            SetLeftDrive(distancePID.GetControlValue(0.0) - anglePID.GetControlValue(position.GetTheta()));
            SetRightDrive(distancePID.GetControlValue(0.0) + anglePID.GetControlValue(position.GetTheta()));
        }
    }
}

void Drive::DriveThroughPoint(float targetX, float targetY, float power, bool reversed, PositionCalculation& position)
{
    // Set up the control variables
    PID anglePID(0.5, 0.0, 0.01, 0.0, -(power / 3.0), (power / 3.0), (power / 9.0), 0.0);
    position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    float distance = CalculateDistance(position.GetX(), position.GetY(), targetX, targetY);
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);

    // Loop until the target is reached
    while(distance > 0.1)
    {
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
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
    PID turnPID(4.3, 0.05, 0.20, 0.0, -power, power, (power / 3.0), position.GetTheta());
    turnPID.SetTargetValue(angle);
    position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    float controlValue = turnPID.GetControlValue(position.GetTheta());

    while(fabs(angle - position.GetTheta()) > 0.1 || controlValue > 1)
    {
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
        controlValue = turnPID.GetControlValue(position.GetTheta());
        SetLeftDrive(controlValue);
        SetRightDrive(-controlValue);
    }
}

void Drive::TurnTowardsPoint(float targetX, float targetY, float power, PositionCalculation& position)
{
    PID turnPID(4.3, 0.05, 0.20, 0.0, -power, power, (power / 3.0), position.GetTheta());
    position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    float angle = CalculateAngle(position.GetX(), position.GetY(), targetX, targetY);
    turnPID.SetTargetValue(angle);
    float controlValue = turnPID.GetControlValue(position.GetTheta());

    while(fabs(angle - position.GetTheta()) > 0.1 || controlValue > 1)
    {
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                            DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
        controlValue = turnPID.GetControlValue(position.GetTheta());
        SetLeftDrive(controlValue);
        SetRightDrive(-controlValue);
    }
}