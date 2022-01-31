// Included libraries
#include "config/LiftConfig.h"

namespace LiftConfig
{
    // Constants
    const float BOTTOM_POSITION = 0.0;
    const float MIDDLE_POSITION = 23000.0;
    const float TOP_POSITION = 50000.0;
    const float ARM_LENGTH = 13.0;
    const float COUNTS_PER_ROTATION = 252000.0;
    const float DEGREES_TO_RADIANS = 0.0174;

    // Ports
    const int LEFT_LIFT_PORT = 17;
    const int RIGHT_LIFT_PORT = 7;

    // Motors
    pros::Motor leftLiftMotor(17, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightLiftMotor(7, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
}