// Inclusion guard
#ifndef AUTONS_HPP
#define AUTONS_HPP

// Included libraries
#include "AutonController.hpp"
#include "main.h"

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
    extern void ProgrammingSkillsBlue();

    //-------------------------------------------------------------------------
    // This function runs the programming skills 2 routine
    // v1: Created the function - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    extern void ProgrammingSkillsOrange();

    //-------------------------------------------------------------------------
    // This function runs the left auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void LeftAutonBlue();

    //-------------------------------------------------------------------------
    // This function runs the middle auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void MiddleAutonBlue();

    //-------------------------------------------------------------------------
    // This function runs the right auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void RightAutonBlue();

    //-------------------------------------------------------------------------
    // This function runs the left auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void LeftAutonOrange();

    //-------------------------------------------------------------------------
    // This function runs the middle auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void MiddleAutonOrange();

    //-------------------------------------------------------------------------
    // This function runs the right auton routine
    // v1: Created the function - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    extern void RightAutonOrange();
}

#endif