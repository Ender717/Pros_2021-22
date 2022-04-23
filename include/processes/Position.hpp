// Inclusion Guard
#ifndef POSITION_HPP
#define POSITION_HPP

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages the position tracking system of the robot
// v1: Created the class - Nathan S, 9-24-21
//-----------------------------------------------------------------------------
class Position
{
private:
    //-------------------------------------------------------------------------
    // Hardware constants:
    // leftTrackingDistance: The left wheel's offset from the center
    // rightTrackingDistance: The right wheel's offset from the center
    // strafeTrackingDistance: The strafe wheel's offset from the center
    //-------------------------------------------------------------------------
    double* leftTrackingDistance;
    double* rightTrackingDistance;
    double* strafeTrackingDistance;

    //-------------------------------------------------------------------------
    // Current position:
    // currentX: The current x-coordinate
    // currentY: The current y-coordinate
    // currentTheta: The current angle
    //-------------------------------------------------------------------------
    double* currentX;
    double* currentY;
    double* currentTheta;

    //-------------------------------------------------------------------------
    // Previous position:
    // lastLeft: The previous position of the left tracking wheel
    // lastRight: The previous position of the right tracking wheel
    // lastStrafe: The previous position of the strafe tracking wheel
    // lastTheta: The previous angle of the robot
    //-------------------------------------------------------------------------
    double* lastLeft;
    double* lastRight;
    double* lastStrafe;
    double* lastTheta;

    //-------------------------------------------------------------------------
    // Reset position:
    // resetX: The x-coordinate at the last reset
    // resetY: The y-coordinate at the last reset
    // resetTheta: The angle at the last reset
    //-------------------------------------------------------------------------
    double* resetX;
    double* resetY;
    double* resetTheta;

    //-------------------------------------------------------------------------
    // Sets a reset position for the position tracker
    // v1: Created the method - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    void SetResetPosition();

public:
    //-------------------------------------------------------------------------
    // Builder class for the position calculation
    // v1: Created the class - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    class PositionBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Private data members:
        // leftTrackingDistance: The left wheel's offset from the center
        // rightTrackingDistance: The right wheel's offset from the center
        // strafeTrackingDistance: The strafe wheel's offset from the center
        // startX: The starting x-coordinate
        // startY: The starting y-coordinate
        // startTheta: The starting angle
        //---------------------------------------------------------------------
        double* leftTrackingDistance;
        double* rightTrackingDistance;
        double* strafeTrackingDistance;
        double* startX;
        double* startY;
        double* startTheta;

        //---------------------------------------------------------------------
        // Default constructor for the PositionBuilder class
        // v1: Created the constructor - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the PositionBuilder class
        // v1: Created the destructor - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        ~PositionBuilder();

        //---------------------------------------------------------------------
        // Wither method for the leftTrackingDistance attribute
        // leftTrackingDistance: The value to set leftTrackingDistance to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithLeftDistance(double leftTrackingDistance);

        //---------------------------------------------------------------------
        // Wither method for the rightTrackingDistance attribute
        // rightTrackingDistance: The value to set rightTrackingDistance to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithRightDistance(double rightTrackingDistance);

        //---------------------------------------------------------------------
        // Wither method for the strafeTrackingDistance attribute
        // strafeTrackingDistance: The value to set strafeTrackingDistance to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithStrafeDistance(double strafeTrackingDistance);

        //---------------------------------------------------------------------
        // Wither method for the startX attribute
        // startX: The value to set startX to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithStartX(double startX);

        //---------------------------------------------------------------------
        // Wither method for the startY attribute
        // startY: The value to set startY to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithStartY(double startY);

        //---------------------------------------------------------------------
        // Wither method for the startTheta attribute
        // startAngle: The starting angle (needs conversion to rads)
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-31-22
        //---------------------------------------------------------------------
        PositionBuilder* WithStartAngle(double startAngle);

        //---------------------------------------------------------------------
        // Constructs and returns a new Position from the builder
        // return: The new Position
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        Position* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for Position class
    // builder: The builder being used for construction
    // v1: Created the constructor - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    Position(PositionBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for Position class
    // v1: Created the destructor - Nathan S, 4-11-22
    //-------------------------------------------------------------------------
    ~Position();

    //-------------------------------------------------------------------------
    // Updates the current position of the system
    // leftValue: The left encoder value in inches
    // rightValue: The right encoder value in inches
    // strafeValue: The strafe encoder value in inches
    // v1: Created the method - Nathan S, 9-24-21
    // v2: Corrected the calculations - Nathan S, 1-9-22
    // v3: Reformatted the method - Nathan S, 1-26-22
    // Credit: Team 5225A - E-Bots Pilons
    //-------------------------------------------------------------------------
    void UpdatePosition(double leftValue, double rightValue, double strafeValue, double newTheta);

    //-------------------------------------------------------------------------
    // Sets the x-coordinate to the specified value
    // x: The new x-coordinate
    // v1: Created the method - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    void SetX(double x);

    //-------------------------------------------------------------------------
    // Sets the y-coordinate to the specified value
    // y: The new y-coordinate
    // v1: Created the method - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    void SetY(double y);

    //-------------------------------------------------------------------------
    // Sets the angle to the specified value
    // angle: The new angle
    // v1: Created the method - Nathan S, 3-31-22
    //-------------------------------------------------------------------------
    void SetAngle(double angle);

    //-------------------------------------------------------------------------
    // Sets the coordinates in the tracking system to a new position
    // x: The value to set the x-coordinate to
    // y: The value to set the y-coordinate to
    // theta: The value to set the angle to
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void SetPosition(double x, double y, double theta);

    //-------------------------------------------------------------------------
    // Returns the current x-coordinate of the robot
    // return: The current x-coordinate of the robot
    // v1: Created the method - Nathan S, 9-24-21
    //-------------------------------------------------------------------------
    double GetX() const;

    //-------------------------------------------------------------------------
    // Returns the current y-coordinate of the robot
    // return: The current y-coordinate of the robot
    // v1: Created the method - Nathan S, 9-24-21
    //-------------------------------------------------------------------------
    double GetY() const;

    //-------------------------------------------------------------------------
    // Returns the current angle of the robot
    // return: The current angle of the robot in rads
    // v1: Created the method - Nathan S, 9-24-21
    //-------------------------------------------------------------------------
    double GetTheta() const;

    //-------------------------------------------------------------------------
    // Returns the current angle of the robot
    // return: The current angle of the robot in degs
    // v1: Created the method - Nathan S, 9-24-21
    //-------------------------------------------------------------------------
    double GetAngle() const;
};

#endif
