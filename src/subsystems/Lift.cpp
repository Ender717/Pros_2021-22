// Included libraries
#include "subsystems/Lift.h"

// Constructor definitions ----------------------------------------------------
Lift::Lift() {};

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    LiftConfig::leftLiftMotor.tare_position();
    LiftConfig::rightLiftMotor.tare_position();
}

float Lift::GetHeight()
{
    
}