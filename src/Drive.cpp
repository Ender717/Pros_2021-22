// Included libraries
#include "Drive.h"

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

// Constructor definitions ----------------------------------------------------
Drive::Drive()
{
    // Motors
    leftRearDriveMotor = new pros::Motor(LEFT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                   true, E_MOTOR_ENCODER_COUNTS);
    leftMiddleDriveMotor = new pros::Motor(LEFT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                     false, E_MOTOR_ENCODER_COUNTS);
    leftFrontDriveMotor = new pros::Motor(LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    true, E_MOTOR_ENCODER_COUNTS);
    rightRearDriveMotor = new pros::Motor(RIGHT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    false, E_MOTOR_ENCODER_COUNTS);
    rightMiddleDriveMotor = new pros::Motor(RIGHT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                      true, E_MOTOR_ENCODER_COUNTS);
    rightFrontDriveMotor = new pros::Motor(RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                     false, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    leftTrackingSensor = new pros::Rotation(LEFT_TRACKING_PORT);
    rightTrackingSensor = new pros::Rotation(RIGHT_TRACKING_PORT);
    strafeTrackingSensor = new pros::Rotation(STRAFE_TRACKING_PORT);
    inertialSensor = new pros::Imu(INERTIAL_PORT);

    // Processes
    positionTracking = new PositionCalculation(0.0, 0.0, 0.0); // THIS IS SET IN AUTON
    distancePID = new PID(10.0, 10.0, 10.0, -125.0, 125.0, 40.0, 0.0);
    anglePID = new PID(2.0, 2.0, 2.0, -50.0, 50.0, 10.0, 0.0);
    turnPID = new PID(10.0, 10.0, 10.0, -125.0, 125.0, 50.0, 0.0);
}

void Drive::Initialize()
{
    inertialSensor->reset();
    while (inertialSensor->is_calibrating()) 
    {
        pros::delay(2);
    }
    leftTrackingSensor->set_position(0.0);
	rightTrackingSensor->set_position(0.0);
	strafeTrackingSensor->set_position(0.0);
}

// Public method definitions --------------------------------------------------
void Drive::DriveStraight(float inches, bool reversed)
{
    // Confirm that the position tracking is running
    if (positionTracking != nullptr)
    {
        // Set the PID controllers for the desired motion
        UpdatePosition();
        distancePID->SetTargetValue(inches);
        anglePID->SetTargetValue(positionTracking->GetAngle());
        float startingPosition = leftTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION;

        // Run the loop until the PID controller is done
        while(fabs(distancePID->GetControlValue(leftTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION - startingPosition)) > 0.0)
        {
            UpdatePosition();
            // Run the control for forward movement
            if(!reversed)
            {
                SetLeftDrive(distancePID->GetControlValue(leftTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION - startingPosition) 
                             + anglePID->GetControlValue(positionTracking->GetAngle()));
                SetRightDrive(distancePID->GetControlValue(leftTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION - startingPosition) 
                              - anglePID->GetControlValue(positionTracking->GetAngle()));
            }
            // Run the control for backward movement
            else
            {
                SetLeftDrive(-distancePID->GetControlValue(startingPosition - leftTrackingSensor->get_position()) - 
                             anglePID->GetControlValue(startingPosition - positionTracking->GetAngle()));
                SetRightDrive(-distancePID->GetControlValue(leftTrackingSensor->get_position()) + 
                             anglePID->GetControlValue(positionTracking->GetAngle()));
            }
        }
    }
}

void Drive::SpinTurn(float degrees)
{
    // Set the PID controller for the motion
    UpdatePosition();
    turnPID->SetTargetValue(positionTracking->GetAngle());

    // Run the control loop
    while(fabs(turnPID->GetControlValue(positionTracking->GetAngle())) > 0.0)
    {
        UpdatePosition();
        SetLeftDrive(turnPID->GetControlValue(positionTracking->GetAngle()));
        SetRightDrive(-turnPID->GetControlValue(positionTracking->GetAngle()));
    }
}

void Drive::SetLeftDrive(float power)
{
    leftRearDriveMotor->move(power);
    leftMiddleDriveMotor->move(power);
    leftFrontDriveMotor->move(power);
}

void Drive::SetRightDrive(float power)
{
    rightRearDriveMotor->move(power);
    rightMiddleDriveMotor->move(power);
    rightFrontDriveMotor->move(power);
}

void Drive::DriveToPoint(float targetX, float targetY, bool reversed)
{
    // Set up the control variables
    UpdatePosition();
    float distance = CalculateDistance(positionTracking->GetX(), positionTracking->GetY(), targetX, targetY);
    float angle = CalculateAngle(positionTracking->GetX(), positionTracking->GetY(), targetX, targetY);

    // Loop until the target is reached
    while(distance > 0.0)
    {
        // Control for forward motion
        if(!reversed)
        {
            distancePID->SetTargetValue(distance);
            anglePID->SetTargetValue(angle);
            SetLeftDrive(distancePID->GetControlValue(0.0) + anglePID->GetControlValue(positionTracking->GetAngle()));
            SetRightDrive(distancePID->GetControlValue(0.0) - anglePID->GetControlValue(positionTracking->GetAngle()));
        }
        // Control for backward motion
        else
        {
            angle = angle + 180.0;
            if(angle > 360.0)
                angle = angle - 360.0;
            distancePID->SetTargetValue(-distance);
            anglePID->SetTargetValue(angle);
            SetLeftDrive(distancePID->GetControlValue(0.0) - anglePID->GetControlValue(positionTracking->GetAngle()));
            SetRightDrive(distancePID->GetControlValue(0.0) + anglePID->GetControlValue(positionTracking->GetAngle()));
        }
    }
}

void Drive::DriveThroughPoint(float targetX, float targetY, float power, bool reversed)
{
    // Set up the control variables
    UpdatePosition();
    float distance = CalculateDistance(positionTracking->GetX(), positionTracking->GetY(), targetX, targetY);
    float angle = CalculateAngle(positionTracking->GetX(), positionTracking->GetY(), targetX, targetY);

    // Loop until the target is reached
    while(distance > 0.0)
    {
        // Control for forward motion
        if(!reversed)
        {
            anglePID->SetTargetValue(angle);
            SetLeftDrive(power + anglePID->GetControlValue(positionTracking->GetAngle()));
            SetRightDrive(power - anglePID->GetControlValue(positionTracking->GetAngle()));
        }
        // Control for backward motion
        else
        {
            angle = angle + 180.0;
            if(angle > 360.0)
                angle = angle - 360.0;
            anglePID->SetTargetValue(angle);
            SetLeftDrive(-power + anglePID->GetControlValue(positionTracking->GetAngle()));
            SetRightDrive(-power - anglePID->GetControlValue(positionTracking->GetAngle()));
        }
    }
}

float Drive::GetX()
{
    return positionTracking->GetX();
}

float Drive::GetY()
{
    return positionTracking->GetY();
}

float Drive::GetTheta()
{
    return positionTracking->GetAngle() / DEGREES_TO_RADIANS;
}

void Drive::UpdatePosition()
{
    positionTracking->UpdatePosition(leftTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION,
                                     rightTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / -COUNTS_PER_ROTATION,
                                     strafeTrackingSensor->get_position() * TRACKING_WHEEL_SIZE * PI / -COUNTS_PER_ROTATION, 
                                     inertialSensor->get_rotation() * DEGREES_TO_RADIANS * INERTIAL_TUNING);
}

void Drive::SetPosition(float x, float y, float theta)
{
    positionTracking->SetPosition(x, y, theta);
}