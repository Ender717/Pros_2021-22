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
// v2: Refactored the class for data management - Nathan S, 2-13-22
//-----------------------------------------------------------------------------
class Carrier
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // isDown: Whether the carrier is down or not
    // hasGoal: Whether the carrier is holding a goal or not
    //-------------------------------------------------------------------------
    bool isDown;
    bool hasGoal;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the Carrier class
    // startDown: Whether the carrier starts down or not
    // v1: Created the constructor - Nathan S, 1-29-22
    // v2: Added a parameter to control start position - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    Carrier(bool startDown);

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
    // Checks if the carrier is down or not
    // return: True if the carrier is down, false if not
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    bool IsDown();

    //-------------------------------------------------------------------------
    // Checks if the carrier has a goal or not
    // return: True if the carrier has a goal, false if not
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    bool HasGoal();

    //-------------------------------------------------------------------------
    // Initializes the carrier
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void Initialize();
};

#endif