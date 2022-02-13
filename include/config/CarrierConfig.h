// Inclusion guard
#ifndef CARRIER_CONFIG_H
#define CARRIER_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the carrier subsystem members of the robot
// v1: Created the namespace - Nathan S, 1-29-22
//-----------------------------------------------------------------------------
namespace CarrierConfig
{
    //-------------------------------------------------------------------------
    // Ports
    // LEFT_CARRIER_PORT: The port for the left carrier motor
    // RIGHT_CARRIER_PORT: The port for the right carrier motor
    //-------------------------------------------------------------------------
    extern const char LEFT_CARRIER_PORT;
    extern const char RIGHT_CARRIER_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // leftCarrierPiston: The piston on the left side of the carrier
    // rightCarrierPiston: The piston on the right side of the carrier
    //-------------------------------------------------------------------------
    extern pros::ADIDigitalOut leftCarrierPiston;
    extern pros::ADIDigitalOut rightCarrierPiston;
}

#endif