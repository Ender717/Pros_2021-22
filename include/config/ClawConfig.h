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
    // GOAL_THRESHOLD: The threshold the goal sensor passes when a goal is there
    //-------------------------------------------------------------------------
    extern const float OPEN_POSITION;
    extern const float CLOSED_POSITION;
    extern const float GOAL_THRESHOLD;

    //-------------------------------------------------------------------------
    // Ports
    // CLAW_PORT: The port the claw motor is in
    // GOAL_SENSOR_PORT: The port the goal sensor is in
    //-------------------------------------------------------------------------
    extern const int CLAW_PORT;
    extern const int GOAL_SENSOR_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // clawMotor: The motor for the claw
    //-------------------------------------------------------------------------
    extern pros::Motor clawMotor;

    //-------------------------------------------------------------------------
    // Sensors
    // goalSensor: The optical sensor in charge of detecting goals in the claw
    //-------------------------------------------------------------------------
    extern pros::Optical goalSensor;
}

#endif