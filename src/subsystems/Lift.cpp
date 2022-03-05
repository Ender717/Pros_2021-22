// Included libraries
#include "subsystems/Lift.h"

// Constructor definitions ----------------------------------------------------
Lift::Lift(float angle) : liftPID(5.0, 0.3, 0.25, 0.0, -127.0, 127.0, 70.0, angle)
{
    startAngle = angle;
}

// Private method definitions -------------------------------------------------
void Lift::SetLift(float power)
{
    LiftConfig::leftLift1Motor.move(power);
    LiftConfig::leftLift2Motor.move(power);
    LiftConfig::rightLift1Motor.move(power);
    LiftConfig::rightLift2Motor.move(power);
}

bool Lift::AtBottom()
{
    return GetAngle() <= LiftConfig::BOTTOM_POSITION;
}

bool Lift::AtTop()
{
    return GetAngle() >= LiftConfig::TOP_POSITION;
}

float Lift::GetAngle()
{
    return startAngle + (LiftConfig::leftLift1Motor.get_position() / LiftConfig::COUNTS_PER_DEGREE);
}

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    // Set the positions to 0
    LiftConfig::leftLift1Motor.tare_position();
    LiftConfig::leftLift2Motor.tare_position();
    LiftConfig::rightLift1Motor.tare_position();
    LiftConfig::rightLift2Motor.tare_position();

    // Set the brake modes to brake
    LiftConfig::leftLift1Motor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    LiftConfig::leftLift2Motor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    LiftConfig::rightLift1Motor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    LiftConfig::rightLift2Motor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
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

void Lift::SetTargetAngle(float targetAngle)
{
    liftPID.SetTargetValue(targetAngle);
}