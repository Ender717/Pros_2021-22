// Inclusion guard
#ifndef CLAW_CONFIG_H
#define CLAW_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the claw subsystem members of the robot
// v1: Created the namespace - Nathan S, 1-31-22
//-----------------------------------------------------------------------------
namespace ClawConfig
{
    //-------------------------------------------------------------------------
    // Constants
    // OPEN_POSITION: The position of the claw when open
    // CLOSED_POSITION: The position of the claw when closed
    //-------------------------------------------------------------------------
    extern const float OPEN_POSITION;
    extern const float CLOSED_POSITION;

    //-------------------------------------------------------------------------
    // Ports
    // CLAW_PORT: The port the claw motor is in
    //-------------------------------------------------------------------------
    extern const int CLAW_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // clawMotor: The motor for the claw
    //-------------------------------------------------------------------------
    extern pros::Motor clawMotor;
}

#endif