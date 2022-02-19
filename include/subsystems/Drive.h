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
// v2: Restructured the class - Nathan S, 2-13-22
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
    // taskInitialized: Whether a task has already been initialized or not
    // taskCompleted: Whether the assigned task is complete or not
    // timer: The amount of time elapsed during a task
    // startDistance: The distance a task started at from the target
    //-------------------------------------------------------------------------
    PID distancePID;
    PID anglePID;
    PID turnPID;
    PositionCalculation position;
    bool taskInitialized;
    bool taskCompleted;
    int timer;
    float startDistance;

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
    // power: The speed at which the robot moves to the target coordinate
    // v1: Created the method - Nathan S, 2-13-22
    // v2: Made the method work properly - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void GoToPosition(float targetX, float targetY, float power);

    //-------------------------------------------------------------------------
    // Makes the drive move towards a target position as a task
    // targetX: The target position's x-coordinate
    // targetY: The target position's y-coordinate
    // power: The speed at which the robot moves to the target coordinate
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void GoToPositionTask(float targetX, float targetY, float power);

    //-------------------------------------------------------------------------
    // Makes the drive turn to the target angle
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void TurnToAngle(float targetAngle);

    //-------------------------------------------------------------------------
    // Checks if the current task has been completed
    // return: True if the task is complete, false if not
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    bool TaskComplete();

    //-------------------------------------------------------------------------
    // Sets the drive to accept a new task
    // v1: Created the method - Nathan S, 2-18-22
    //-------------------------------------------------------------------------
    void NewTask();

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
    // Sets the current position of the drive
    // x: The new x-coordinate of the drive in inches
    // y: The new y-coordinate of the drive in inches
    // theta: The new angle of the drive in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetPosition(float x, float y, float theta);

    //-------------------------------------------------------------------------
    // Gets the current x-coordinate of the drive
    // return: The x-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetX();

    //-------------------------------------------------------------------------
    // Gets the current y-coordinate of the drive
    // return: The y-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetY();

    //-------------------------------------------------------------------------
    // Gets the current angle of the drive
    // return: The angle of the drive in radians
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetTheta();

    //-------------------------------------------------------------------------
    // Prints the current robot position to the brain screen
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void PrintPosition();

    //-------------------------------------------------------------------------
    // Updates the position of the drive
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void UpdatePosition();
};

#endif