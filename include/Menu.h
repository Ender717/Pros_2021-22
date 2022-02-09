// Inclusion guard
#ifndef MENU_H
#define MENU_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace manages the menu system for the robot
// v1: Created the namespace - Nathan S, 2-9-22
//-----------------------------------------------------------------------------
namespace Menu
{
    //-------------------------------------------------------------------------
    // Draws the auton selection menu
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void DrawAutonSelect();

    //-------------------------------------------------------------------------
    // Runs the autonomous selection menu
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void AutonSelect();
}

#endif