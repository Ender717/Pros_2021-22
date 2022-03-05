// Included libraries
#include "config/LiftConfig.h"

namespace LiftConfig
{
    // Constants
    const float BOTTOM_POSITION = -20.0;
    const float TOP_POSITION = 150.0;
    const float COUNTS_PER_DEGREE = 10.0;
    const float DEGREES_TO_RADIANS = 0.0174;

    // Ports
    const int LEFT_LIFT_1_PORT = 15;
    const int LEFT_LIFT_2_PORT = 16;
    const int RIGHT_LIFT_1_PORT = 7;
    const int RIGHT_LIFT_2_PORT = 8;

    // Motors
    pros::Motor leftLift1Motor(LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftLift2Motor(LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightLift1Motor(RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightLift2Motor(RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
}