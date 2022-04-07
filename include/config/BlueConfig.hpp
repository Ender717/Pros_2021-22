// Inclusion guard
#ifndef BLUE_CONFIG_HPP
#define BLUE_CONFIG_HPP

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the configuration of the blue robot
// v1: Created the namespace - Nathan S, 3-9-22
//-----------------------------------------------------------------------------
namespace BlueConfig
{
    //-------------------------------------------------------------------------
    // Constants:
    // DRIVE_TRACKING_WHEEL_SIZE: The diameter of the tracking wheels on the drive
    // DRIVE_LEFT_TRACKING_DISTANCE: The left tracking wheel offset
    // DRIVE_RIGHT_TRACKING_DISTANCE: The right tracking wheel offset
    // DRIVE_STRAFE_TRACKING_DISTANCE: The strafe tracking wheel offset
    // DRIVE_COUNTS_PER_ROTATION: The number of encoder counts in one rotation 
    //                            of a rotation sensor
    // LIFT_BOTTOM_POSITION: The minimum angle of the lift
    // LIFT_TOP_POSITION: The maximum angle of the lift
    // LIFT_START_POSITION: The starting angle of the lift
    // LIFT_COUNTS_PER_DEGREE: The number of encoder counts the lift moves per 
    //                         degree of rotation it experiences
    //-------------------------------------------------------------------------
    extern const double DRIVE_TRACKING_WHEEL_SIZE;
    extern const double DRIVE_LEFT_TRACKING_DISTANCE;
    extern const double DRIVE_RIGHT_TRACKING_DISTANCE;
    extern const double DRIVE_STRAFE_TRACKING_DISTANCE;
    extern const double DRIVE_COUNTS_PER_ROTATION;
    extern const double LIFT_BOTTOM_POSITION;
    extern const double LIFT_TOP_POSITION;
    extern const double LIFT_START_POSITION;
    extern const double LIFT_COUNTS_PER_DEGREE;

    //-------------------------------------------------------------------------
    // Motor ports:
    // LEFT_DRIVE_1_PORT: The port the first left drive motor is plugged into
    // LEFT_DRIVE_2_PORT: The port the second left drive motor is plugged into
    // LEFT_DRIVE_3_PORT: The port the third left drive motor is plugged into
    // LEFT_DRIVE_4_PORT: The port the fourth left drive motor is plugged into
    // RIGHT_DRIVE_1_PORT: The port the first right drive motor is plugged into
    // RIGHT_DRIVE_2_PORT: The port the second right drive motor is plugged into
    // RIGHT_DRIVE_3_PORT: The port the third right drive motor is plugged into
    // RIGHT_DRIVE_4_PORT: The port the fourth right drive motor is plugged into
    // INTAKE_1_PORT: The port the intake motor is plugged into
    // LEFT_LIFT_1_PORT: The port the first left lift motor is plugged into
    // LEFT_LIFT_2_PORT: The port the second left lift motor is plugged into
    // RIGHT_LIFT_1_PORT: The port the first right lift motor is plugged into
    // RIGHT_LIFT_2_PORT: The port the second right lift motor is plugged into
    //-------------------------------------------------------------------------
    extern const int LEFT_DRIVE_1_PORT;
    extern const int LEFT_DRIVE_2_PORT;
    extern const int LEFT_DRIVE_3_PORT;
    extern const int LEFT_DRIVE_4_PORT;
    extern const int RIGHT_DRIVE_1_PORT;
    extern const int RIGHT_DRIVE_2_PORT;
    extern const int RIGHT_DRIVE_3_PORT;
    extern const int RIGHT_DRIVE_4_PORT;
    extern const int INTAKE_1_PORT;
    extern const int LEFT_LIFT_1_PORT;
    extern const int LEFT_LIFT_2_PORT;
    extern const int RIGHT_LIFT_1_PORT;
    extern const int RIGHT_LIFT_2_PORT;
    
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
    // 3-wire ports:
    // CARRIER_1_PORT: The port for the first carrier piston
    // CLAW_1_PORT: The port for the first claw piston
    //-------------------------------------------------------------------------
    extern const char CARRIER_1_PORT;
    extern const char CLAW_1_PORT;

    /*

    //-------------------------------------------------------------------------
    // Motors:
    // claw1Motor: The first motor for the claw
    // leftDrive1Motor: The first left drive motor
    // leftDrive2Motor: The second left drive motor
    // leftDrive3Motor: The third left drive motor
    // leftDrive4Motor: The fourth left drive motor
    // rightDrive1Motor: The first right drive motor
    // rightDrive2Motor: The second right drive motor
    // rightDrive3Motor: The third right drive motor
    // rightDrive4Motor: The fourth right drive motor
    // intake1Motor: The first motor for the intake
    // leftLift1Motor: The first motor on the left side of the lift
    // leftLift2Motor: The second motor on the left side of the lift
    // rightLift1Motor: The first motor on the right side of the lift
    // rightLift2Motor: The second motor on the right side of the lift
    //-------------------------------------------------------------------------
    extern pros::Motor claw1Motor;
    extern pros::Motor leftDrive1Motor;
    extern pros::Motor leftDrive2Motor;
    extern pros::Motor leftDrive3Motor;
    extern pros::Motor leftDrive4Motor;
    extern pros::Motor rightDrive1Motor;
    extern pros::Motor rightDrive2Motor;
    extern pros::Motor rightDrive3Motor;
    extern pros::Motor rightDrive4Motor;
    extern pros::Motor intake1Motor;
    extern pros::Motor leftLift1Motor;
    extern pros::Motor leftLift2Motor;
    extern pros::Motor rightLift1Motor;
    extern pros::Motor rightLift2Motor;

    //-------------------------------------------------------------------------
    // Sensors:
    // leftDriveTrackingSensor: The rotation sensor on the left side of the drive
    // rightDriveTrackingSensor: The rotation sensor on the right side of the drive
    // strafeDriveTrackingSensor: The rotation sensor on the strafe wheel of the drive
    //-------------------------------------------------------------------------
    extern pros::Rotation leftDriveTrackingSensor;
    extern pros::Rotation rightDriveTrackingSensor;
    extern pros::Rotation strafeDriveTrackingSensor;

    //-------------------------------------------------------------------------
    // Pistons:
    // carrier1Piston: The first carrier piston
    // carrier2Piston: The second carrier piston
    //-------------------------------------------------------------------------
    extern pros::ADIDigitalOut carrier1Piston;
    extern pros::ADIDigitalOut carrier2Piston;

    */
}

#endif