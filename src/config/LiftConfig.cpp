// Included libraries
#include "config/LiftConfig.h"

namespace LiftConfig
{
    // Constants
    const float BOTTOM_POSITION = -2490.0;
    const float TOP_POSITION = 960.0;
    const float COUNTS_PER_DEGREE = 25.0;
    const float DEGREES_TO_RADIANS = 0.0174;

    // Ports
    const int LEFT_LIFT_PORT = 9;
    const int RIGHT_LIFT_PORT = 10;

    // Motors
    pros::Motor leftLiftMotor(LEFT_LIFT_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightLiftMotor(RIGHT_LIFT_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
}