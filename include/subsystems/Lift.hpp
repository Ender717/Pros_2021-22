// Inclusion guard
#ifndef LIFT_HPP
#define LIFT_HPP

// Included libraries
#include <list>
#include <cfloat>
#include "./processes/PID.hpp"
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the lift subsystem of the robot
// v1: Created the class - Nathan S, 1-30-22
// v2: Restructured the class - Nathan S, 2-14-22
// v3: Converted to generalized class - Nathan S, 3-13-22
//-----------------------------------------------------------------------------
class Lift
{
private:
    //-------------------------------------------------------------------------
    // Private data members:
    // motorList: The motors on the lift
    // liftPID: The PID controller in charge of the lift
    // startAngle: The starting angle of the lift in degrees
    // startHeight: The starting height of the lift in inches
    // countsPerDegree: The number of encoder counts per degree
    // countsPerInch: The number of encoder counts per inch
    // armLength: The length of the arm on the lift in inches
    // minPosition: The minimum position of the lift in encoder counts
    // maxPosition: The maximum position of the lift in encoder counts
    //-------------------------------------------------------------------------
    std::list<pros::Motor*>* leftMotorList;
    std::list<pros::Motor*>* rightMotorList;
    PID* liftPID;
    double* startAngle;
    double* startHeight;
    double* countsPerDegree;
    double* countsPerInch;
    double* armLength;
    double* minPosition;
    double* maxPosition;
    double* holdPosition;

    //-------------------------------------------------------------------------
    // Sets the lift to the designated power level
    // power: The power level to set the lift to
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    void SetLift(double power);

    //-------------------------------------------------------------------------
    // Sets half the lift to the designated power level
    // power: The power level to set the lift to
    // v1: Created the method - Nathan S, 4-19-22
    //-------------------------------------------------------------------------
    void SetHalfLift(double power);

    //-------------------------------------------------------------------------
    // Finds the current position of the lift
    // return: The current position of the lift encoders
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    double GetPosition();

    //-------------------------------------------------------------------------
    // Converts an angle in degrees to a position in encoder counts
    // return: The equivalent position
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    double AngleToPosition(double angle);

    //-------------------------------------------------------------------------
    // Converts a height in inches to a position in encoder counts
    // return: The equivalent position
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    double HeightToPosition(double height);

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

public:
    //-------------------------------------------------------------------------
    // Builder class for the lift
    // v1: Created the class - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    class LiftBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // motorList: The motors on the lift
        // liftPID: The PID controller in charge of the lift
        // minPosition: The minimum position of the lift in encoder counts
        // maxPosition: The maximum position of the lift in encoder counts
        // startAngle: The starting angle of the lift in degrees
        // minAngle: The minimum angle of the lift in degrees
        // maxAngle: The maximum angle of the lift in degrees
        // startHeight: The starting height of the lift in inches
        // minHeight: The minimum height of the lift in inches
        // maxHeight: The maximum height of the lift in inches
        // countsPerDegree: The number of encoder counts per degree
        // countsPerInch: The number of encoder counts per inch
        // armLength: The length of the arm on the lift in inches
        //-------------------------------------------------------------------------
        std::list<pros::Motor*>* leftMotorList;
        std::list<pros::Motor*>* rightMotorList;
        PID* liftPID;
        double* startAngle;
        double* minAngle;
        double* maxAngle;
        double* startHeight;
        double* minHeight;
        double* maxHeight;
        double* countsPerDegree;
        double* countsPerInch;
        double* armLength;

        //---------------------------------------------------------------------
        // Default constructor for the LiftBuilder class
        // v1: Created the constructor - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the LiftBuilder class
        // v1: Created the destructor - Nathan S, 4-12-22
        //---------------------------------------------------------------------
        ~LiftBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the build
        // motor: The motor being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithLeftMotor(pros::Motor* motor);

        //---------------------------------------------------------------------
        // Wither method to add a motor to the build
        // motor: The motor being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithRightMotor(pros::Motor* motor);

        //---------------------------------------------------------------------
        // Wither method to add a pid controller to the build
        // pid: The PID controller being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithPID(PID* pid);

        //---------------------------------------------------------------------
        // Wither method to add a starting angle to the build
        // startAngle: The starting angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithStartAngle(double startAngle);

        //---------------------------------------------------------------------
        // Wither method to add a minimum angle to the build
        // minAngle: The minimum angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithMinAngle(double minAngle);

        //---------------------------------------------------------------------
        // Wither method to add a maximum angle to the build
        // maxAngle: The maximum angle being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithMaxAngle(double maxAngle);

        //---------------------------------------------------------------------
        // Wither method to add a starting height to the build
        // startHeight: The starting height being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithStartHeight(double startHeight);

        //---------------------------------------------------------------------
        // Wither method to add a minimum height to the build
        // minHeight: The minimum height being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithMinHeight(double minHeight);

        //---------------------------------------------------------------------
        // Wither method to add a maximum height to the build
        // maxHeight: The maximum height being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithMaxHeight(double maxHeight);

        //---------------------------------------------------------------------
        // Wither method to add a number of counts per degree to the build
        // countsPerDegree: The number of counts per degree being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithCountsPerDegree(double countsPerDegree);

        //---------------------------------------------------------------------
        // Wither method to add a number of counts per inch to the build
        // countsPerInch: The number of counts per inch being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithCountsPerInch(double countsPerInch);

        //---------------------------------------------------------------------
        // Wither method to add an arm length to the build
        // armLength: The arm length being added
        // return: The LiftBuilder for build chaining
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        LiftBuilder* WithArmLength(double armLength);

        //---------------------------------------------------------------------
        // Builder method for the builder class
        // return: The lift
        // v1: Created the method - Nathan S, 3-13-22
        //---------------------------------------------------------------------
        Lift* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for the Lift class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Lift(LiftBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for the Lift class
    // v1: Created the destructor - Nathan S, 4-12-22
    //-------------------------------------------------------------------------
    ~Lift();

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
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    void SetAngle(double targetAngle);

    //-------------------------------------------------------------------------
    // Sets the lift to the desired height
    // targetHeight: The target height in inches
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    void SetHeight(double targetHeight);

    //-------------------------------------------------------------------------
    // Calculates the current angle of the lift
    // return: The current angle of the lift in degrees
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    double GetAngle();

    //-------------------------------------------------------------------------
    // Calculates the current height of the lift
    // return: The current height of the lift in inches
    // v1: Created the method - Nathan S, 3-13-22
    //-------------------------------------------------------------------------
    double GetHeight();
};

#endif