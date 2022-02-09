// Inclusion guard
#ifndef CLAW_H
#define CLAW_H

// Included libraries
#include "./main.h"
#include "./config/ClawConfig.h"
#include "./processes/PID.h"

//-----------------------------------------------------------------------------
// This class manages the claw subsystem of the robot
// v1: Created the class - Nathan S, 1-31-22
//-----------------------------------------------------------------------------
class Claw
{
public:
    //-------------------------------------------------------------------------
    // Default contstructor for the Claw class
    // v1: Created the constructor - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    Claw(int n);

    //-------------------------------------------------------------------------
    // Gets the current position of the claw
    // return: The current position of the claw
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    float GetPosition();

    //-------------------------------------------------------------------------
    // Sets the claw motor to the desired power
    // power: The power level to set the motor to
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void SetClaw(float power);

    //-------------------------------------------------------------------------
    // Sets the position of the claw to closed
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void SetClosed();

    //-------------------------------------------------------------------------
    // Sets the position of the claw to open
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void SetOpen();

    //-------------------------------------------------------------------------
    // Initializes the claw
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void Initialize();
};

#endif