// Included libraries
#include "config/CarrierConfig.h"

namespace CarrierConfig
{
    // Constants
    const float DOWN_POSITION = 0.0;
    const float UP_POSITION = 500.0;
    
    // Ports
    const char LEFT_CARRIER_PORT = 'A';
    const char RIGHT_CARRIER_PORT = 'B';

    // Motors
    pros::ADIDigitalOut leftCarrierPiston(LEFT_CARRIER_PORT);
    pros::ADIDigitalOut rightCarrierPiston(RIGHT_CARRIER_PORT);
}