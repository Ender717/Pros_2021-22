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
// v2: Refactored the class - Nathan S, 2-13-22
//-----------------------------------------------------------------------------
class Drive
{
private:
    //-------------------------------------------------------------------------
    // Private data members
    // distancePID: The PID controller for distance
    // anglePID: The PID controller for angle
    // turnPID: The PID controller for turning
    // position: The position calculation system
    //-------------------------------------------------------------------------
    PID distancePID;
    PID anglePID;
    PID turnPID;
    PositionCalculation position;

public:
    //-------------------------------------------------------------------------
    // Default constructor for the drive class
    // startX: The starting x-coordinate of the drive position
    // startY: The starting y-coordinate of the drive position
    // startTheta: The starting angle of the drive position
    // v1: Created the constructor - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    Drive(float startX, float startY, float startTheta);

    //-------------------------------------------------------------------------
    // Initializes the drive
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    void Initialize();

    //-------------------------------------------------------------------------
    // Sets the drive to the desired power levels
    // leftPower: The power being sent to the left side of the drive
    // rightPower: The power being sent to the right side of the drive
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetDrive(float leftPower, float rightPower);

    //-------------------------------------------------------------------------
    // Makes the drive move towards a target position
    // targetX: The target position's x-coordinate
    // targetY: The target position's y-coordinate
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void GoToPosition(float targetX, float targetY);

    //-------------------------------------------------------------------------
    // Makes the drive turn to the target angle
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void TurnToAngle(float targetAngle);

    //-------------------------------------------------------------------------
    // Sets the current x-coordinate of the drive
    // x: The new x-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetX(float x);

    //-------------------------------------------------------------------------
    // Sets the current y-coordinate of the drive
    // y: The new y-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetY(float y);

    //-------------------------------------------------------------------------
    // Sets the current angle of the drive
    // theta: The new angle of the drive in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetTheta(float theta);

    //-------------------------------------------------------------------------
    // Updates the position of the drive
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void UpdatePosition();
};

#endif