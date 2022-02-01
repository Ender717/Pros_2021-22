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

float Lift::GetPosition()
{
    return (LiftConfig::leftLiftMotor.get_position() + LiftConfig::rightLiftMotor.get_position()) / 2.0;
}

float Lift::GetHeight()
{
    float countsFromParallel = LiftConfig::leftLiftMotor.get_position() - LiftConfig::MIDDLE_POSITION;
    float angle = countsFromParallel / LiftConfig::COUNTS_PER_ROTATION * 360.0 * LiftConfig::DEGREES_TO_RADIANS;
    float height = LiftConfig::ARM_LENGTH * sin(angle);
    return height;
}

void Lift::SetLift(float power)
{
    LiftConfig::leftLiftMotor.move(power);
    LiftConfig::rightLiftMotor.move(power);
}

void Lift::SetHeight(float inches)
{
    
    PID armPID(4.3, 0.85, 0.43, 5.0, -127.0, 127.0, 80.0, GetHeight());
    armPID.SetTargetValue(inches);
    float height = GetHeight();
    float controlValue = armPID.GetControlValue(height);

    while(abs(inches - height) > 0.1 || controlValue > 1)
    {
        height = GetHeight();
        controlValue = armPID.GetControlValue(height);
        SetLift(controlValue);
    }
}

void Lift::SetPosition(float target)
{
    PID armPID(6.3, 0.15, 0.05, 0.0, -127.0, 127.0, 80.0, 0.0);
    armPID.SetTargetValue(target);
    float current = GetPosition();
    float controlValue = armPID.GetControlValue(current);

    while(abs(target - current) > 1.0 || controlValue > 1)
    {
        current = GetPosition();
        controlValue = armPID.GetControlValue(current);
        SetLift(controlValue);
    }
}