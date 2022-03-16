// Inclusion guard
#ifndef AUTONS_H
#define AUTONS_H

// Included libraries
#include "main.h"
#include "AutonController.hpp"

//-----------------------------------------------------------------------------
// This class contains all autonomous configurations and values
// v1: Created the class - Nathan S, 2-6-22
//-----------------------------------------------------------------------------
class Autons
{
public:
    //-------------------------------------------------------------------------
    // This method runs the programming skills 1 routine
    // v1: Created the method - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    static void ProgrammingSkills1();

    //-------------------------------------------------------------------------
    // This method runs the programming skills 2 routine
    // v1: Created the method - Nathan S, 2-6-22
    //-------------------------------------------------------------------------
    static void ProgrammingSkills2();

    //-------------------------------------------------------------------------
    // This method runs the left auton routine
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void LeftAuton();

    //-------------------------------------------------------------------------
    // This method runs the middle auton routine
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void MiddleAuton();

    //-------------------------------------------------------------------------
    // This method runs the right auton routine
    // v1: Created the method - Nathan S, 2-9-22
    //-------------------------------------------------------------------------
    static void RightAuton();
};

#endif