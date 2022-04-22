// Inclusion guard
#ifndef CLAW_HPP
#define CLAW_HPP

// Included libraries
#include <list>
#include <cfloat>
#include "./processes/PID.hpp"
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the claw subsystem of the robot
// v1: Created the class - Nathan S, 1-30-22
// v2: Refactored - Nathan S, 2-14-22
// v3: Converted to generalized class - Nathan S, 4-1-22
//-----------------------------------------------------------------------------
class Claw
{
private:
    //-------------------------------------------------------------------------
    // Private data members:
    // motorList: The motors on the claw
    // pistonList: The pistons on the claw
    // objectSensor: The sensor used to determine if the claw is holding an object
    // clawPID: The PID controller in charge of the claw
    // minPosition: The minimum position of the claw in encoder counts
    // maxPosition: The maximum position of the claw in encoder counts
    // openPosition: The position of the claw when it is open
    // closedPosition: The position of the claw when it is closed
    // isOpen: Whether the claw is open or not
    //-------------------------------------------------------------------------
    std::list<pros::Motor*>* motorList;
    std::list<pros::ADIDigitalOut*>* pistonList;
    pros::ADIDigitalIn* objectSensor;
    PID* clawPID;
    double* minPosition;
    double* maxPosition;
    double* openPosition;
    double* closedPosition;
    bool* isOpen;

    //-------------------------------------------------------------------------
    // Sets the claw to the designated power level
    // power: The power level to set the claw to
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void SetClaw(double power);

    //-------------------------------------------------------------------------
    // Finds the current position of the claw
    // return: The current position of the claw encoders
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double GetPosition();

    //-------------------------------------------------------------------------
    // Checks if the claw is all the way open
    // return: True if the claw is all the way open, false if not
    // v1: Created the method - Nathan S, 2-31-22
    //-------------------------------------------------------------------------
    bool IsOpened();

    //-------------------------------------------------------------------------
    // Checks if the claw is all the way closed
    // return: True if the claw is at the top of its range, false if not
    // v1: Created the method - Nathan S, 2-31-22
    //-------------------------------------------------------------------------
    bool IsClosed();

public:
    //-------------------------------------------------------------------------
    // Builder class for the claw
    // v1: Created the class - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    class ClawBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // motorList: The motors on the claw
        // pistonList: The pistons on the claw
        // objectSensor: The sensor on the claw
        // clawPID: The PID controller in charge of the claw
        // minPosition: The minimum position of the claw in encoder counts
        // maxPosition: The maximum position of the claw in encoder counts
        // openPosition: The position of the claw when it is open
        // closedPosition: The position of the claw when it is closed
        //-------------------------------------------------------------------------
        std::list<pros::Motor*>* motorList;
        std::list<pros::ADIDigitalOut*>* pistonList;
        pros::ADIDigitalIn* objectSensor;
        PID* clawPID;
        double* minPosition;
        double* maxPosition;
        double* openPosition;
        double* closedPosition;

        //---------------------------------------------------------------------
        // Default constructor for the ClawBuilder class
        // v1: Created the constructor - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the ClawBuilder class
        // v1: Created the destructor - Nathan S, 4-11-22
        //---------------------------------------------------------------------
        ~ClawBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the build
        // motor: The motor being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithMotor(pros::Motor* motor);

        //---------------------------------------------------------------------
        // Wither method to add a piston to the build
        // piston: The piston being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithPiston(pros::ADIDigitalOut* piston);

        //---------------------------------------------------------------------
        // Wither method to add a sensor to the build
        // sensor: The sensor being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-22-22
        //---------------------------------------------------------------------
        ClawBuilder* WithSensor(pros::ADIDigitalIn* sensor);

        //---------------------------------------------------------------------
        // Wither method to add a pid controller to the build
        // pid: The PID controller being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithPID(PID* pid);

        //---------------------------------------------------------------------
        // Wither method to add a minimum position to the build
        // minPosition: The minimum position being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithMinPosition(double minPosition);

        //---------------------------------------------------------------------
        // Wither method to add a maximum position to the build
        // maxPosition: The maximum position being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithMaxPosition(double maxPosition);

        //---------------------------------------------------------------------
        // Wither method to add an open position to the build
        // downPosition: The open position being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithOpenPosition(double openPosition);

        //---------------------------------------------------------------------
        // Wither method to add a closed position to the build
        // closedPosition: The closed position being added
        // return: The ClawBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        ClawBuilder* WithClosedPosition(double closedPosition);

        //---------------------------------------------------------------------
        // Builder method for the builder class
        // return: The claw
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        Claw* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for the Claw class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    Claw(ClawBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for the Claw class
    // v1: Created the destructor - Nathan S, 4-11-22
    //-------------------------------------------------------------------------
    ~Claw();

    //-------------------------------------------------------------------------
    // Initializes the claw
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Opens the claw
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Open();

    //-------------------------------------------------------------------------
    // Closes the claw
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Close();

    //-------------------------------------------------------------------------
    // Holds the claw at its current position
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Sets the claw to the open position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetOpen();

    //-------------------------------------------------------------------------
    // Sets the claw to the closed position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetClosed();

    //-------------------------------------------------------------------------
    // Toggles the position of the claw between open and closed
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void TogglePosition();

    //-------------------------------------------------------------------------
    // Runs the claw to grab any objects it sees
    // v1: Created the method - Nathan S, 4-22-22
    //-------------------------------------------------------------------------
    void GrabObject();

    //-------------------------------------------------------------------------
    // Checks if the claw has an object
    // return: True if the claw has an object, false if not
    // v1: Created the method - Nathan S, 4-22-22
    //-------------------------------------------------------------------------
    bool HasObject();
};

#endif