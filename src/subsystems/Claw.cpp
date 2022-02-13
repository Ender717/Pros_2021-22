// Included libraries
#include "subsystems/Claw.h"

// Constructor definitions ----------------------------------------------------
Claw::Claw(bool startClosed) 
{
    isClosed = startClosed;
    hasGoal = false;
    clawPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 65.0, 0.0);
} 

// Public method definitions --------------------------------------------------
void Claw::SetClosed()
{
    clawPID.SetTargetValue(ClawConfig::CLOSED_POSITION);
    isClosed = true;
}

void Claw::SetOpen()
{
    clawPID.SetTargetValue(ClawConfig::OPEN_POSITION);
    isClosed = false;
}

void Claw::HoldPosition()
{
    float position = ClawConfig::clawMotor.get_position();
    bool inPosition = (isClosed && (position > ClawConfig::CLOSED_POSITION)) ||
                      (!isCLosed && (position < ClawConfig::OPEN_POSITION))
    if(!inPosition)
    {
        float power = clawPID.GetControlValue(position);
        ClawConfig::clawMotor.move(power);
    }
}

bool Claw::IsClosed()
{
    return isClosed;
}

bool Claw::HasGoal()
{
    return hasGoal;
}

void Claw::Initialize()
{
    ClawConfig::clawMotor.tare_position();
    ClawConfig::clawMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    if(isClosed)
        clawPID.SetTargetValue(ClawConfig::CLOSED_POSITION)
    else
        clawPID.SetTargetValue(ClawConfig::OPEN_POSITION)
}