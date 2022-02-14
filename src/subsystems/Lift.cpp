// Included libraries
#include "subsystems/Lift.h"

// Constructor definitions ----------------------------------------------------
Lift::Lift(float angle) : liftPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 70.0, 0.0)
{
    startAngle = angle;
}

// Private method definitions -------------------------------------------------
void Lift::SetLift(float power)
{
    LiftConfig::leftLiftMotor.move(power);
    LiftConfig::rightLiftMoto.move(power);
}

bool Lift::AtBottom()
{
    return LiftConfig::leftLiftMotor.get_position() <= LiftConfig::BOTTOM_POSITION;
}

bool Lift::AtTop()
{
    return LiftConfig::leftLiftMotor.get_position() >= LiftConfig::TOP_POSITION;
}

float Lift::GetAngle()
{
    return startAngle + (LiftConfig::leftLiftMotor.get_position() * LiftConfig::COUNTS_PER_DEGREE);
}

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    LiftConfig::leftLiftMotor.tare_position();
    LiftConfig::rightLiftMotor.tare_position();
    LiftConfig::leftLiftMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    LiftConfig::rightLiftMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

void Lift::Raise()
{
    if(!AtTop())
        SetLift(127.0);
    else
        SetLift(0.0);
    liftPID.SetTargetValue(GetAngle());
}

void Lift::Lower()
{
    if(!AtBottom())
        SetLift(-127.0);
    else
        SetLift(-127.0);
    liftPID.SetTargetValue(GetAngle());
}

void Lift::HoldPosition()
{
    if(!AtBottom() && !AtTop())
    {
        float controlValue = liftPID.GetControlValue(GetAngle());
        SetLift(controlValue);
    }
    else
        SetLift(0.0);
}

void Lift::SetAngle(float targetAngle)
{
    liftPID.SetTargetValue(targetAngle);

    while(abs(targetAngle - GetAngle()) > 0.1)
    {
        HoldPosition();
        pros::delay(5);
    }
}