// Inclusion guard
#ifndef ROBOT_H
#define ROBOT_H

// Included libraries
#include "main.h"
#include "Drive.h"

//-----------------------------------------------------------------------------
// This class manages a robot which exists as a container of its subsystems
// v1: Created the class - Nathan S, 1-24-22
//-----------------------------------------------------------------------------
class Robot
{
private:

public:
    //-------------------------------------------------------------------------
    // Default constructor for the robot class
    // v1: Created the constructor - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    Robot();

    //-------------------------------------------------------------------------
    // Initializes all subsystems within the robot
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void Initialize();
};

#endif