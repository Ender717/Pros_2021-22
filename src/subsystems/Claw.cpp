// Included libraries
#include "subsystems/Claw.h"

// Constructor definitions ----------------------------------------------------
Claw::Claw(int n) {} 

// Public method definitions --------------------------------------------------
float Claw::GetPosition()
{
    return ClawConfig::clawMotor.get_position();
}

void Claw::SetClaw(float power)
{
    ClawConfig::clawMotor.move(power);
}

void Claw::SetClosed()
{
    PID clawPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 65.0, 0.0);
    clawPID.SetTargetValue(ClawConfig::CLOSED_POSITION);
    float current = ClawConfig::clawMotor.get_position();
    float controlValue = clawPID.GetControlValue(current);

    while(fabs(ClawConfig::CLOSED_POSITION - current) > 1 || controlValue > 1)
    {
        current = ClawConfig::clawMotor.get_position();
        controlValue = clawPID.GetControlValue(current);
        SetClaw(controlValue);
        pros::delay(2);
    }
    SetClaw(0.0);
}

void Claw::SetOpen()
{
    PID clawPID(3.5, 0.35, 0.1, 0.0, -125.0, 125.0, 85.0, 0.0);
    clawPID.SetTargetValue(ClawConfig::OPEN_POSITION);
    float current = ClawConfig::clawMotor.get_position();
    float controlValue = clawPID.GetControlValue(current);

    while(fabs(ClawConfig::OPEN_POSITION - current) > 1 || controlValue > 1)
    {
        current = ClawConfig::clawMotor.get_position();
        controlValue = clawPID.GetControlValue(current);
        SetClaw(controlValue);
        pros::delay(2);
    }
}

void Claw::Initialize()
{
    ClawConfig::clawMotor.tare_position();
    ClawConfig::clawMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}