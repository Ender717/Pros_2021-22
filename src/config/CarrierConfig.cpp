// Included libraries
#include "config/CarrierConfig.h"

namespace CarrierConfig
{
    // Constants
    const float DOWN_POSITION = 36000.0;
    const float UP_POSITION = 0.0;

    // Ports
    const int LEFT_CARRIER_PORT = 16;
    const int RIGHT_CARRIER_PORT = 6;

    // Motors
    pros::Motor leftCarrierMotor(LEFT_CARRIER_PORT, pros::E_MOTOR_GEARSET_36,
                                 true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightCarrierMotor(RIGHT_CARRIER_PORT, pros::E_MOTOR_GEARSET_36,
                                  false, E_MOTOR_ENCODER_COUNTS);
}