// Inclusion guard
#ifndef INTAKE_CONFIG_H
#define INTAKE_CONFIG_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This namespace controls the intake subsystem members of the robot
// v1: Created the namespace - Nathan S, 2-2-22
//-----------------------------------------------------------------------------
namespace IntakeConfig
{
    //-------------------------------------------------------------------------
    // Ports
    // INTAKE_PORT: The port the intake motor is in
    //-------------------------------------------------------------------------
    extern const int INTAKE_PORT;

    //-------------------------------------------------------------------------
    // Motors
    // intakeMotor: The motor for the intake
    //-------------------------------------------------------------------------
    extern pros::Motor intakeMotor;
}

#endif