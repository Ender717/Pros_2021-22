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

void Lift::SetLift(float power)
{
    LiftConfig::leftLiftMotor.move(power);
    LiftConfig::rightLiftMotor.move(power);
}

void Lift::SetHeight(float inches)
{
    float height = GetHeight();
    PID armPID(4.3, 0.85, 0.43, 5.0, -power, power, (power / 1.5), height);
    armPID.SetTargetValue(targetAngle);
    float controlValue = armPID.GetControlValue(height);

    while(abs(inches - height) > 0.1 || controlValue > 1)
    {
        height = GetHeight();
        controlValue = armPID.GetControlValue(height);
        SetLift(controlValue);
    }
}