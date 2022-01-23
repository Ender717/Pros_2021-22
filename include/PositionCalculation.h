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
   // CENTER_DISTANCE: The distance between the center tracking wheel and the 
   //                  center of the robot
   //--------------------------------------------------------------------------
   const float LEFT_DISTANCE = 6.0625;
   const float RIGHT_DISTANCE = 6.0625;
   const float CENTER_DISTANCE = 5.00;

   //--------------------------------------------------------------------------
   // Private class member variables
   // oldLeftValue: The starting value of the left tracking wheel
   // oldRightValue: The starting value of the right tracking wheel
   // oldCenterValue: The starting value of the center tracking wheel
   // newLeftValue: The new value of the left tracking wheel
   // newRightPosition: The new value of the right tracking wheel
   // newCenterPosition: The new value of the center tracking wheel
   // oldTheta: The starting angle of the robot
   // oldX: The starting x-coordinate of the robot
   // oldY: The starting y-coordinate of the robot
   // currentX: The current x-coordinate of the robot
   // currentY: The current y-coordinate of the robot
   // currentTheta: The current angle of the robot
   // leftChange: The change in value of the left tracking wheel
   // rightChange: The change in value of the right tracking wheel
   // centerChange: The change in value of the center tracking wheel
   // thetaChange: The change in the angle of the robot
   //--------------------------------------------------------------------------
   float oldLeftValue;
   float oldRightValue;
   float oldCenterValue;
   float newLeftValue;
   float newRightValue;
   float newCenterValue;
   float oldX;
   float oldY;
   float oldTheta;
   float currentX;
   float currentY;
   float currentTheta;
   float leftChange;
   float rightChange;
   float centerChange;
   float thetaChange;


   //--------------------------------------------------------------------------
   // Updates the values of the left and right tracking wheels
   // v1: Created the method - Nathan S, 9-24-21
   //--------------------------------------------------------------------------
   void UpdateValues(float leftValue, float rightValue, float centerValue);

   //--------------------------------------------------------------------------
   // Calculates the angle of the robot using the tracking wheels, and averages
   // that value with the inertial sensor reading
   // v1: Created the method - Nathan S, 9-27-21
   //--------------------------------------------------------------------------
   void UpdateTheta(float inertialValue);

   //--------------------------------------------------------------------------
   // Calculates the position of the robot using the tracking wheels and the 
   // angle of the robot
   // v1: Created the method - Nathan S, 9-27-21
   //--------------------------------------------------------------------------
   void CalculatePosition();

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
   // Updates the current position of the system
   // leftValue: The current value of the left tracking wheel
   // rightValue: The current value of the right tracking wheel
   // centerValue: The current value of the center tracking wheel
   // inertialValue: The current value of the inertial sensor's z-axis
   // v1: Created the method - Nathan S, 9-24-21
   // v2: Corrected the calculations - Nathan S, 1-9-22
   //--------------------------------------------------------------------------
   void UpdatePosition(float leftValue, float rightValue, float centerValue,
      float inertialValue);

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
   float GetAngle();
};

#endif
