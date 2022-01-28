// Inclusion Guard
#ifndef POSITIONCALCULATION_H
#define POSITIONCALCULATION_H

//-----------------------------------------------------------------------------
// This class manages the position tracking system of the robot
// v1: Created the class - Nathan S, 9-24-21
//-----------------------------------------------------------------------------
class PositionCalculation
{
private:
   //--------------------------------------------------------------------------
   // Private class member constants
   // LEFT_DISTANCE: The distance between the left tracking wheel and the 
   //                center of the robot
   // RIGHT_DISTANCE: The distance between the right tracking wheel and the 
   //                 center of the robot
   // STRAFE_DISTANCE: The distance between the center tracking wheel and the 
   //                  center of the robot
   //--------------------------------------------------------------------------
   const float LEFT_DISTANCE = 6.0938;
   const float RIGHT_DISTANCE = 6.0938;
   const float STRAFE_DISTANCE = 1.50;

   //--------------------------------------------------------------------------
   // Private data members
   // currentX: The robot's current x-coordinate
   // currentY: The robot's current y-coordinate
   // currentTheta: The robot's current angle
   // lastLeft: The position of the left tracking wheel during the last cycle
   // lastRight: The position of the right tracking wheel during the last cycle
   // lastStrafe: The position of the strafe tracking wheel during the last cycle
   // lastTheta: The angle of the robot during the last cycle
   //--------------------------------------------------------------------------
   float currentX;
   float currentY;
   float currentTheta;
   float lastLeft;
   float lastRight;
   float lastStrafe;
   float lastTheta;

public:
   //--------------------------------------------------------------------------
   // Parameterized constructor for PositionCalculation class
   // startX: The initial x-position of the robot
   // startY: The initial y-position of the robot
   // startTheta: The initial angle of the robot
   // v1: Created the constructor - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   PositionCalculation(float startX, float startY, float startTheta);

   //--------------------------------------------------------------------------
   // Sets the coordinates in the tracking system to a new position
   // x: The value to set the x-coordinate to
   // y: The value to set the y-coordinate to
   // theta: The value to set the angle to
   // v1: Created the method - Nathan S, 1-24-22
   //--------------------------------------------------------------------------
   void SetPosition(float x, float y, float theta);

   //--------------------------------------------------------------------------
   // Updates the current position of the system
   // v1: Created the method - Nathan S, 9-24-21
   // v2: Corrected the calculations - Nathan S, 1-9-22
   // v3: Reformatted the method - Nathan S, 1-26-22
   // v4: Changed to an automatic data method instead of input - Nathan S, 1-28-22
   // Credit: Team 5225A - E-Bots Pilons
   //--------------------------------------------------------------------------
   void UpdatePosition();

   //--------------------------------------------------------------------------
   // Returns the current x-coordinate of the robot
   // return: The current x-coordinate of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   float GetX();

   //--------------------------------------------------------------------------
   // Returns the current y-coordinate of the robot
   // return: The current y-coordinate of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   float GetY();

   //--------------------------------------------------------------------------
   // Returns the current angle of the robot
   // return: The current angle of the robot
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   float GetTheta();
};

#endif
