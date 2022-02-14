// Included libraries
#include "subsystems/Intake.h"

// Constructor definitions ----------------------------------------------------
Intake::Intake(float speed) 
{
    intakeSpeed = speed;
}

// Public method definitions --------------------------------------------------
void Intake::Initialize()
{
    IntakeConfig::intakeMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

void Intake::Intake()
{
    IntakeConfig::intakeMotor.move(intakeSpeed);
}

void Intake::Outtake()
{
    IntakeConfig::intakeMotor.move(-intakeSpeed);
}

void Intake::Hold()
{
    IntakeConfig::intakeMotor.move(0.0);
}