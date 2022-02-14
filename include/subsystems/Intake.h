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
// v2: Refactored the class - Nathan S, 2-14-22
//-----------------------------------------------------------------------------
class Intake
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // intakeSpeed: The speed the intake runs at
    //-------------------------------------------------------------------------
    float intakeSpeed;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the intake class
    // speed: The speed this intake runs at
    // v1: Created the constructor - Nathan S, 2-2-22
    // v2: Added a speed parameter - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    Intake(float speed);
    
    //-------------------------------------------------------------------------
    // Initializes the intake system
    // v1: Created the method - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Runs the intake inwards
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Intake();

    //-------------------------------------------------------------------------
    // Runs the intake outwards
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Outtake();

    //-------------------------------------------------------------------------
    // Stops the intake
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Stop();
};

#endif