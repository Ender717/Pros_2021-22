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
    // Constants
    // DOWN_POSITION: The encoder position when the carrier is down
    // UP_POSITION: The encoder position when the carrier is up
    //-------------------------------------------------------------------------
    extern const float DOWN_POSITION;
    extern const float UP_POSITION;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_CARRIER_PORT: The port for the left carrier motor
    // RIGHT_CARRIER_PORT: The port for the right carrier motor
    //-------------------------------------------------------------------------
    extern const int LEFT_CARRIER_PORT;
    extern const int RIGHT_CARRIER_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // leftCarrierMotor: The motor on the left side of the carrier
    // rightCarrierMotor: The motor on the right side of the carrier
    //-------------------------------------------------------------------------
    extern pros::Motor leftCarrierMotor;
    extern pros::Motor rightCarrierMotor;
}

#endif