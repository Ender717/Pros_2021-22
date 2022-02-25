// Inclusion guard
#ifndef DRIVE_CONFIG_H
#define DRIVE_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the drive subsystem members of the robot
// v1: Created the class - Nathan S, 1-23-22
// v2: Split the class into a namespace and class - Nathan S, 1-24-22
//-----------------------------------------------------------------------------
namespace DriveConfig
{
    //-------------------------------------------------------------------------
    // Constants
    // TRACKING_WHEEL_SIZE: The diameter of the tracking wheels
    // PI: The mathematical value for pi
    // COUNTS_PER_ROTATION: The number of encoder counts in one rotation of a 
    //                      rotation sensor
    // DEGREES_TO_RADIANS: The number to multiply degrees by to get radians
    //-------------------------------------------------------------------------
    extern const float TRACKING_WHEEL_SIZE;
    extern const float PI;
    extern const float COUNTS_PER_ROTATION;
    extern const float DEGREES_TO_RADIANS;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_DRIVE_1_PORT: The port the first left drive motor is plugged into
    // LEFT_DRIVE_2_PORT: The port the second left drive motor is plugged into
    // LEFT_DRIVE_3_PORT: The port the third left drive motor is plugged into
    // LEFT_DRIVE_4_PORT: The port the fourth left drive motor is plugged into
    // RIGHT_DRIVE_1_PORT: The port the first right drive motor is plugged into
    // RIGHT_DRIVE_2_PORT: The port the second right drive motor is plugged into
    // RIGHT_DRIVE_3_PORT: The port the third right drive motor is plugged into
    // RIGHT_DRIVE_4_PORT: The port the fourth right drive motor is plugged into
    // LEFT_TRACKING_PORT: The port the left rotation sensor is plugged into
    // RIGHT_TRACKING_PORT: The port the right rotation sensor is plugged into
    // STRAFE_TRACKING_PORT: The port the strafe rotation sensor is plugged into
    // INERTIAL_PORT: The port the inertial sensor is plugged into
    //-------------------------------------------------------------------------
    extern const int LEFT_DRIVE_1_PORT;
    extern const int LEFT_DRIVE_2_PORT;
    extern const int LEFT_DRIVE_3_PORT;
    extern const int LEFT_DRIVE_4_PORT;
    extern const int RIGHT_DRIVE_1_PORT;
    extern const int RIGHT_DRIVE_2_PORT;
    extern const int RIGHT_DRIVE_3_PORT;
    extern const int RIGHT_DRIVE_4_PORT;
    extern const int LEFT_TRACKING_PORT;
    extern const int RIGHT_TRACKING_PORT;
    extern const int STRAFE_TRACKING_PORT;
    extern const int INERTIAL_PORT;

    //-------------------------------------------------------------------------
    // Drive Motors
    // leftDrive1Motor: The first left drive motor
    // leftDrive2Motor: The second left drive motor
    // leftDrive3Motor: The third left drive motor
    // leftDrive4Motor: The fourth left drive motor
    // rightDrive1Motor: The first right drive motor
    // rightDrive2Motor: The second right drive motor
    // rightDrive3Motor: The third right drive motor
    // rightDrive4Motor: The fourth right drive motor
    //-------------------------------------------------------------------------
    extern pros::Motor leftDrive1Motor;
    extern pros::Motor leftDrive2Motor;
    extern pros::Motor leftDrive3Motor;
    extern pros::Motor leftDrive4Motor;
    extern pros::Motor rightDrive1Motor;
    extern pros::Motor rightDrive2Motor;
    extern pros::Motor rightDrive3Motor;
    extern pros::Motor rightDrive4Motor;

    //-------------------------------------------------------------------------
    // Drive Sensors
    // leftTrackingSensor: The rotation sensor on the left side of the drive
    // rightTrackingSensor: The rotation sensor on the right side of the drive
    // strafeTrackingSensor: The rotation sensor on the strafe wheel of the drive
    // inertialSensor: The inertial sensor on the drive
    //-------------------------------------------------------------------------
    extern pros::Rotation leftTrackingSensor;
    extern pros::Rotation rightTrackingSensor;
    extern pros::Rotation strafeTrackingSensor;
    extern pros::Imu inertialSensor;
};

#endif