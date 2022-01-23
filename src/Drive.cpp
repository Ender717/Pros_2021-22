// Included libraries
#include "Drive.h"

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