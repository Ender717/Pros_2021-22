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
   //--------------------------------------------------------------------------
   // Hardware constants:
   // leftTrackingDistance: The left wheel's offset from the center
   // rightTrackingDistance: The right wheel's offset from the center
   // strafeTrackingDistance: The strafe wheel's offset from the center
   //--------------------------------------------------------------------------
   double leftTrackingDistance;
   double rightTrackingDistance;
   double strafeTrackingDistance;

   //--------------------------------------------------------------------------
   // Current position:
   // currentX: The current x-coordinate
   // currentY: The current y-coordinate
   // currentTheta: The current angle
   //--------------------------------------------------------------------------
   double currentX;
   double currentY;
   double currentTheta;

   //--------------------------------------------------------------------------
   // Previous position:
   // lastLeft: The previous position of the left tracking wheel
   // lastRight: The previous position of the right tracking wheel
   // lastStrafe: The previous position of the strafe tracking wheel
   // lastTheta: The previous angle of the robot
   //--------------------------------------------------------------------------
   double lastLeft;
   double lastRight;
   double lastStrafe;
   double lastTheta;

   //--------------------------------------------------------------------------
   // Reset position:
   // resetX: The x-coordinate at the last reset
   // resetY: The y-coordinate at the last reset
   // resetTheta: The angle at the last reset
   //--------------------------------------------------------------------------
   double resetX;
   double resetY;
   double resetTheta;

public:
   //--------------------------------------------------------------------------
   // Builder class for the position calculation
   // v1: Created the class - Nathan S, 3-31-22
   //--------------------------------------------------------------------------
   class PositionBuilder
   {

   };

   //--------------------------------------------------------------------------
   // Default constructor for Position class
   // v1: Created the constructor - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   Position();

   //--------------------------------------------------------------------------
   // Sets the coordinates in the tracking system to a new position
   // x: The value to set the x-coordinate to
   // y: The value to set the y-coordinate to
   // theta: The value to set the angle to
   // v1: Created the method - Nathan S, 1-24-22
   //--------------------------------------------------------------------------
   void SetPosition(double x, double y, double theta);

   //--------------------------------------------------------------------------
   // Updates the current position of the system
   // leftValue: The left encoder value in inches
   // rightValue: The right encoder value in inches
   // strafeValue: The strafe encoder value in inches
   // v1: Created the method - Nathan S, 9-24-21
   // v2: Corrected the calculations - Nathan S, 1-9-22
   // v3: Reformatted the method - Nathan S, 1-26-22
   // Credit: Team 5225A - E-Bots Pilons
   //--------------------------------------------------------------------------
   void UpdatePosition(double leftValue, double rightValue, double strafeValue);

   //--------------------------------------------------------------------------
   // Returns the current x-coordinate of the robot
   // return: The current x-coordinate of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   double GetX() const;

   //--------------------------------------------------------------------------
   // Returns the current y-coordinate of the robot
   // return: The current y-coordinate of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   double GetY() const;

   //--------------------------------------------------------------------------
   // Returns the current angle of the robot
   // return: The current angle of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   double GetTheta() const;
};

#endif
