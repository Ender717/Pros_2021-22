// Inclusion guard
#ifndef OLD_CONFIG_H
#define OLD_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the configuration of the old robot
// v1: Created the namespace - Nathan S, 3-9-22
//-----------------------------------------------------------------------------
namespace OldConfig
{
    //-------------------------------------------------------------------------
    // Constants:
    // OPEN_POSITION: The position of the claw when open
    // CLOSED_POSITION: The position of the claw when closed
    // DRIVE_TRACKING_WHEEL_SIZE: The diameter of the tracking wheels on the drive
    // DRIVE_COUNTS_PER_ROTATION: The number of encoder counts in one rotation 
    //                            of a rotation sensor
    // LIFT_BOTTOM_POSITION: The minimum angle of the lift
    // LIFT_TOP_POSITION: The maximum angle of the lift
    // LIFT_START_POSITION: The starting angle of the lift
    // LIFT_COUNTS_PER_DEGREE: The number of encoder counts the lift moves per 
    //                         degree of rotation it experiences
    //-------------------------------------------------------------------------
    extern const float CARRIER_DOWN_POSITION;
    extern const float CARRIER_UP_POSITION;
    extern const float CLAW_OPEN_POSITION;
    extern const float CLAW_CLOSED_POSITION;
    extern const float DRIVE_TRACKING_WHEEL_SIZE;
    extern const float DRIVE_COUNTS_PER_ROTATION;
    extern const float LIFT_BOTTOM_POSITION;
    extern const float LIFT_TOP_POSITION;
    extern const float LIFT_START_POSITION;
    extern const float LIFT_COUNTS_PER_DEGREE;

    //-------------------------------------------------------------------------
    // Motor ports:
    // CARRIER_1_PORT: The port for the first carrier motor
    // CARRIER_2_PORT: The port for the second carrier motor
    // CLAW_1_PORT: The port the claw motor is plugged into
    // LEFT_DRIVE_1_PORT: The port the first left drive motor is plugged into
    // LEFT_DRIVE_2_PORT: The port the second left drive motor is plugged into
    // LEFT_DRIVE_3_PORT: The port the third left drive motor is plugged into
    // RIGHT_DRIVE_1_PORT: The port the first right drive motor is plugged into
    // RIGHT_DRIVE_2_PORT: The port the second right drive motor is plugged into
    // RIGHT_DRIVE_3_PORT: The port the third right drive motor is plugged into
    // INTAKE_1_PORT: The port the intake motor is plugged into
    // LEFT_LIFT_1_PORT: The port the first left lift motor is plugged into
    // LEFT_LIFT_2_PORT: The port the second left lift motor is plugged into
    // RIGHT_LIFT_1_PORT: The port the first right lift motor is plugged into
    // RIGHT_LIFT_2_PORT: The port the second right lift motor is plugged into
    //-------------------------------------------------------------------------
    extern const int CARRIER_1_PORT;
    extern const int CARRIER_2_PORT;
    extern const int CLAW_1_PORT;
    extern const int LEFT_DRIVE_1_PORT;
    extern const int LEFT_DRIVE_2_PORT;
    extern const int LEFT_DRIVE_3_PORT;
    extern const int RIGHT_DRIVE_1_PORT;
    extern const int RIGHT_DRIVE_2_PORT;
    extern const int RIGHT_DRIVE_3_PORT;
    extern const int INTAKE_1_PORT;
    extern const int LEFT_LIFT_1_PORT;
    extern const int RIGHT_LIFT_1_PORT;
    
    //-------------------------------------------------------------------------
    // Sensor ports:
    // LEFT_DRIVE_TRACKING_PORT: The port the left rotation sensor is plugged into
    // RIGHT_DRIVE_TRACKING_PORT: The port the right rotation sensor is plugged into
    // STRAFE_DRIVE_TRACKING_PORT: The port the strafe rotation sensor is plugged into
    //-------------------------------------------------------------------------
    extern const int LEFT_DRIVE_TRACKING_PORT;
    extern const int RIGHT_DRIVE_TRACKING_PORT;
    extern const int STRAFE_DRIVE_TRACKING_PORT;

    //-------------------------------------------------------------------------
    // Motors:
    // carrier1Motor: The first motor for the carrier
    // carrier2Motor: The second motor for the carrier
    // claw1Motor: The first motor for the claw
    // leftDrive1Motor: The first left drive motor
    // leftDrive2Motor: The second left drive motor
    // leftDrive3Motor: The third left drive motor
    // rightDrive1Motor: The first right drive motor
    // rightDrive2Motor: The second right drive motor
    // rightDrive3Motor: The third right drive motor
    // intake1Motor: The first motor for the intake
    // leftLift1Motor: The first motor on the left side of the lift
    // rightLift1Motor: The first motor on the right side of the lift
    //-------------------------------------------------------------------------
    extern pros::Motor carrier1Motor;
    extern pros::Motor carrier2Motor;
    extern pros::Motor claw1Motor;
    extern pros::Motor leftDrive1Motor;
    extern pros::Motor leftDrive2Motor;
    extern pros::Motor leftDrive3Motor;
    extern pros::Motor rightDrive1Motor;
    extern pros::Motor rightDrive2Motor;
    extern pros::Motor rightDrive3Motor;
    extern pros::Motor intake1Motor;
    extern pros::Motor leftLift1Motor;
    extern pros::Motor rightLift1Motor;

    //-------------------------------------------------------------------------
    // Sensors:
    // leftDriveTrackingSensor: The rotation sensor on the left side of the drive
    // rightDriveTrackingSensor: The rotation sensor on the right side of the drive
    // strafeDriveTrackingSensor: The rotation sensor on the strafe wheel of the drive
    //-------------------------------------------------------------------------
    extern pros::Rotation leftDriveTrackingSensor;
    extern pros::Rotation rightDriveTrackingSensor;
    extern pros::Rotation strafeDriveTrackingSensor;
}

#endif