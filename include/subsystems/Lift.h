// Inclusion guard
#ifndef LIFT_H
#define LIFT_H

// Included libraries
#include "./main.h"
#include "./config/LiftConfig.h"
#include "./processes/PID.h"

//-----------------------------------------------------------------------------
// This class manages the lift subsystem of the robot
// v1: Created the class - Nathan S, 1-30-22
// v2: Restructured the class - Nathan S, 2-14-22
//-----------------------------------------------------------------------------
class Lift
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // liftPID: The PID controller in charge of the lift
    // startAngle: The starting angle of the lift in degrees
    //-------------------------------------------------------------------------
    PID liftPID;
    float startAngle;

    //-------------------------------------------------------------------------
    // Sets the lift to the designated power level
    // power: The power level to set the lift to
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void SetLift(float power);

    //-------------------------------------------------------------------------
    // Checks if the lift is at the bottom of its range
    // return: True if the lift is at the bottom of its range, false if not
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    bool AtBottom();

    //-------------------------------------------------------------------------
    // Checks if the lift is at the top of its range
    // return: True if the lift is at the top of its range, false if not
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    bool AtTop();

    //-------------------------------------------------------------------------
    // Calculates the current angle of the lift
    // return: The current angle of the lift in degrees
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetAngle();

public:
    //-------------------------------------------------------------------------
    // Default constructor for the Lift class
    // angle: The angle the lift is starting at
    // v1: Created the constructor - Nathan S, 1-30-22
    // v2: Added an angle parameter - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    Lift(float angle);

    //-------------------------------------------------------------------------
    // Initializes the lift
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Raises the lift
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Raise();

    //-------------------------------------------------------------------------
    // Lowers the lift
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Lower();

    //-------------------------------------------------------------------------
    // Holds the lift at its current position
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Sets the lift to the desired angle
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void SetAngle(float targetAngle);

    //-------------------------------------------------------------------------
    // Sets the lift to the desired angle as a target
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void SetTargetAngle(float targetAngle);
};

#endif