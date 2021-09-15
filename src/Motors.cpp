#include "Motors.h"

// Constructor definitions ----------------------------------------------------
Motors::Motors()
{

}

// Public method definitions --------------------------------------------------
void Motors::Initialize()
{
   motorList[0] = pros::Motor driveLeft1Motor(DRIVE_LEFT1);
   motorList[1] = pros::Motor driveLeft2Motor(DRIVE_LEFT2);
   motorList[2] = pros::Motor driveLeft3Motor(DRIVE_LEFT3);
   motorList[3] = pros::Motor driveLeft4Motor(DRIVE_LEFT4);
   motorList[4] = pros::Motor driveRight1Motor(DRIVE_RIGHT1);
   motorList[5] = pros::Motor driveRight2Motor(DRIVE_RIGHT2);
   motorList[6] = pros::Motor driveRight3Motor(DRIVE_RIGHT3);
   motorList[7] = pros::Motor driveRight4Motor(DRIVE_RIGHT4);
}