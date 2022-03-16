// Inclusion guard
#ifndef MENU_H
#define MENU_H

// Included libraries
#include "main.h"

//-----------------------------------------------------------------------------
// This class manages the menu system for the robot
// v1: Created the class - Nathan S, 2-9-22
//-----------------------------------------------------------------------------
class Menu
{
private:
    //-------------------------------------------------------------------------
    // Constants:
    // NUM_ROBOTS: The total number of robot configurations available
    // NUM_AUTONS: The total number of auton routines available
    //-------------------------------------------------------------------------
    static const int NUM_ROBOTS = 4;
    static const int NUM_AUTONS = 5;

public:
    //-------------------------------------------------------------------------
    // Public data members:
    // robotSelected: The robot which was selected to be used
    // autonSelected: The robot which was selected to be used
    //-------------------------------------------------------------------------
    static int selectedRobot;
    static int selectedAuton;
    
    //-------------------------------------------------------------------------
    // Draws the auton selection menu
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void DrawMenuSelect();

    //-------------------------------------------------------------------------
    // Runs the robot selection menu
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void RobotSelect();

    //-------------------------------------------------------------------------
    // Runs the autonomous selection menu
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void AutonSelect();

    //-------------------------------------------------------------------------
    // Displays the current position of the robot on screen
    // x: The x-coordinate of the robot
    // y: The y-coordinate of the robot
    // theta: The angle of the robot
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    static void DrawPosition(double x, double y, double theta);
};

#endif