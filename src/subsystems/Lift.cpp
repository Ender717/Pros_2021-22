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
    return LiftConfig::leftLiftMotor.get_position();
}

float Lift::GetHeight()
{
    float angle = (5.0 * 3.1415 / 9.0) - (LiftConfig::leftLiftMotor.get_position() / 10.0 / 5.0 * LiftConfig::DEGREES_TO_RADIANS);
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
    
    PID armPID(6.3, 1.25, 0.73, 5.0, -127.0, 127.0, 80.0, GetHeight());
    armPID.SetTargetValue(inches);
    float height = GetHeight();
    float controlValue = armPID.GetControlValue(height);

    while(abs(inches - height) > 0.1 || controlValue > 1)
    {
        height = GetHeight();
        controlValue = armPID.GetControlValue(height);
        SetLift(controlValue);
        pros::delay(2);
    }
}

void Lift::SetPosition(float target)
{
    PID armPID(4.3, 0.15, 0.05, 0.0, -127.0, 127.0, 80.0, 0.0);
    armPID.SetTargetValue(target);
    float current = GetPosition();
    float controlValue = armPID.GetControlValue(current);

    while(abs(target - current) > 1.0 || controlValue > 1)
    {
        current = GetPosition();
        controlValue = armPID.GetControlValue(current);
        SetLift(controlValue);
        pros::delay(2);
    }
}