// Inclusion guard
#ifndef ORANGE_CONFIG_H
#define ORANGE_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the configuration of the orange robot
// v1: Created the namespace - Nathan S, 3-9-22
//-----------------------------------------------------------------------------
namespace OldOrangeConfig
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
    const double CLAW_OPEN_POSITION = 515.0;
    const double CLAW_CLOSED_POSITION = 5.0;
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -10.0;
    const double LIFT_TOP_POSITION = 110.0;
    const double LIFT_START_POSITION = 75.0;
    const double LIFT_COUNTS_PER_DEGREE = 25.0;

    //-------------------------------------------------------------------------
    // Motor ports:
    // CLAW_1_PORT: The port the claw motor is plugged into
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
    const int CLAW_1_PORT = 7;
    const int LEFT_DRIVE_1_PORT = 11;
    const int LEFT_DRIVE_2_PORT = 12;
    const int LEFT_DRIVE_3_PORT = 13;
    const int RIGHT_DRIVE_1_PORT = 18;
    const int RIGHT_DRIVE_2_PORT = 19;
    const int RIGHT_DRIVE_3_PORT = 20;
    const int INTAKE_1_PORT = 8;
    const int LEFT_LIFT_1_PORT = 9;
    const int RIGHT_LIFT_1_PORT = 6;
    
    //-------------------------------------------------------------------------
    // Sensor ports:
    // LEFT_DRIVE_TRACKING_PORT: The port the left rotation sensor is plugged into
    // RIGHT_DRIVE_TRACKING_PORT: The port the right rotation sensor is plugged into
    // STRAFE_DRIVE_TRACKING_PORT: The port the strafe rotation sensor is plugged into
    //-------------------------------------------------------------------------
    const int LEFT_DRIVE_TRACKING_PORT = 14;
    const int RIGHT_DRIVE_TRACKING_PORT = 17;
    const int STRAFE_DRIVE_TRACKING_PORT = 16;

    //-------------------------------------------------------------------------
    // 3-wire ports:
    // CARRIER_1_PORT: The port for the first carrier piston
    // CARRIER_2_PORT: The port for the second carrier piston
    //-------------------------------------------------------------------------
    const char CARRIER_1_PORT = 'A';
    const char CARRIER_2_PORT = 'B';

    //-------------------------------------------------------------------------
    // Motors:
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
    pros::Motor claw1Motor(CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive1Motor(LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive2Motor(LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftDrive3Motor(LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06,
                                true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive1Motor(RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                 false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive2Motor(RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                 true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightDrive3Motor(RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06,
                                 false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor intake1Motor(INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftLift1Motor(LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightLift1Motor(RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);

    //-------------------------------------------------------------------------
    // Sensors:
    // leftDriveTrackingSensor: The rotation sensor on the left side of the drive
    // rightDriveTrackingSensor: The rotation sensor on the right side of the drive
    // strafeDriveTrackingSensor: The rotation sensor on the strafe wheel of the drive
    //-------------------------------------------------------------------------
    pros::Rotation leftDriveTrackingSensor(LEFT_DRIVE_TRACKING_PORT);
    pros::Rotation rightDriveTrackingSensor(RIGHT_DRIVE_TRACKING_PORT);
    pros::Rotation strafeDriveTrackingSensor(STRAFE_DRIVE_TRACKING_PORT);

    //-------------------------------------------------------------------------
    // Pistons:
    // carrier1Piston: The first carrier piston
    // carrier2Piston: The second carrier piston
    //-------------------------------------------------------------------------
    pros::ADIDigitalOut carrier1Piston(CARRIER_1_PORT);
    pros::ADIDigitalOut carrier2Piston(CARRIER_2_PORT);
}

#endif