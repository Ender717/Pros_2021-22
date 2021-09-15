// Inclusion guard
#ifndef MOTORS_H
#define MOTORS_H

//-----------------------------------------------------------------------------
// This class defines all aspects of the motors on the robot
// v1: Created the class - Nathan S, 9-14-21
//-----------------------------------------------------------------------------
class Motors
{
private:
   static const int DRIVE_LEFT1 = 1;
   static const int DRIVE_LEFT2 = 2;
   static const int DRIVE_LEFT3 = 3;
   static const int DRIVE_LEFT4 = 4;
   static const int DRIVE_RIGHT1 = 10;
   static const int DRIVE_RIGHT2 = 9;
   static const int DRIVE_RIGHT3 = 8;
   static const int DRIVE_RIGHT4 = 7;
   static const int NUM_MOTORS = 8;

   motorList = pros::Motor[NUM_MOTORS];

public:
   //--------------------------------------------------------------------------
   // Default constructor for Motors class
   // v1: Created the constructor - Nathan S, 9-14-21
   //--------------------------------------------------------------------------
   Motors();

   //--------------------------------------------------------------------------
   // Initializes the motors
   // v1: Created the method - Nathan S, 9-14-21
   //--------------------------------------------------------------------------
   void Initialize();
};

#endif
