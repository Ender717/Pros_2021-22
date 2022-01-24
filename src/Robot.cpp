// Included libraries
#include "Robot.h"

// Constructor definitions ----------------------------------------------------
Robot::Robot()
{
    drive = new Drive();
}

// Public method definitions --------------------------------------------------
void Robot::Initialize()
{
    drive->Initialize();
}