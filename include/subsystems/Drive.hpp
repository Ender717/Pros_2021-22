// Inclusion guard
#ifndef DRIVE_H
#define DRIVE_H

// Included libraries
#include "./main.h"
#include <list>
#include "./processes/PID.hpp"
#include "./processes/PositionCalculation.hpp"
    
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
    // leftMotorList: The list of motors being used by the left side of the drive
    // rightMotorList: The list of motors being used by the right side of the drive
    // trackingList: The list of tracking sensors on the drive
    // distancePID: The PID controller for distance
    // anglePID: The PID controller for angle
    // turnPID: The PID controller for turning
    // position: The position calculation system
    // taskInitialized: Whether a task has already been initialized or not
    // taskCompleted: Whether the assigned task is complete or not
    // timer: The amount of time elapsed during a task
    // startDistance: The distance a task started at from the target
    // startAngle: The difference in angle a task started at from the target
    //-------------------------------------------------------------------------
    std::list<pros::Motor> leftMotorList;
    std::list<pros::Motor> rightMotorList;
    std::list<pros::Rotation> trackingList;
    PID distancePID;
    PID anglePID;
    PID turnPID;
    PositionCalculation position;
    float wheelSize;
    bool taskInitialized;
    bool taskCompleted;
    int timer;
    float startDistance;
    float startAngle;

public:
    //-------------------------------------------------------------------------
    // This is a builder class for the drive subsystem
    // v1: Created the class - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    class DriveBuilder
    {
    public:
        //---------------------------------------------------------------------
        // Attributes:
        // leftMotorList: The list of motors being used by the left side of the drive
        // rightMotorList: The list of motors being used by the right side of the drive
        // trackingList: The list of tracking sensors (left-right-strafe)
        // distancePID: The PID controller for distance
        // anglePID: The PID controller for angle
        // turnPID: The PID controller for turning
        // position: The position calculation system
        // wheelSize: The size of the tracking wheels
        //---------------------------------------------------------------------
        std::list<pros::Motor> leftMotorList;
        std::list<pros::Motor> rightMotorList;
        std::list<pros::Rotation> trackingList;
        PID distancePID;
        PID anglePID;
        PID turnPID;
        PositionCalculation position;
        float wheelSize;

        //---------------------------------------------------------------------
        // Default constructor for the DriveBuilder class
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the left side of the drive build
        // motor: The motor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithLeftMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a motor to the right side of the drive build
        // motor: The motor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithRightMotor(pros::Motor motor);

        //---------------------------------------------------------------------
        // Wither method to add a tracking sensor to the drive build
        // sensor: The sensor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithTrackingSensor(pros::Rotation sensor);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for distance to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithDistancePID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for angle to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithAnglePID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for turning to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithTurnPID(PID pid);

        //---------------------------------------------------------------------
        // Wither method to add a position calculator to the build
        // position: The position calculation being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithPosition(PositionCalculation position);

        //---------------------------------------------------------------------
        // Wither method to add a wheel size to the build
        // wheelSize: The wheel size being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder WithWheelSize(float wheelSize);

        //---------------------------------------------------------------------
        // Builder method for the DriveBuilder
        // return: The drive
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Drive Build();
    };

    //-------------------------------------------------------------------------
    // Default constructor for the drive class
    // v1: Created the constructor - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    Drive();

    //-------------------------------------------------------------------------
    // Builder constructor for the drive class
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Drive(DriveBuilder builder);

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
    // Makes the drive turn to the target angle as a task
    // targetAngle: The target angle in degrees
    // power: The speed at which the drive will turn
    // v1: Created the method - Nathan S, 2-22-22
    //-------------------------------------------------------------------------
    void TurnToAngleTask(float targetAngle, float power);

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
    float GetX() const;

    //-------------------------------------------------------------------------
    // Gets the current y-coordinate of the drive
    // return: The y-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetY() const;

    //-------------------------------------------------------------------------
    // Gets the current angle of the drive
    // return: The angle of the drive in radians
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    float GetTheta() const;

    //-------------------------------------------------------------------------
    // Updates the position of the drive
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void UpdatePosition();
};

#endif