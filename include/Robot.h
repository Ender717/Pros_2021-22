// Inclusion guard
#ifndef ROBOT_H
#define ROBOT_H

// Included libraries
#include "subsystems/Drive.h"
#include "subsystems/Carrier.h"
#include "subsystems/Lift.h"
#include "subsystems/Claw.h"
#include "subsystems/Intake.h"
#include "config/BlueConfig.h"
#include "config/OldOrangeConfig.h"
#include "config/OldBlueConfig.h"
#include "main.h"

//-----------------------------------------------------------------------------
// This class controls the robot container
// v1: Created the namespace - Nathan S, 2-8-22
// v2: Converted to a class - Nathan S, 2-8-22
//-----------------------------------------------------------------------------
class Robot
{
private:
    //-------------------------------------------------------------------------
    // Creates a pre-configured blue robot
    // v1: Created the method - Nathan S, 3-10-22
    //-------------------------------------------------------------------------
    void CreateBlueRobot();

    //-------------------------------------------------------------------------
    // Creates a pre-configured old orange robot
    // v1: Created the method - Nathan S, 3-10-22
    //-------------------------------------------------------------------------
    void CreateOldOrangeRobot();

    //-------------------------------------------------------------------------
    // Creates a pre-configured old blue robot
    // v1: Created the method - Nathan S, 3-10-22
    //-------------------------------------------------------------------------
    void CreateOldBlueRobot();
    //-------------------------------------------------------------------------
    // Updates the carrier subsystem
    // master: The controller
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void UpdateCarrier(pros::Controller& master);

    //-------------------------------------------------------------------------
    // Updates the claw subsystem
    // master: The controller
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void UpdateClaw(pros::Controller& master);

    //-------------------------------------------------------------------------
    // Updates the drive subsystem
    // master: The controller
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void UpdateDrive(pros::Controller& master);

    //-------------------------------------------------------------------------
    // Updates the intake subsystem
    // master: The controller
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void UpdateIntake(pros::Controller& master);

    //-------------------------------------------------------------------------
    // Updates the lift subsystem
    // master: The controller
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void UpdateLift(pros::Controller& master);

public:
    //-------------------------------------------------------------------------
    // Subsystems
    // drive: The drive subsystem
    // carrier: The carrier subsystem
    // lift: The lift subsystem
    // claw: The claw subsystem
    // intake: The intake subsystem
    //-------------------------------------------------------------------------
    Drive drive;
	Carrier carrier;
	Lift lift;
	Claw claw;
	Intake intake;

    //-------------------------------------------------------------------------
    // Default constructor for the robot class
    // v1: Created the constructor - Nathan S, 2-8-22
    //-------------------------------------------------------------------------
    Robot();

    //-------------------------------------------------------------------------
    // Initializes the robot
    // robotSelected: The robot which was selected
    // v1: Created the method - Nathan S, 2-8-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Controls the robot during driver control mode
    // master: The controller
    // v1: Created the method - Nathan S, 2-8-22
    //-------------------------------------------------------------------------
    void RobotControl(pros::Controller& master);
};

#endif