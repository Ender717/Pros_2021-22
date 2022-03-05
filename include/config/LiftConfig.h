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
    // BOTTOM_POSITION: The minimum angle of the lift
    // TOP_POSITION: The maximum angle of the lift
    // COUNTS_PER_DEGREE: The number of encoder counts the lift moves per degree
    //                    of rotation it experiences
    // DEGREES_TO_RADIANS: The constant multiple from degrees to radians
    //-------------------------------------------------------------------------
    extern const float BOTTOM_POSITION;
    extern const float TOP_POSITION;
    extern const float COUNTS_PER_DEGREE;
    extern const float DEGREES_TO_RADIANS;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_LIFT_1_PORT: The port for the first left lift motor
    // LEFT_LIFT_2_PORT: The port for the second left lift motor
    // RIGHT_LIFT_1_PORT: The port for the first right lift motor
    // RIGHT_LIFT_2_PORT: The port for the second right lift motor
    //-------------------------------------------------------------------------
    extern const int LEFT_LIFT_1_PORT;
    extern const int LEFT_LIFT_2_PORT;
    extern const int RIGHT_LIFT_1_PORT;
    extern const int RIGHT_LIFT_2_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // leftLift1Motor: The first motor on the left side of the lift
    // leftLift2Motor: The second motor on the left side of the lift
    // rightLift1Motor: The first motor on the right side of the lift
    // rightLift2Motor: The second motor on the right side of the lift
    //-------------------------------------------------------------------------
    extern pros::Motor leftLift1Motor;
    extern pros::Motor leftLift2Motor;
    extern pros::Motor rightLift1Motor;
    extern pros::Motor rightLift2Motor;
}

#endif