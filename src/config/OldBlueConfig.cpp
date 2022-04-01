// Defined library
#include "config/OldBlueConfig.hpp"

namespace OldBlueConfig
{
    // Constants
    const double CARRIER_DOWN_POSITION = -3000.0;
    const double CARRIER_UP_POSITION = 0.0;
    const double CLAW_OPEN_POSITION = 515.0;
    const double CLAW_CLOSED_POSITION = 5.0;
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_LEFT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_RIGHT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_STRAFE_TRACKING_DISTANCE = 1.50;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -10.0;
    const double LIFT_TOP_POSITION = 110.0;
    const double LIFT_START_POSITION = 75.0;
    const double LIFT_COUNTS_PER_DEGREE = 25.0;

    // Motor ports
    const int CARRIER_1_PORT = 6;
    const int CARRIER_2_PORT = 16;
    const int CLAW_1_PORT = 18;
    const int LEFT_DRIVE_1_PORT = 11;
    const int LEFT_DRIVE_2_PORT = 12;
    const int LEFT_DRIVE_3_PORT = 13;
    const int RIGHT_DRIVE_1_PORT = 1;
    const int RIGHT_DRIVE_2_PORT = 2;
    const int RIGHT_DRIVE_3_PORT = 3;
    const int INTAKE_1_PORT = 8;
    const int LEFT_LIFT_1_PORT = 7;
    const int RIGHT_LIFT_1_PORT = 17;

    // Sensor ports
    const int LEFT_DRIVE_TRACKING_PORT = 14;
    const int RIGHT_DRIVE_TRACKING_PORT = 4;
    const int STRAFE_DRIVE_TRACKING_PORT = 5;

    // Motors
    pros::Motor carrier1Motor(CARRIER_1_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor carrier2Motor(CARRIER_2_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
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

    // Sensors
    pros::Rotation leftDriveTrackingSensor(LEFT_DRIVE_TRACKING_PORT);
    pros::Rotation rightDriveTrackingSensor(RIGHT_DRIVE_TRACKING_PORT);
    pros::Rotation strafeDriveTrackingSensor(STRAFE_DRIVE_TRACKING_PORT);
}