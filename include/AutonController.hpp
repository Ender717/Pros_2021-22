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
private:
    //-------------------------------------------------------------------------
    // Private data members
    // robot: The robot
    //-------------------------------------------------------------------------
    Robot* robot;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the auton controller class
    // x: The starting x-coordinate
    // y: The starting y-coordinate
    // theta: The starting angle
    // v1: Created the constructor - Nathan S, 2-17-22
    //-------------------------------------------------------------------------
    AutonController(double x, double y, double theta);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by the position
    // targetX: The target x-coordinate for the drive
    // targetY: The target y-coordinate for the drive
    // drivePower: The maximum power for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void DoPositionTask(double targetX, double targetY, double drivePower,
                        double liftAngle, bool clawClosed, bool carrierDown, bool intake);

    //-------------------------------------------------------------------------
    // Runs an autonomous task routine controlled by a turn
    // targetX: The target angle for the drive
    // drivePower: The maximum power for the drive
    // liftAngle: The angle to set the lift to
    // clawClosed: Whether the claw should be closed or not
    // carrierDown: Whether the carrier should be down or not
    // v1: Created the method - Nathan S, 2-22-22
    //-------------------------------------------------------------------------
    void DoTurnTask(double targetAngle, double drivePower, double liftAngle, 
                    bool clawClosed, bool carrierDown, bool intake);

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
    void DoLiftTask(double targetX, double targetY, double drivePower,
                     double liftAngle, bool clawClosed, bool carrierDown, bool intake);
};

#endif