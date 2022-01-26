// Included libraries
#include "config/DriveConfig.h"

namespace DriveConfig
{
    // Constants
    const float TRACKING_WHEEL_SIZE = 2.75;
    const float PI = 3.1415;
    const float COUNTS_PER_ROTATION = 36000.0;
    const float DEGREES_TO_RADIANS = 0.0174;
    const float INERTIAL_TUNING = 1.00696;

    // Ports
    const int LEFT_REAR_DRIVE_PORT = 13;
    const int LEFT_MIDDLE_DRIVE_PORT = 12;
    const int LEFT_FRONT_DRIVE_PORT = 11;
    const int RIGHT_REAR_DRIVE_PORT = 3;
    const int RIGHT_MIDDLE_DRIVE_PORT = 2;
    const int RIGHT_FRONT_DRIVE_PORT = 1;
    const int LEFT_TRACKING_PORT = 14;
    const int RIGHT_TRACKING_PORT = 4;
    const int STRAFE_TRACKING_PORT = 5;
    const int INERTIAL_PORT = 20;

    // Motors
    pros::Motor leftRearDriveMotor(LEFT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                   true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftMiddleDriveMotor(LEFT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                     false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftFrontDriveMotor(LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightRearDriveMotor(RIGHT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightMiddleDriveMotor(RIGHT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                      true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightFrontDriveMotor(RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                     false, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    pros::Rotation leftTrackingSensor(LEFT_TRACKING_PORT);
    pros::Rotation rightTrackingSensor(RIGHT_TRACKING_PORT);
    pros::Rotation strafeTrackingSensor(STRAFE_TRACKING_PORT);
    pros::Imu inertialSensor(INERTIAL_PORT);
}