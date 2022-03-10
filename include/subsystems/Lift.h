// Inclusion guard
#ifndef LIFT_H
#define LIFT_H

// Included libraries
#include <list>
#include "./processes/PID.h"
#include "./main.h"

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
    // leftMotorList: The left side motors
    // rightMotorList: The right side motors
    // liftPID: The PID controller in charge of the lift
    // startAngle: The starting angle of the lift in degrees
    // countsPerDegree: The number of encoder counts per degree
    //-------------------------------------------------------------------------
    std::list<pros::Motor> leftMotorList;
    std::list<pros::Motor> rightMotorList;
    PID liftPID;
    float topAngle;
    float bottomAngle;
    float startAngle;
    float countsPerDegree;

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
    // Builder class for the lift
    // v1: Created the class - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    class LiftBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // leftMotorList: The left side motors
        // rightMotorList: The right side motors
        // liftPID: The PID controller in charge of the lift
        // startAngle: The starting angle of the lift in degrees
        // countsPerDegree: The number of encoder counts per degree
        //---------------------------------------------------------------------
        std::list<pros::Motor> leftMotorList;
        std::list<pros::Motor> rightMotorList;
        PID liftPID;
        float topAngle;
        float bottomAngle;
        float startAngle;
        float countsPerDegree;

        //---------------------------------------------------------------------
        // Default constructor for the LiftBuilder class
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the left side of the build
        // motor: The motor being added to the left side
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithLeftMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a motor to the right side of the build
        // motor: The motor being added to the right side
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithRightMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a pid controller to the build
        // pid: The PID controller being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithPID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add a top angle to the build
        // topAngle: The top angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithTopAngle(float topAngle);

        //---------------------------------------------------------------------
        // Wither method to add a bottom angle to the build
        // bottomAngle: The bottom angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithBottomAngle(float bottomAngle);

        //---------------------------------------------------------------------
        // Wither method to add a starting angle to the build
        // startAngle: The starting angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithStartAngle(float startAngle);

        //---------------------------------------------------------------------
        // Wither method to add the counts per degree of the lift to the build
        // countsPerDegree: The counts per degree being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        LiftBuilder WithCountsPerDegree(float countsPerDegree);

        //---------------------------------------------------------------------
        // Builder method for the builder class
        // return: The lift
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Lift Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the Lift class
    // angle: The angle the lift is starting at
    // v1: Created the constructor - Nathan S, 1-30-22
    // v2: Added an angle parameter - Nathan S, 2-14-22
    // v3: Changed angle to builder - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Lift();

    //-------------------------------------------------------------------------
    // Builder constructor for the Lift class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Lift(LiftBuilder builder);

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