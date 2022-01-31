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
    // MIDDLE_POSITION: The encoder position when the lift is parallel to the ground
    // TOP_POSITION: The encoder position when the lift is at the top
    // ARM_LENGTH: The length of the arm in inches
    // COUNTS_PER_ROTATION: The number of encoder counts in one rotation of the arm
    // DEGREES_TO_RADIANS: The constant multiple from degrees to radians
    //-------------------------------------------------------------------------
    extern const float BOTTOM_POSITION;
    extern const float MIDDLE_POSITION;
    extern const float TOP_POSITION;
    extern const float ARM_LENGTH;
    extern const float COUNTS_PER_ROTATION;
    extern const float DEGREES_TO_RADIANS;

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