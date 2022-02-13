// Included libraries
#include "subsystems/Intake.h"

// Constructor definitions ----------------------------------------------------
Intake::Intake(int n) {}

// Public method definitions --------------------------------------------------
void Intake::Initialize()
{
    IntakeConfig::intakeMotor.tare_position();
    IntakeConfig::intakeMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

float Intake::GetPosition()
{
    return IntakeConfig::intakeMotor.get_position();
}

void Intake::SetIntake(float power)
{
    IntakeConfig::intakeMotor.move(power);
}