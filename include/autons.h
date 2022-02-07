// Inclusion guard
#ifndef AUTONS_H
#define AUTONS_H

// Included libraries
#include "main.h"
#include "subsystems/Drive.h"
#include "subsystems/Carrier.h"
#include "subsystems/Lift.h"
#include "subsystems/Claw.h"
#include "subsystems/Intake.h"
#include "processes/PositionCalculation.h"

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
    // This function runs the programming skills routine
    // v1: Created the function - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    extern void ProgrammingSkills();
}

#endif