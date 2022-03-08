// Included libraries
#include "subsystems/Claw.h"

// Constructor definitions ----------------------------------------------------
Claw::Claw(bool startClosed)
{
    PID::PIDBuilder builder;
    clawPID = builder.WithKd(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();

    isClosed = startClosed;
    if(isClosed)
        clawPID.SetTargetValue(ClawConfig::CLOSED_POSITION);
    else
        clawPID.SetTargetValue(ClawConfig::OPEN_POSITION);
} 

// Public method definitions --------------------------------------------------
void Claw::Initialize()
{
    ClawConfig::clawMotor.tare_position();
    ClawConfig::clawMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

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
    bool inPosition = (isClosed && (position <= ClawConfig::CLOSED_POSITION)) ||
                      (!isClosed && (position >= ClawConfig::OPEN_POSITION));
    if(!inPosition && (!isClosed || (isClosed && HasGoal())))
    {
        float power = clawPID.GetControlValue(position);
        ClawConfig::clawMotor.move(power);
    }
}

bool Claw::IsClosed() const
{
    return isClosed;
}

bool Claw::HasGoal()
{
    bool hasGoal = false;
    if(ClawConfig::goalSensor.get_proximity() >= ClawConfig::GOAL_THRESHOLD)
        hasGoal = true;
    return hasGoal;
}