// Included libraries
#include "config/OrangeConfig.hpp"

namespace OrangeConfig
{
    // Constants
    const double CLAW_OPEN_POSITION = 515.0;
    const double CLAW_CLOSED_POSITION = 5.0;
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -8.5;
    const double LIFT_TOP_POSITION = 140.0;
    const double LIFT_START_POSITION = 130.0;
    const double LIFT_COUNTS_PER_DEGREE = 12.5;

    // Ports
    const int CLAW_1_PORT = -1;
    const int LEFT_DRIVE_1_PORT = 14;
    const int LEFT_DRIVE_2_PORT = 13;
    const int LEFT_DRIVE_3_PORT = 12;
    const int LEFT_DRIVE_4_PORT = 11;
    const int RIGHT_DRIVE_1_PORT = 6;
    const int RIGHT_DRIVE_2_PORT = 3;
    const int RIGHT_DRIVE_3_PORT = 2;
    const int RIGHT_DRIVE_4_PORT = 1;
    const int INTAKE_1_PORT = -1;
    const int LEFT_LIFT_1_PORT = 15;
    const int LEFT_LIFT_2_PORT = 16;
    const int RIGHT_LIFT_1_PORT = 7;
    const int RIGHT_LIFT_2_PORT = 8;
    
    // Sensor ports
    const int LEFT_DRIVE_TRACKING_PORT = -1;
    const int RIGHT_DRIVE_TRACKING_PORT = -1;
    const int STRAFE_DRIVE_TRACKING_PORT = -1;

    // 3-wire ports
    const char CARRIER_1_PORT = 'X';
    const char CARRIER_2_PORT = 'X';

    // Motors
    pros::Motor claw1Motor(CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
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
    pros::Motor intake1Motor(INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftLift1Motor(LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftLift2Motor(LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightLift1Motor(RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightLift2Motor(RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    pros::Rotation leftDriveTrackingSensor(LEFT_DRIVE_TRACKING_PORT);
    pros::Rotation rightDriveTrackingSensor(RIGHT_DRIVE_TRACKING_PORT);
    pros::Rotation strafeDriveTrackingSensor(STRAFE_DRIVE_TRACKING_PORT);

    // Pistons
    pros::ADIDigitalOut carrier1Piston(CARRIER_1_PORT);
    pros::ADIDigitalOut carrier2Piston(CARRIER_2_PORT);
}