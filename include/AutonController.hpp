// Inclusion guard
#ifndef AUTON_CONTROLLER_HPP
#define AUTON_CONTROLLER_HPP

// Included libraries
#include "Robot.hpp"
#include "main.h"

//-----------------------------------------------------------------------------
// This class manages the autonomous control system
// v1: Created the class - Nathan S, 2-17-22
//-----------------------------------------------------------------------------
class AutonController
{
public:
    //-------------------------------------------------------------------------
    // Private data members
    // robot: The robot
    //-------------------------------------------------------------------------
    static Robot* robot;

    //-------------------------------------------------------------------------
    // Default constructor for the auton controller class
    // x: The starting x-coordinate
    // y: The starting y-coordinate
    // theta: The starting angle
    // v1: Created the constructor - Nathan S, 2-17-22
    //-------------------------------------------------------------------------
    AutonController(Robot* robot);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the drive
    // distance: The distance to drive forward
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoDistanceTask(double distance, double liftAngle, bool clawClosed, 
        bool carrierDown, bool intake);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by a turn
    // targetAngle: The target angle for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-22-22
    //-------------------------------------------------------------------------
    void DoTurnTask(double targetAngle, double liftAngle, bool clawClosed,
        bool carrierDown, bool intake);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the lift
    // distance: The distance for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoLiftDistanceTask(double distance, double liftAngle, bool clawClosed, 
        bool carrierDown, bool intake);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the lift
    // targetAngle: The target angle for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoLiftTurnTask(double targetAngle, double liftAngle, bool clawClosed, 
        bool carrierDown, bool intake);
};

#endif