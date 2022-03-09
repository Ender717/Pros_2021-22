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
    // Constants:
    // DOWN_POSITION: The position of the carrier when it is down
    // UP_POSITION: The position of the carrier when it is up
    //-------------------------------------------------------------------------
    extern const float DOWN_POSITION;
    extern const float UP_POSITION;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_CARRIER_PORT: The port for the left carrier piston
    // RIGHT_CARRIER_PORT: The port for the right carrier piston
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