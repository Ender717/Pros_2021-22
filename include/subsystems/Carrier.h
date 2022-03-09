// Inclusion guard
#ifndef CARRIER_H
#define CARRIER_H

// Included libraries
#include <list>
#include "./processes/PID.h"
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the carrier subsystem of the robot
// v1: Created the class - Nathan S, 1-29-22
// v2: Refactored the class for data management - Nathan S, 2-13-22
//-----------------------------------------------------------------------------
class Carrier
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // motorList: The list of motors
    // pistonList: The list of pistons
    // carrierPID: The PID controller in charge of the carrier
    // upPosition: The position the carrier rests at when it is up
    // downPosition: The position the carrier rests at when it is down
    // isDown: Whether the carrier is down or not
    //-------------------------------------------------------------------------
    std::list<pros::Motor> motorList;
    std::list<pros::ADIDigitalOut> pistonList;
    PID carrierPID;
    float upPosition;
    float downPosition;
    bool isDown;

public:
    //-------------------------------------------------------------------------
    // This is the builder class for the Carrier subsystem
    // v1: Created the class - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    class CarrierBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // motorList: The list of motors for the carrier
        // pistonList: The list of pistons for the carrier
        // carrierPID: The PID controller for the carrier
        // upPosition: The position the carrier rests at when it is up
        // downPosition: The position the carrier rests at when it is down
        //---------------------------------------------------------------------
        std::list<pros::Motor> motorList;
        std::list<pros::ADIDigitalOut> pistonList;
        PID carrierPID;
        float upPosition;
        float downPosition;

        //---------------------------------------------------------------------
        // Default constructor for the CarrierBuilder
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the carrier build
        // motor: The motor being added to the build
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a piston to the carrier build
        // piston: The piston being added to the build
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder WithPiston(pros::ADIDigitalOut piston);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller to the carrier build
        // pid: The PID controller being added to the build
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder WithPID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add an up position to the carrier build
        // upPosition: The upPosition being added to the build
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder WithUpPosition(float upPosition);

        //---------------------------------------------------------------------
        // Wither method to add a down position to the carrier build
        // downPosition: The downPosition being added to the build
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        CarrierBuilder WithDownPosition(float downPosition);

        //---------------------------------------------------------------------
        // Build method to construct the carrier
        // return: The carrier
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Carrier Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the Carrier class
    // startDown: Whether the carrier starts down or not
    // v1: Created the constructor - Nathan S, 1-29-22
    // v2: Added a parameter to control start position - Nathan S, 2-13-22
    // v3: Removed start position parameter for initialization - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Carrier();

    //-------------------------------------------------------------------------
    // Builder constructor for the Carrier class
    // builder: The CarrierBuilder
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Carrier(CarrierBuilder builder);

    //-------------------------------------------------------------------------
    // Initializes the carrier
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Sets the position of the Carrier to down
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void SetDown();

    //-------------------------------------------------------------------------
    // Sets the position of the Carrier to up
    // v1: Created the method - Nathan S, 1-29-22
    //-------------------------------------------------------------------------
    void SetUp();

    //-------------------------------------------------------------------------
    // Holds the position of the Carrier
    // v1: Created the method - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Checks if the carrier is down or not
    // return: True if the carrier is down, false if not
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    bool IsDown() const;
};

#endif