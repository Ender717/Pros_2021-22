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
   // ROBOT_WIDTH: The distance between the left and right tracking wheels
   //--------------------------------------------------------------------------
   const float ROBOT_WIDTH = 15.0;

   //--------------------------------------------------------------------------
   // Private class member variables
   // oldLeftValue: The starting value of the left tracking wheel
   // oldRightValue: The starting value of the right tracking wheel
   // oldTheta: The starting angle of the robot
   // newLeftValue: The new value of the left tracking wheel
   // newRightPosition: The new value of the right tracking wheel
   // newTheta: The new angle of the robot
   // originX: The x-coordinate of the arc origin point
   // originY: The y-coordinate of the arc origin point
   // currentX: The current x-coordinate of the robot
   // currentY: The current y-coordinate of the robot
   // currentTheta: The current angle of the robot
   //--------------------------------------------------------------------------
   float oldLeftValue;
   float oldRightValue;
   float oldTheta;
   float newLeftValue;
   float newRightValue;
   float newTheta;
   float originX;
   float originY;
   float currentX;
   float currentY;
   float currentTheta;

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
   // Updates the values of the left and right tracking wheels
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   void UpdateValues(float leftValue, float rightValue, float angle);

   //--------------------------------------------------------------------------
   // Calculates the angle of the robot using the tracking wheels, and averages
   // that value with the inertial sensor reading
   //--------------------------------------------------------------------------
   void CalculateTheta(float inertialValue);
};

#endif
