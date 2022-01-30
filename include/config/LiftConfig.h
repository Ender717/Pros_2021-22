// Inclusion guard
#ifndef LIFT_CONFIG_H
#define LIFT_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the lift subsystem members of the robot
// v1: Created the namespace - Nathan S, 1-30-22
//-----------------------------------------------------------------------------
namespace LiftConfig
{
    //-------------------------------------------------------------------------
    // Constants
    // BOTTOM_POSITION: The encoder position when the lift is at the ground
    // TOP_POSITION: The encoder position when the lift is at the top
    //-------------------------------------------------------------------------
    extern const float BOTTOM_POSITION;
    extern const float TOP_POSITION;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_LIFT_PORT: The port for the left lift motor
    // RIGHT_LIFT_PORT: The port for the right lift motor
    //-------------------------------------------------------------------------
    extern const int LEFT_LIFT_PORT;
    extern const int RIGHT_LIFT_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // leftLiftMotor: The motor on the left side of the carrier
    // rightLiftMotor: The motor on the right side of the carrier
    //-------------------------------------------------------------------------
    extern pros::Motor leftLiftMotor;
    extern pros::Motor rightLiftMotor;
}

#endif