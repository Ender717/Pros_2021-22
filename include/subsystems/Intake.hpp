// Inclusion guard
#ifndef INTAKE_H
#define INTAKE_H

// Included libraries
#include "./main.h"
#include <list>
#include "./processes/PID.hpp"

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
    // motorList: The list of motors on the intake
    // intakePID: The PID controller in charge of the intake
    // intakeSpeed: The speed the intake runs at
    //-------------------------------------------------------------------------
    std::list<pros::Motor> motorList;
    PID intakePID;
    float intakeSpeed;

public:
    //-------------------------------------------------------------------------
    // This is a builder class for the intake
    // v1: Created the class - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    class IntakeBuilder
    {
    public:
        //---------------------------------------------------------------------
        // motorList: The list of motors
        // intakePID: The PID controller
        //---------------------------------------------------------------------
        std::list<pros::Motor> motorList;
        PID intakePID;

        //---------------------------------------------------------------------
        // Default constructor for the IntakeBuilder class
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        IntakeBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the build
        // motor: The motor being added to the build
        // return: The IntakeBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        IntakeBuilder WithMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller to the build
        // pid: The PID controller being added to the build
        // return: The IntakeBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        IntakeBuilder WithPID(PID pid);

        //---------------------------------------------------------------------
        // Build method for the IntakeBuilder
        // return: The intake
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Intake Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the intake class
    // speed: The speed this intake runs at
    // v1: Created the constructor - Nathan S, 2-2-22
    // v2: Added a speed parameter - Nathan S, 2-14-22
    // v3: Changed the speed parameter to a setter - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Intake();

    //-------------------------------------------------------------------------
    // Builder constructor for the intake class
    // builder: The builder being used for construction
    // v1: Created the method - Nathan S 3-9-22
    //-------------------------------------------------------------------------
    Intake(IntakeBuilder builder);
    
    //-------------------------------------------------------------------------
    // Initializes the intake system
    // v1: Created the method - Nathan S, 2-2-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Sets the speed of the intake
    // speed: The speed to set the intake to
    // v1: Created the method - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    void SetSpeed(float speed);

    //-------------------------------------------------------------------------
    // Runs the intake inwards
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Suck();

    //-------------------------------------------------------------------------
    // Runs the intake outwards
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Blow();

    //-------------------------------------------------------------------------
    // Stops the intake
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void Stop();
};

#endif