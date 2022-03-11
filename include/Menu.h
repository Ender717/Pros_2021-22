// Inclusion guard
#ifndef MENU_H
#define MENU_H

// Included libraries
#include "Robot.h"
#include "./main.h"
#include "autons.h"

//-----------------------------------------------------------------------------
// This namespace manages the menu system for the robot
// v1: Created the namespace - Nathan S, 2-9-22
//-----------------------------------------------------------------------------
namespace Menu
{
    //-------------------------------------------------------------------------
    // Variables
    // robotSelected: True if an robot has been selected, false if not
    // autonSelected: True if an auton has been selected, false if not
    // robotSelected: The robot which was selected to be used
    //-------------------------------------------------------------------------
    extern bool autonSelected;
    
    //-------------------------------------------------------------------------
    // Draws the auton selection menu
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void DrawMenuSelect();

    //-------------------------------------------------------------------------
    // Runs the autonomous selection menu
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void AutonSelect();

    //-------------------------------------------------------------------------
    // Displays the current position of the robot on screen
    // robot: The robot
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    extern void DrawPosition(const Robot& robot);
}

#endif