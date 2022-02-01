// Inclusion guard
#ifndef LIFT_H
#define LIFT_H

// Included libraries
#include "./main.h"
#include "./config/LiftConfig.h"
#include "./processes/PID.h"

//-----------------------------------------------------------------------------
// This class manages the lift subsystem of the robot
// v1: Created the class - Nathan S, 1-30-22
//-----------------------------------------------------------------------------
class Lift
{
private:

public:
    //-------------------------------------------------------------------------
    // Default constructor for the Lift class
    // v1: Created the constructor - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    Lift();

    //-------------------------------------------------------------------------
    // Initializes the lift
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Gets the current position of the lift encoders
    // return: The position of the lift encoders
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    float GetPosition();

    //-------------------------------------------------------------------------
    // Gets the current height of the lift
    // return: The height of the lift in inches
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    float GetHeight();

    //-------------------------------------------------------------------------
    // Sets the motors on the lift to the desired power
    // power: The power to set the motors to
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void SetLift(float power);

    //-------------------------------------------------------------------------
    // Sets the lift to the desired height in inches
    // inches: The height to set the lift to
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void SetHeight(float inches);
};

#endif