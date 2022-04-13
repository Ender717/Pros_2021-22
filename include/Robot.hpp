// Inclusion guard
#ifndef ROBOT_H
#define ROBOT_H

// Included libraries
#include "subsystems/Drive.hpp"
#include "subsystems/Carrier.hpp"
#include "subsystems/Lift.hpp"
#include "subsystems/Claw.hpp"
#include "subsystems/Intake.hpp"
#include "config/BlueConfig.hpp"
#include "config/OrangeConfig.hpp"
#include "config/OldBlueConfig.hpp"
#include "config/OldOrangeConfig.hpp"
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
    // Creates a pre-configured orange robot
    // v1: Created the method - Nathan S, 3-10-22
    //-------------------------------------------------------------------------
    void CreateOrangeRobot();

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
    Drive* drive;
	Carrier* carrier;
	Lift* lift;
	Claw* claw;
	Intake* intake;

    //-------------------------------------------------------------------------
    // This class builds a robot
    // v1: Created the class - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    class RobotBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Subsystems
        // carrier: The carrier subsystems
        // claw: The claw subsystem
        // drive: The drive subsystem
        // intake: The intake subsystem
        // lift: The lift subsystem
        //---------------------------------------------------------------------
        Carrier* carrier;
        Claw* claw;
        Drive* drive;
        Intake* intake;
        Lift* lift;

        //---------------------------------------------------------------------
        // Default constructor for the RobotBuilder class
        // v1: Created the constructor - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the RobotBuilder class
        // v1: Created the destructor - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        ~RobotBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a carrier to the build
        // carrier: The carrier being added to the build
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder* WithCarrier(Carrier* carrier);

        //---------------------------------------------------------------------
        // Wither method to add a claw to the build
        // claw: The claw being added to the build
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder* WithClaw(Claw* claw);

        //---------------------------------------------------------------------
        // Wither method to add a drive to the build
        // drive: The drive being added to the build
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder* WithDrive(Drive* drive);

        //---------------------------------------------------------------------
        // Wither method to add an intake to the build
        // intake: The intake being added to the build
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder* WithIntake(Intake* intake);

        //---------------------------------------------------------------------
        // Wither method to add a lift to the build
        // lift: The lift being added to the build
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        RobotBuilder* WithLift(Lift* lift);

        //---------------------------------------------------------------------
        // Build method to build the robot
        // return: The robot which was built
        // v1: Created the method - Nathan S, 4-13-22
        //---------------------------------------------------------------------
        Robot* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for the robot class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    Robot(RobotBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for the Robot class
    // v1: Created the destructor - Nathan S, 4-12-22
    //-------------------------------------------------------------------------
    ~Robot();

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