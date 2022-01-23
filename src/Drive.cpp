// Included libraries
#include "Drive.h"

// Private method definitions -------------------------------------------------
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
    positionTracking = nullptr; // THIS IS SET IN AUTON
    distancePID = new PID(10.0, 10.0, 10.0, -125.0, 125.0, 40.0, 0.0);
    anglePID = new PID(10.0, 10.0, 10.0, -50.0, 50.0, 10.0, 0.0);
    turnPID = new PID(10.0, 10.0, 10.0, -125.0, 125.0, 50.0, 0.0);
}

// Public method definitions --------------------------------------------------
void Drive::DriveStraight(float inches, bool reversed)
{
    // Confirm that the position tracking is running
    if (positionTracking != nullptr)
    {
        // Set the PID controllers for the desired motion
        distancePID->setTarget(inches);
        distancePID->UpdateController();
        anglePID->setTarget(positionTracking->GetAngle());
        anglePID->UpdateController();
        float startingPosition = leftTrackingSensor->get();

        // Run the loop until the PID controller is done
        while(fabs(distancePID->GetControlValue()) > 0.0)
        {
            // Run the control for forward movement
            if(!reversed)
            {
                SetLeftDrive(distancePID->GetControlValue(leftTrackingSensor->get() - startingPosition) 
                             + anglePID->GetControlValue(positionTracking->GetAngle()));
                SetRightDrive(distancePID->GetControlValue(leftTrackingSensor->get() - startingPosition) 
                              - anglePID->GetControlValue(positionTracking->GetAngle()));
            }
            // Run the control for backward movement
            else
            {
                SetLeftDrive(-distancePID->GetControlValue(startingPosition - leftTrackingSensor->get()) - 
                             anglePID->GetControlValue(startingPosition - positionTracking->GetAngle()));
                SetRightDrive(-distancePID->GetControlValue(leftTrackingSensor->get()) + 
                             anglePID->GetControlValue(positionTracking->GetAngle()));
            }
        }
    }
}