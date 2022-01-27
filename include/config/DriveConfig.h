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
    // LEFT_REAR_DRIVE_PORT: The port the left rear drive motor is plugged into
    // LEFT_MIDDLE_DRIVE_PORT: The port the left middle drive motor is plugged into
    // LEFT_FRONT_DRIVE_PORT: The port the left front drive motor is plugged into
    // RIGHT_REAR_DRIVE_PORT: The port the right rear drive motor is plugged into
    // RIGHT_MIDDLE_DRIVE_PORT: The port the right middle drive motor is plugged into
    // RIGHT_FRONT_DRIVE_PORT: The port the right front drive motor is plugged into
    // LEFT_TRACKING_PORT: The port the left rotation sensor is plugged into
    // RIGHT_TRACKING_PORT: The port the right rotation sensor is plugged into
    // STRAFE_TRACKING_PORT: The port the strafe rotation sensor is plugged into
    // INERTIAL_PORT: The port the inertial sensor is plugged into
    //-------------------------------------------------------------------------
    extern const int LEFT_REAR_DRIVE_PORT;
    extern const int LEFT_MIDDLE_DRIVE_PORT;
    extern const int LEFT_FRONT_DRIVE_PORT;
    extern const int RIGHT_REAR_DRIVE_PORT;
    extern const int RIGHT_MIDDLE_DRIVE_PORT;
    extern const int RIGHT_FRONT_DRIVE_PORT;
    extern const int LEFT_TRACKING_PORT;
    extern const int RIGHT_TRACKING_PORT;
    extern const int STRAFE_TRACKING_PORT;

    //-------------------------------------------------------------------------
    // Drive Motors
    // leftRearDriveMotor: The motor positioned at the left rear of the drive
    // leftMiddleDriveMotor: The motor positioned at the left middle of the drive
    // leftFrontDriveMotor: The motor positioned at the left front of the drive
    // rightRearDriveMotor: The motor positioned at the right rear of the drive
    // rightMiddleDriveMotor: The motor positioned at the right center of the drive
    // rightRearDriveMotor: The motor positioned at the right front of the drive
    //-------------------------------------------------------------------------
    extern pros::Motor leftRearDriveMotor;
    extern pros::Motor leftMiddleDriveMotor;
    extern pros::Motor leftFrontDriveMotor;
    extern pros::Motor rightRearDriveMotor;
    extern pros::Motor rightMiddleDriveMotor;
    extern pros::Motor rightFrontDriveMotor;

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
};

#endif