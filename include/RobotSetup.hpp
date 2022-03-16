// Inclusion guard
#ifndef ROBOT_SETUP_H
#define ROBOT_SETUP_H

// Included libraries
#include "main.h"
#include "Robot.hpp"

//-----------------------------------------------------------------------------
// This class manages the setup process for the robot
// v1: Created the class - Nathan S, 3-15-22
//-----------------------------------------------------------------------------
class RobotSetup
{
public:
    //-------------------------------------------------------------------------
    // The robot being initialized and stored
    //-------------------------------------------------------------------------
    static Robot robot;

    //-------------------------------------------------------------------------
    // Initializes the robot
    // robotSelected: The robot configuration which was selected
    // v1: Created the function - Nathan S, 3-15-22
    //-------------------------------------------------------------------------
    static void Initialize(int robotSelected);
};

#endif