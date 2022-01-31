// Inclusion guard
#ifndef CARRIER_H
#define CARRIER_H

// Included libraries
#include "./main.h"
#include "./config/CarrierConfig.h"
#include "./processes/PID.h"

//-----------------------------------------------------------------------------
// This class manages the carrier subsystem of the robot
// v1: Created the class - Nathan S, 1-29-22
//-----------------------------------------------------------------------------
class Carrier
{
public:
    //-------------------------------------------------------------------------
    // Default contstructor for the Carrier class
    // v1: Created the constructor - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    Carrier();

    //-------------------------------------------------------------------------
    // Gets the current position of the carrier
    // return: The current position of the carrier
    // v1: Created the constructor - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    float GetPosition();

    //-------------------------------------------------------------------------
    // Sets the carrier motors to the desired power
    // power: The power level to set the motors to
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void SetCarrier(float power);

    //-------------------------------------------------------------------------
    // Sets the position of the Carrier to down
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void SetDown();

    //-------------------------------------------------------------------------
    // Sets the position of the Carrier to up
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void SetUp();

    //-------------------------------------------------------------------------
    // Initializes the carrier
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void Initialize();
};

#endif