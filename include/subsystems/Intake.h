// Inclusion guard
#ifndef INTAKE_H
#define INTAKE_H

// Included libraries
#include "./main.h"
#include "./config/IntakeConfig.h"
#include "./processes/PID.h"

//-----------------------------------------------------------------------------
// This class manages the Intake subsystem of the robot
// v1: Created the class - Nathan S, 2-2-22
//-----------------------------------------------------------------------------
class Intake
{
public:
    //-------------------------------------------------------------------------
    // Default constructor for the intake class
    // v1: Created the constructor - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    Intake();
    
    //-------------------------------------------------------------------------
    // Initializes the intake system
    // v1: Created the method - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Gets the current position of the intake
    // return: The current encoder position of the intake motor
    // v1: Created the method - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    float GetPosition();

    //-------------------------------------------------------------------------
    // Sets the intake to a specified power level
    // power: The power level to set the intake to
    // v1: Created the method - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    void SetIntake(float power);
};

#endif