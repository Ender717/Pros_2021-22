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
    float countsFromParallel = LiftConfig::leftLiftMotor.get_position() - LiftConfig::MIDDLE_POSITION;
    float angle = countsFromParallel / LiftConfig::COUNTS_PER_ROTATION * LiftConfig::DEGREES_TO_RADIANS;
    float height = LiftConfig::ARM_LENGTH * sin(angle);
    return height;
}