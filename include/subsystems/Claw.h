// Inclusion guard
#ifndef CLAW_H
#define CLAW_H

// Included libraries
#include <list>
#include "./processes/PID.h"
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the claw subsystem of the robot
// v1: Created the class - Nathan S, 1-31-22
// v2: Refactored the class - Nathan S, 2-13-22
//-----------------------------------------------------------------------------
class Claw
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // motorList: The list of motors
    // pistonList: The list of pistons
    // clawPID: The PID controller in charge of the claw
    // openPosition: The position the claw rests at when it is open
    // closedPosition: The position the claw rests at when it is closed
    // isClosed: Whether the claw is closed or not
    //-------------------------------------------------------------------------
    std::list<pros::Motor> motorList;
    std::list<pros::ADIDigitalOut> pistonList;
    PID clawPID;
    float openPosition;
    float closedPosition;
    bool isClosed;

public:
    //-------------------------------------------------------------------------
    // This is the builder class for the Claw subsystem
    // v1: Created the class - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    class ClawBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // motorList: The list of motors
        // pistonList: The list of pistons
        // clawPID: The PID controller in charge of the claw
        // openPosition: The position the claw rests at when it is open
        // closedPosition: The position the claw rests at when it is closed
        //---------------------------------------------------------------------
        std::list<pros::Motor> motorList;
        std::list<pros::ADIDigitalOut> pistonList;
        PID clawPID;
        float openPosition;
        float closedPosition;

        //---------------------------------------------------------------------
        // Default constructor for the ClawBuilder
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the claw build
        // motor: The motor being added to the build
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder WithMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a piston to the claw build
        // piston: The piston being added to the build
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder WithPiston(pros::ADIDigitalOut piston);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller to the claw build
        // pid: The PID controller being added to the build
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder WithPID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add an open position to the claw build
        // openPosition: The openPosition being added to the build
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder WithOpenPosition(float openPosition);

        //---------------------------------------------------------------------
        // Wither method to add a closed position to the claw build
        // closedPosition: The closedPosition being added to the build
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        ClawBuilder WithClosedPosition(float closedPosition);

        //---------------------------------------------------------------------
        // Build method to construct the claw
        // return: The claw
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Claw Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the Claw class
    // v1: Created the constructor - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    Claw();

    //-------------------------------------------------------------------------
    // Builder constructor for the Claw class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Claw(ClawBuilder builder);

    //-------------------------------------------------------------------------
    // Initializes the claw
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Sets the position of the claw to closed
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void SetClosed();

    //-------------------------------------------------------------------------
    // Sets the position of the claw to open
    // v1: Created the method - Nathan S, 1-31-22
    //-------------------------------------------------------------------------
    void SetOpen();

    //-------------------------------------------------------------------------
    // Holds the current position of the claw
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Checks if the claw is closed or not
    // return: True if the claw is closed, false if not
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    bool IsClosed() const;
};

#endif