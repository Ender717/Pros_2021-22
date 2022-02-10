// Inclusion guard
#ifndef ROBOT_H
#define ROBOT_H

// Included libraries
#include "./main.h"
#include "subsystems/Drive.h"
#include "subsystems/Carrier.h"
#include "subsystems/Lift.h"
#include "subsystems/Claw.h"
#include "subsystems/Intake.h"

//-----------------------------------------------------------------------------
// This namespace controls the robot container
// v1: Created the namespace - Nathan S, 2-8-22
//-----------------------------------------------------------------------------
namespace Robot
{
    //-------------------------------------------------------------------------
    // Variables
    // leftDrivePower: The power being sent to the left side of the drive
    // rightDrivePower: The power being sent to the right side of the drive
    // liftPower: The power being sent to the lift
    // intakePower: The power being sent to the intake
    // clawClosed: Whether the claw is currently closed or not
    // carrierDown: Whetherr the carrier is currently down or not
    //-------------------------------------------------------------------------
    extern float leftDrivePower;
    extern float rightDrivePower;
    extern float liftPower;
    extern float intakePower;
    extern bool clawClosed;
    extern bool carrierDown;

    //-------------------------------------------------------------------------
    // Processes
    // liftPID: The PID controller in charge of the lift
    // position: The position tracking system
    //-------------------------------------------------------------------------
	extern PID liftPID;
	extern PositionCalculation position;

    //-------------------------------------------------------------------------
    // Subsystems
    // drive: The drive subsystem
    // carrier: The carrier subsystem
    // lift: The lift subsystem
    // claw: The claw subsystem
    // intake: The intake subsystem
    //-------------------------------------------------------------------------
    extern Drive drive;
	extern Carrier carrier;
	extern Lift lift;
	extern Claw claw;
	extern Intake intake;

    //-------------------------------------------------------------------------
    // Initializes the robot
    // v1: Created the function - Nathan S, 2-8-22
    //-------------------------------------------------------------------------
    extern void Initialize();

    //-------------------------------------------------------------------------
    // Controls the robot during driver control mode
    // master: The controller
    // v1: Created the function - Nathan S, 2-8-22
    //-------------------------------------------------------------------------
    extern void DriveControl(pros::Controller& master);
}

#endif