// Inclusion guard
#ifndef DRIVE_HPP
#define DRIVE_HPP

// Included libraries
#include <list>
#include "./processes/PID.hpp"
#include "./processes/Position.hpp"
#include "./main.h"
    
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
    // leftTrackingSensor: The left tracking sensor on the drive
    // rightTrackingSesnor: The right tracking sensor on the drive
    // strafeTrackingSensor: The strafe tracking sensor on the drive
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
    std::list<pros::Motor*>* leftMotorList;
    std::list<pros::Motor*>* rightMotorList;
    pros::Rotation* leftTrackingSensor;
    pros::Rotation* rightTrackingSensor;
    pros::Rotation* strafeTrackingSensor;
    pros::Imu* inertialSensor;
    PID* distancePID;
    PID* anglePID;
    PID* turnPID;
    Position* position;
    double* wheelSize;

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
        // leftTrackingSensor: The left tracking sensor
        // rightTrackingSensor: The right tracking sensor
        // strafeTrackingSensor: The strafe tracking sensor
        // distancePID: The PID controller for distance
        // anglePID: The PID controller for angle
        // turnPID: The PID controller for turning
        // position: The position calculation system
        // wheelSize: The size of the tracking wheels
        //---------------------------------------------------------------------
        std::list<pros::Motor*>* leftMotorList;
        std::list<pros::Motor*>* rightMotorList;
        pros::Rotation* leftTrackingSensor;
        pros::Rotation* rightTrackingSensor;
        pros::Rotation* strafeTrackingSensor;
        pros::Imu* inertialSensor;
        PID* distancePID;
        PID* anglePID;
        PID* turnPID;
        Position* position;
        double* wheelSize;

        //---------------------------------------------------------------------
        // Default constructor for the DriveBuilder class
        // v1: Created the constructor - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the DriveBuilder class
        // v1: Created the destructor - Nathan S, 4-11-22
        //---------------------------------------------------------------------
        ~DriveBuilder();

        //---------------------------------------------------------------------
        // Wither method to add a motor to the left side of the drive build
        // motor: The motor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithLeftMotor(pros::Motor* motor);

        //---------------------------------------------------------------------
        // Wither method to add a motor to the right side of the drive build
        // motor: The motor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithRightMotor(pros::Motor* motor);

        //---------------------------------------------------------------------
        // Wither method to add a left tracking sensor to the drive build
        // sensor: The sensor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithLeftTrackingSensor(pros::Rotation* sensor);

        //---------------------------------------------------------------------
        // Wither method to add a right tracking sensor to the drive build
        // sensor: The sensor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithRightTrackingSensor(pros::Rotation* sensor);

        //---------------------------------------------------------------------
        // Wither method to add a strafe tracking sensor to the drive build
        // sensor: The sensor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithStrafeTrackingSensor(pros::Rotation* sensor);

        //---------------------------------------------------------------------
        // Wither method to add an inertial sensor to the drive build
        // sensor: The sensor being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 4-22-22
        //---------------------------------------------------------------------
        DriveBuilder* WithInertialSensor(pros::Imu* sensor);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for distance to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithDistancePID(PID* pid);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for angle to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithAnglePID(PID* pid);

        //---------------------------------------------------------------------
        // Wither method to add a PID controller for turning to the build
        // pid: The PID controller being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithTurnPID(PID* pid);

        //---------------------------------------------------------------------
        // Wither method to add a position calculator to the build
        // position: The position calculation being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithPosition(Position* position);

        //---------------------------------------------------------------------
        // Wither method to add a wheel size to the build
        // wheelSize: The wheel size being added to the build
        // return: The DriveBuilder for build chaining
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        DriveBuilder* WithWheelSize(double wheelSize);

        //---------------------------------------------------------------------
        // Builder method for the DriveBuilder
        // return: The drive
        // v1: Created the method - Nathan S, 3-9-22
        //---------------------------------------------------------------------
        Drive* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for the drive class
    // v1: Created the constructor - Nathan S, 3-9-22
    //-------------------------------------------------------------------------
    Drive(DriveBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for the drive class
    // v1: Created the destructor - Nathan S, 4-11-22
    //-------------------------------------------------------------------------
    ~Drive();

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
    void SetDrive(double leftPower, double rightPower);

    //-------------------------------------------------------------------------
    // Drives straight forward a designated distance
    // distance: The distance being travelled
    // v1: Created the method - Nathan S, 3-30-22
    //-------------------------------------------------------------------------
    void DriveStraight(double distance, double angle);

    //-------------------------------------------------------------------------
    // Drives straight forward through a designated distance
    // distance: The distance being travelled
    // v1: Created the method - Nathan S, 3-30-22
    //-------------------------------------------------------------------------
    void DriveStraightThrough(double distance, double angle, double power);

    //-------------------------------------------------------------------------
    // Makes the drive turn to the target angle as a task
    // targetAngle: The target angle in degrees
    // v1: Created the method - Nathan S, 2-22-22
    //-------------------------------------------------------------------------
    void TurnToAngle(double targetAngle);

    //-------------------------------------------------------------------------
    // Sets the current x-coordinate of the drive
    // x: The new x-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetX(double x);

    //-------------------------------------------------------------------------
    // Sets the current y-coordinate of the drive
    // y: The new y-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetY(double y);

    //-------------------------------------------------------------------------
    // Sets the current angle of the drive
    // theta: The new angle of the drive in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetTheta(double theta);

    //-------------------------------------------------------------------------
    // Sets the current position of the drive
    // x: The new x-coordinate of the drive in inches
    // y: The new y-coordinate of the drive in inches
    // theta: The new angle of the drive in degrees
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void SetPosition(double x, double y, double theta);

    //-------------------------------------------------------------------------
    // Gets the current x-coordinate of the drive
    // return: The x-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    double GetX() const;

    //-------------------------------------------------------------------------
    // Gets the current y-coordinate of the drive
    // return: The y-coordinate of the drive in inches
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    double GetY() const;

    //-------------------------------------------------------------------------
    // Gets the current angle of the drive
    // return: The angle of the drive in radians
    // v1: Created the method - Nathan S, 2-14-22
    //-------------------------------------------------------------------------
    double GetTheta() const;

    //-------------------------------------------------------------------------
    // Updates the position of the drive
    // v1: Created the method - Nathan S, 2-13-22
    //-------------------------------------------------------------------------
    void UpdatePosition();
};

#endif