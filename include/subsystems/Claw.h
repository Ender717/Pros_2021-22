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
// v2: Refactored the class - Nathan S, 2-13-22
//-----------------------------------------------------------------------------
class Claw
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // isClosed: Whether the claw is closed or not
    // clawPID: The PID controller for the claw
    //-------------------------------------------------------------------------
    bool isClosed;
    PID clawPID;

public:
    //-------------------------------------------------------------------------
    // Default contstructor for the Claw class
    // startClosed: Whether the claw starts closed or not
    // v1: Created the constructor - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    Claw(bool startClosed);

    //-------------------------------------------------------------------------
    // Initializes the claw
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void Initialize();

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
    // Holds the current position of the claw
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Checks if the claw is closed or not
    // return: True if the claw is closed, false if not
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    bool IsClosed();
};

#endif