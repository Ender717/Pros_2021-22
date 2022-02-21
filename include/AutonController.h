// Inclusion guard
#ifndef AUTON_CONTROLLER_H
#define AUTON_CONTROLLER_H

// Included libraries
#include "Robot.h"
#include "Menu.h"
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
    // robot: The robot
    //-------------------------------------------------------------------------
    Robot robot;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the auton controller class
    // v1: Created the constructor - Nathan S, 2-17-22
    //-------------------------------------------------------------------------
    AutonController();

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the drive
    // targetX: The target x-coordinate for the drive
    // targetY: The target y-coordinate for the drive
    // drivePower: The maximum power for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoDriveTask(float targetX, float targetY, float drivePower,
                     float liftAngle, bool clawClosed, bool carrierDown);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the lift
    // targetX: The target x-coordinate for the drive
    // targetY: The target y-coordinate for the drive
    // drivePower: The maximum power for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoLiftTask(float targetX, float targetY, float drivePower,
                     float liftAngle, bool clawClosed, bool carrierDown);
};

#endif