// Inclusion guard
#ifndef AUTONS_H
#define AUTONS_H

// Included libraries
#include "main.h"
#include "Menu.h"
#include "AutonController.h"

//-----------------------------------------------------------------------------
// This namespace contains all autonomous configurations and values
//-----------------------------------------------------------------------------
namespace Autons
{
    //-------------------------------------------------------------------------
    // Constants
    // NUM_AUTONS: The number of autonomous routines available
    //-------------------------------------------------------------------------
    extern const int NUM_AUTONS;

    //-------------------------------------------------------------------------
    // Variables
    // selectedAuton: The number of the auton selected
    //-------------------------------------------------------------------------
    extern int selectedAuton;

    //-------------------------------------------------------------------------
    // This function runs the programming skills 1 routine
    // v1: Created the function - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    extern void ProgrammingSkills1();

    //-------------------------------------------------------------------------
    // This function runs the programming skills 2 routine
    // v1: Created the function - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    extern void ProgrammingSkills2();

    //-------------------------------------------------------------------------
    // This function runs the left auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void LeftAuton();

    //-------------------------------------------------------------------------
    // This function runs the middle auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void MiddleAuton();

    //-------------------------------------------------------------------------
    // This function runs the right auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void RightAuton();
}

#endif