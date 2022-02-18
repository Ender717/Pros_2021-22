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
    // taskComplete: Whether the main task has been completed or not
    //-------------------------------------------------------------------------
    bool taskComplete;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the auton controller class
    // v1: Created the constructor - Nathan S, 2-17-22
    //-------------------------------------------------------------------------
    AutonController();

    //-------------------------------------------------------------------------
    // Sets the main task being run by the controller
    // function: The function the task is running
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void SetMainTask(void (*func)(float, float, float));


};

#endif