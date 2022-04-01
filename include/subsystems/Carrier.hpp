// Inclusion guard
#ifndef CARRIER_HPP
#define CARRIER_HPP

// Included libraries
#include <list>
#include <cfloat>
#include "./processes/PID.hpp"
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the carrier subsystem of the robot
// v1: Created the class - Nathan S, 1-30-22
// v2: Refactored - Nathan S, 2-14-22
// v3: Converted to generalized class - Nathan S, 4-1-22
//-----------------------------------------------------------------------------
class Carrier
{
private:
    //-------------------------------------------------------------------------
    // Private data members:
    // motorList: The motors on the carrier
    // pistonList: The pistons on the carrier
    // carrierPID: The PID controller in charge of the carrier
    // startAngle: The starting angle of the carrier in degrees
    // startHeight: The starting height of the carrier in inches
    // countsPerDegree: The number of encoder counts per degree
    // countsPerInch: The number of encoder counts per inch
    // armLength: The length of the arm on the carrier in inches
    // minPosition: The minimum position of the carrier in encoder counts
    // maxPosition: The maximum position of the carrier in encoder counts
    // downPosition: The position of the carrier when it is down
    // upPosition: The position of the carrier when it is up
    // isDown: Whether the carrier is down or not
    //-------------------------------------------------------------------------
    std::list<pros::Motor> motorList;
    std::list<pros::ADIDigitalOut> pistonList;
    PID carrierPID;
    double startAngle;
    double startHeight;
    double countsPerDegree;
    double countsPerInch;
    double armLength;
    double minPosition;
    double maxPosition;
    double downPosition;
    double upPosition;
    bool isDown;

    //-------------------------------------------------------------------------
    // Sets the carrier to the designated power level
    // power: The power level to set the carrier to
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void SetCarrier(double power);

    //-------------------------------------------------------------------------
    // Finds the current position of the carrier
    // return: The current position of the carrier encoders
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double GetPosition();

    //-------------------------------------------------------------------------
    // Converts an angle in degrees to a position in encoder counts
    // return: The equivalent position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double AngleToPosition(double angle);

    //-------------------------------------------------------------------------
    // Converts a height in inches to a position in encoder counts
    // return: The equivalent position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double HeightToPosition(double height);

    //-------------------------------------------------------------------------
    // Checks if the carrier is at the bottom of its range
    // return: True if the carrier is at the bottom of its range, false if not
    // v1: Created the method - Nathan S, 2-31-22
    //-------------------------------------------------------------------------
    bool AtBottom();

    //-------------------------------------------------------------------------
    // Checks if the carrier is at the top of its range
    // return: True if the carrier is at the top of its range, false if not
    // v1: Created the method - Nathan S, 2-31-22
    //-------------------------------------------------------------------------
    bool AtTop();

public:
    //-------------------------------------------------------------------------
    // Builder class for the carrier
    // v1: Created the class - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    class CarrierBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // motorList: The motors on the carrier
        // pistonList: The pistons on the carrier
        // carrierPID: The PID controller in charge of the carrier
        // minPosition: The minimum position of the carrier in encoder counts
        // maxPosition: The maximum position of the carrier in encoder counts
        // startAngle: The starting angle of the carrier in degrees
        // minAngle: The minimum angle of the carrier in degrees
        // maxAngle: The maximum angle of the carrier in degrees
        // startHeight: The starting height of the carrier in inches
        // minHeight: The minimum height of the carrier in inches
        // maxHeight: The maximum height of the carrier in inches
        // countsPerDegree: The number of encoder counts per degree
        // countsPerInch: The number of encoder counts per inch
        // armLength: The length of the arm on the carrier in inches
        //-------------------------------------------------------------------------
        std::list<pros::Motor> motorList;
        std::list<pros::ADIDigitalOut> pistonList;
        PID carrierPID;
        double startAngle;
        double minAngle;
        double maxAngle;
        double startHeight;
        double minHeight;
        double maxHeight;
        double countsPerDegree;
        double countsPerInch;
        double armLength;
        double downPosition;
        double upPosition;

        //---------------------------------------------------------------------
        // Default constructor for the CarrierBuilder class
        // v1: Created the constructor - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the build
        // motor: The motor being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a piston to the build
        // piston: The piston being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithPiston(pros::ADIDigitalOut piston);

        //---------------------------------------------------------------------
        // Wither method to add a pid controller to the build
        // pid: The PID controller being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithPID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add a starting angle to the build
        // startAngle: The starting angle being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithStartAngle(double startAngle);

        //---------------------------------------------------------------------
        // Wither method to add a minimum angle to the build
        // minAngle: The minimum angle being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMinAngle(double minAngle);

        //---------------------------------------------------------------------
        // Wither method to add a maximum angle to the build
        // maxAngle: The maximum angle being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMaxAngle(double maxAngle);

        //---------------------------------------------------------------------
        // Wither method to add a starting height to the build
        // startHeight: The starting height being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithStartHeight(double startHeight);

        //---------------------------------------------------------------------
        // Wither method to add a minimum height to the build
        // minHeight: The minimum height being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMinHeight(double minHeight);

        //---------------------------------------------------------------------
        // Wither method to add a maximum height to the build
        // maxHeight: The maximum height being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithMaxHeight(double maxHeight);

        //---------------------------------------------------------------------
        // Wither method to add a number of counts per degree to the build
        // countsPerDegree: The number of counts per degree being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithCountsPerDegree(double countsPerDegree);

        //---------------------------------------------------------------------
        // Wither method to add a number of counts per inch to the build
        // countsPerInch: The number of counts per inch being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithCountsPerInch(double countsPerInch);

        //---------------------------------------------------------------------
        // Wither method to add an arm length to the build
        // armLength: The arm length being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithArmLength(double armLength);

        //---------------------------------------------------------------------
        // Wither method to add a down position to the build
        // downPosition: The down position being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithDownPosition(double downPosition);

        //---------------------------------------------------------------------
        // Wither method to add an up position to the build
        // upPosition: The up position being added
        // return: The CarrierBuilder for build chaining
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        CarrierBuilder WithUpPosition(double upPosition);

        //---------------------------------------------------------------------
        // Builder method for the builder class
        // return: The carrier
        // v1: Created the method - Nathan S, 4-1-22
        //---------------------------------------------------------------------
        Carrier Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the Carrier class
    // angle: The angle the carrier is starting at
    // v1: Created the constructor - Nathan S, 1-30-22
    // v2: Added an angle parameter - Nathan S, 2-14-22
    // v3: Changed angle to builder - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    Carrier();

    //-------------------------------------------------------------------------
    // Builder constructor for the Carrier class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    Carrier(CarrierBuilder builder);

    //-------------------------------------------------------------------------
    // Initializes the carrier
    // v1: Created the method - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Raises the carrier
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Raise();

    //-------------------------------------------------------------------------
    // Lowers the carrier
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void Lower();

    //-------------------------------------------------------------------------
    // Holds the carrier at its current position
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void HoldPosition();

    //-------------------------------------------------------------------------
    // Sets the carrier to the desired angle
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetAngle(double targetAngle);

    //-------------------------------------------------------------------------
    // Sets the carrier to the desired height
    // targetHeight: The target height in inches
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetHeight(double targetHeight);

    //-------------------------------------------------------------------------
    // Calculates the current angle of the carrier
    // return: The current angle of the carrier in degrees
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double GetAngle();

    //-------------------------------------------------------------------------
    // Calculates the current height of the carrier
    // return: The current height of the carrier in inches
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    double GetHeight();

    //-------------------------------------------------------------------------
    // Sets the carrier to the down position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetDown();

    //-------------------------------------------------------------------------
    // Sets the carrier to the up position
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void SetUp();

    //-------------------------------------------------------------------------
    // Toggles the position of the carrier between down and up
    // v1: Created the method - Nathan S, 4-1-22
    //-------------------------------------------------------------------------
    void TogglePosition();
};

#endif