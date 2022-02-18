// Inclusion guard
#ifndef AUTON_CONTROLLER_H
#define AUTON_CONTROLLER_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the autonomous control system
// v1: Created the class - Nathan S, 2-17-22
//-----------------------------------------------------------------------------
class AutonController
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // NUM_TASKS: The number of tasks the system runs concurrently
    //-------------------------------------------------------------------------
    const int NUM_TASKS = 6;
    pros::Task taskList;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the auton controller class
    // v1: Created the constructor - Nathan S, 2-17-22
    //-------------------------------------------------------------------------
    AutonController();
};

#endif