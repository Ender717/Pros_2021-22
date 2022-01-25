// Inclusion guard
#ifndef DRIVE_H
#define DRIVE_H

// Included libraries
#include "main.h"
#include "PositionCalculation.h"
#include "PID.h"

//-----------------------------------------------------------------------------
// This namespace controls the drive subsystem of the robot
// v1: Created the class - Nathan S, 1-23-22
//-----------------------------------------------------------------------------
namespace Drive
{
    //-------------------------------------------------------------------------
    // Constants
    // TRACKING_WHEEL_SIZE: The diameter of the tracking wheels
    // PI: The mathematical value for pi
    // COUNTS_PER_ROTATION: The number of encoder counts in one rotation of a 
    //                      rotation sensor
    // DEGREES_TO_RADIANS: The number to multiply degrees by to get radians
    // INERTIAL_TUNING: The inertial sensor tuning multiplier
    //-------------------------------------------------------------------------
    const float TRACKING_WHEEL_SIZE = 2.75;
    const float PI = 3.1415;
    const float COUNTS_PER_ROTATION = 36000.0;
    const float DEGREES_TO_RADIANS = 0.0174;
    const float INERTIAL_TUNING = 1.00696;

    //-------------------------------------------------------------------------
    // Ports
    // LEFT_REAR_DRIVE_PORT: The port the left rear drive motor is plugged into
    // LEFT_MIDDLE_DRIVE_PORT: The port the left middle drive motor is plugged into
    // LEFT_FRONT_DRIVE_PORT: The port the left front drive motor is plugged into
    // RIGHT_REAR_DRIVE_PORT: The port the right rear drive motor is plugged into
    // RIGHT_MIDDLE_DRIVE_PORT: The port the right middle drive motor is plugged into
    // RIGHT_FRONT_DRIVE_PORT: The port the right front drive motor is plugged into
    // LEFT_TRACKING_PORT: The port the left rotation sensor is plugged into
    // RIGHT_TRACKING_PORT: The port the right rotation sensor is plugged into
    // STRAFE_TRACKING_PORT: The port the strafe rotation sensor is plugged into
    // INERTIAL_PORT: The port the inertial sensor is plugged into
    //-------------------------------------------------------------------------
    const int LEFT_REAR_DRIVE_PORT = 13;
    const int LEFT_MIDDLE_DRIVE_PORT = 12;
    const int LEFT_FRONT_DRIVE_PORT = 11;
    const int RIGHT_REAR_DRIVE_PORT = 3;
    const int RIGHT_MIDDLE_DRIVE_PORT = 2;
    const int RIGHT_FRONT_DRIVE_PORT = 1;
    const int LEFT_TRACKING_PORT = 14;
    const int RIGHT_TRACKING_PORT = 4;
    const int STRAFE_TRACKING_PORT = 5;
    const int INERTIAL_PORT = 20;

    //-------------------------------------------------------------------------
    // Drive Motors
    // leftRearDriveMotor: The motor positioned at the left rear of the drive
    // leftMiddleDriveMotor: The motor positioned at the left middle of the drive
    // leftFrontDriveMotor: The motor positioned at the left front of the drive
    // rightRearDriveMotor: The motor positioned at the right rear of the drive
    // rightMiddleDriveMotor: The motor positioned at the right center of the drive
    // rightRearDriveMotor: The motor positioned at the right front of the drive
    //-------------------------------------------------------------------------
    extern pros::Motor leftRearDriveMotor;
    extern pros::Motor leftMiddleDriveMotor;
    extern pros::Motor leftFrontDriveMotor;
    extern pros::Motor rightRearDriveMotor;
    extern pros::Motor rightMiddleDriveMotor;
    extern pros::Motor rightFrontDriveMotor;

    //-------------------------------------------------------------------------
    // Drive Sensors
    // leftTrackingSensor: The rotation sensor on the left side of the drive
    // rightTrackingSensor: The rotation sensor on the right side of the drive
    // strafeTrackingSensor: The rotation sensor on the strafe wheel of the drive
    // inertialSensor: The inertial sensor on the drive
    //-------------------------------------------------------------------------
    extern pros::Rotation leftTrackingSensor;
    extern pros::Rotation rightTrackingSensor;
    extern pros::Rotation strafeTrackingSensor;
    extern pros::Imu inertialSensor;

    //-------------------------------------------------------------------------
    // Drive Processes
    // positionTracking: The position calculation process which tracks the
    //                   the coordinates of the robot
    // distancePID: The PID controller in charge of managing distance from the target
    // anglePID: The PID controller in charge of managing angle towards the target
    // turnPID: The PID controller in charge of managing turns
    //-------------------------------------------------------------------------
    extern PositionCalculation positionTracking;
    extern PID distancePID;
    extern PID anglePID;
    extern PID turnPID;

    //-------------------------------------------------------------------------
    // Calculates the angle between two points
    // startX: The starting x-coordinate
    // startY: The starting y-coordinate
    // endX: The ending x-coordinate
    // endY: The ending y-coordinate
    // return: The angle between the points
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    extern float CalculateAngle(float startX, float startY, float endX, float endY);

    //-------------------------------------------------------------------------
    // Calculates the distance between two points
    // startX: The starting x-coordinate
    // startY: The starting y-coordinate
    // endX: The ending x-coordinate
    // endY: The ending y-coordinate
    // return: The distance between the points
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    extern float CalculateDistance(float startX, float startY, float endX, float endY);

    //-------------------------------------------------------------------------
    // Initializes the drive
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void Initialize();

    //-------------------------------------------------------------------------
    // Temporary basic control function for driving forward and backward
    // inches: The distance to travel
    // reversed: The direction to travel in (false is forward, true is backward)
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    extern void DriveStraight(float inches, bool reversed);

    //-------------------------------------------------------------------------
    // Temporary basic control function for turning in place
    // degrees: The number of degrees to turn
    // v1: Created the method - Nathan S, 1-23-22
    //-------------------------------------------------------------------------
    extern void SpinTurn(float degrees);

    //-------------------------------------------------------------------------
    // Runs the left side of the drive at the desired power
    // power: The power to run the motors at
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Made the method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void SetLeftDrive(float power);

    //-------------------------------------------------------------------------
    // Runs the right side of the drive at the desired power
    // power: The power to run the motors at
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Made the method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void SetRightDrive(float power);

    //-------------------------------------------------------------------------
    // Drives the robot from its current position to the specified coordinates
    // targetX: The target x-coordinate
    // targetY: The target y-coordinate
    // reversed: Whether the motion is reversed or not
    // v1: Created the method - Nathan S, 1-23-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void DriveToPoint(float targetX, float targetY, bool reversed);

    //-------------------------------------------------------------------------
    // Drives the robot from its current position through the specified coordinates
    // targetX: The target x-coordinate
    // targetY: The target y-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    // v2: Allowed driving backward - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void DriveThroughPoint(float targetX, float targetY, float power, bool reversed);

    //-------------------------------------------------------------------------
    // Gets the current x-coordinate of the position tracking system
    // return: The robot's x-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern float GetX();

    //-------------------------------------------------------------------------
    // Gets the current y-coordinate of the position tracking system
    // return: The robot's y-coordinate
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern float GetY();

    //-------------------------------------------------------------------------
    // Gets the current angle of the position tracking system
    // return: The robot's angle
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern float GetTheta();

    //-------------------------------------------------------------------------
    // Updates the position tracking system
    // v1: Created the method - Nathan S, 1-23-21
    // v2: Made method public - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void UpdatePosition();

    //-------------------------------------------------------------------------
    // Sets the position of the tracking system
    // x: The x-coordinate to set the tracking system to
    // y: The y-coordinate to set the tracking system to
    // theta: The angle to set the tracking system to
    // v1: Created the method - Nathan S, 1-24-22
    //-------------------------------------------------------------------------
    extern void SetPosition(float x, float y, float theta);
};

#endif