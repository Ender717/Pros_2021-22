// Inclusion guard
#ifndef DRIVE_H
#define DRIVE_H

// Included libraries
#include "./main.h"
#include "./config/DriveConfig.h"
#include "./processes/PositionCalculation.h"
#include "./processes/PID.h"
    
//-----------------------------------------------------------------------------
// This class controls the behaviors of the drive
// v1: Created the class - Nathan S, 1-24-22
//-----------------------------------------------------------------------------
class Drive
{
private:
    //-------------------------------------------------------------------------
    // Calculates the angle between two points
    // startX: The starting x-coordinate
    // startY: The starting y-coordinate
    // endX: The ending x-coordinate
    // endY: The ending y-coordinate
    // return: The angle between the points
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    float CalculateAngle(float startX, float startY, float endX, float endY);

    //-------------------------------------------------------------------------
    // Calculates the distance between two points
    // startX: The starting x-coordinate
    // startY: The starting y-coordinate
    // endX: The ending x-coordinate
    // endY: The ending y-coordinate
    // return: The distance between the points
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    float CalculateDistance(float startX, float startY, float endX, float endY);

public:
    //-------------------------------------------------------------------------
    // Default constructor for the drive class
    // v1: Created the constructor - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    Drive();

    //-------------------------------------------------------------------------
    // Initializes the drive
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Temporary basic control function for driving forward and backward
    // inches: The distance to travel
    // position: The position tracking system
    // power: The power with which to move forward
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Added the positioning system - Nathan S, 1-26-22
    // v3: Added a power control - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void DriveStraight(float inches, float power, PositionCalculation& position);

    //-------------------------------------------------------------------------
    // Temporary basic control function for turning in place
    // degrees: The number of degrees to turn
    // position: The position tracking system
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Added the positioning system - Nathan S, 1-26-22
    // v3: Added a power control - Nathan S, 1-30-22
    //-------------------------------------------------------------------------
    void SpinTurn(float degrees, float power, PositionCalculation& position);

    //-------------------------------------------------------------------------
    // Runs the left side of the drive at the desired power
    // power: The power to run the motors at
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Made the method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void SetLeftDrive(float power);

    //-------------------------------------------------------------------------
    // Runs the right side of the drive at the desired power
    // power: The power to run the motors at
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Made the method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void SetRightDrive(float power);

    //-------------------------------------------------------------------------
    // Drives the robot from its current position to the specified coordinates
    // targetX: The target x-coordinate
    // targetY: The target y-coordinate
    // power: The maximum forward speed of the motion
    // reversed: Whether the motion is reversed or not
    // position: The position calculation system
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void DriveToPoint(float targetX, float targetY, float power, bool reversed, PositionCalculation& position);

    //-------------------------------------------------------------------------
    // Drives the robot from its current position through the specified coordinates
    // targetX: The target x-coordinate
    // targetY: The target y-coordinate
    // power: The speed at which to move through the coordinate
    // reversed: Whether the robot is going backward or not
    // position: The position tracking system
    // v1: Created the method - Nathan S, 1-24-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void DriveThroughPoint(float targetX, float targetY, float power, bool reversed, PositionCalculation& position);

    //-------------------------------------------------------------------------
    // Turns the robot to a specified angle
    // angle: The angle to turn the robot to
    // power: The maximum speed at which to turn
    // position: The position tracking system
    // v1: Created the method - Nathan S, 1-28-22
    //-------------------------------------------------------------------------
    void TurnToAngle(float angle, float power, PositionCalculation& position);

    //-------------------------------------------------------------------------
    // Turns the robot to face a specified point
    // targetX: The x-coordinate of the specified point
    // targetY: The y-coordinate of the specified point
    // power: The maximum speed at which to turn
    // position: The position tracking system
    // v1: Created the method - Nathan S, 1-28-22
    //-------------------------------------------------------------------------
    void TurnTowardsPoint(float targetX, float targetY, float power, PositionCalculation& position);
};

#endif