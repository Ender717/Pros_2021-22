// Inclusion guard
#ifndef DRIVE_H
#define DRIVE_H

// Included libraries
#include "main.h"
#include "DriveConfig.h"
    
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

public:
    //-------------------------------------------------------------------------
    // Default constructor for the drive class
    // v1: Created the constructor - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    Drive();

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

    //-------------------------------------------------------------------------
    // Initializes the drive
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Temporary basic control function for driving forward and backward
    // inches: The distance to travel
    // reversed: The direction to travel in (false is forward, true is backward)
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    void DriveStraight(float inches, bool reversed);

    //-------------------------------------------------------------------------
    // Temporary basic control function for turning in place
    // degrees: The number of degrees to turn
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    void SpinTurn(float degrees);

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
    // reversed: Whether the motion is reversed or not
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void DriveToPoint(float targetX, float targetY, bool reversed);

    //-------------------------------------------------------------------------
    // Drives the robot from its current position through the specified coordinates
    // targetX: The target x-coordinate
    // targetY: The target y-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void DriveThroughPoint(float targetX, float targetY, float power, bool reversed);

    //-------------------------------------------------------------------------
    // Gets the current x-coordinate of the position tracking system
    // return: The robot's x-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    float GetX();

    //-------------------------------------------------------------------------
    // Gets the current y-coordinate of the position tracking system
    // return: The robot's y-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    float GetY();

    //-------------------------------------------------------------------------
    // Gets the current angle of the position tracking system
    // return: The robot's angle
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    float GetTheta();

    //-------------------------------------------------------------------------
    // Updates the position tracking system
    // v1: Created the method - Nathan S, 1-23-21
    // v2: Made method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void UpdatePosition();

    //-------------------------------------------------------------------------
    // Sets the position of the tracking system
    // x: The x-coordinate to set the tracking system to
    // y: The y-coordinate to set the tracking system to
    // theta: The angle to set the tracking system to
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void SetPosition(float x, float y, float theta);
};

#endif