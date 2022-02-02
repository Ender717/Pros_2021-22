// Included libraries
#include "subsystems/Intake.h"

// Constructor definitions ----------------------------------------------------
Intake::Intake() {}

// Public method definitions --------------------------------------------------
void Intake::Initialize()
{
    IntakeConfig::intakeMotor.tare_position();
}

float Intake::GetPosition()
{
    return IntakeConfig::intakeMotor.get_position();
}

void Intake::SetIntake(float power)
{
    IntakeConfig::intakeMotor.move(power);
}