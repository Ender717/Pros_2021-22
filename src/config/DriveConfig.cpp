// Included libraries
#include "config/DriveConfig.h"

namespace DriveConfig
{
    // Constants
    const float TRACKING_WHEEL_SIZE = 2.75;
    const float PI = 3.1415;
    const float COUNTS_PER_ROTATION = 36000.0;
    const float DEGREES_TO_RADIANS = 0.0174;

    // Ports
    const int LEFT_DRIVE_1_PORT = 14;
    const int LEFT_DRIVE_2_PORT = 13;
    const int LEFT_DRIVE_3_PORT = 12;
    const int LEFT_DRIVE_4_PORT = 11;
    const int RIGHT_DRIVE_1_PORT = 6;
    const int RIGHT_DRIVE_2_PORT = 3;
    const int RIGHT_DRIVE_3_PORT = 2;
    const int RIGHT_DRIVE_4_PORT = 1;
    const int LEFT_TRACKING_PORT = 20;
    const int RIGHT_TRACKING_PORT = 20;
    const int STRAFE_TRACKING_PORT = 20;
    const int INERTIAL_PORT = 20;

    // Motors
    pros::Motor leftDrive1Motor(LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive2Motor(LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive3Motor(LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06,
                                true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive4Motor(LEFT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive1Motor(RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                 false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive2Motor(RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                 true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive3Motor(RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06,
                                 false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive4Motor(RIGHT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                                 true, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    pros::Rotation leftTrackingSensor(LEFT_TRACKING_PORT);
    pros::Rotation rightTrackingSensor(RIGHT_TRACKING_PORT);
    pros::Rotation strafeTrackingSensor(STRAFE_TRACKING_PORT);
    pros::Imu inertialSensor(INERTIAL_PORT);
}