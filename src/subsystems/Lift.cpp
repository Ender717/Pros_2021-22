// Included libraries
#include "subsystems/Lift.h"

// Constructor definitions ----------------------------------------------------
Lift::LiftBuilder::LiftBuilder()
{
    startAngle = -1.0;
    countsPerDegree = -1.0;
}

// Public method definitions --------------------------------------------------
Lift::LiftBuilder Lift::LiftBuilder::WithLeftMotor(pros::Motor motor)
{
    leftMotorList.push_back(motor);
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithRightMotor(pros::Motor motor)
{
    rightMotorList.push_back(motor);
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithPID(PID pid)
{
    liftPID = pid;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithTopAngle(float topAngle)
{
    this->topAngle = topAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithBottomAngle(float bottomAngle)
{
    this->bottomAngle = bottomAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithStartAngle(float startAngle)
{
    this->startAngle = startAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithCountsPerDegree(float countsPerDegree)
{
    this->countsPerDegree = countsPerDegree;
    return *this;
}

Lift Lift::LiftBuilder::Build()
{
    return Lift(*this);
}

// Constructor definitions ----------------------------------------------------
Lift::Lift()
{
    PID::PIDBuilder builder;
    liftPID = builder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();

    startAngle = 140.0;
}

Lift::Lift(LiftBuilder builder)
{
    // Set the left motors
    while(builder.leftMotorList.size() > 0)
    {
        this->leftMotorList.push_back(builder.leftMotorList.front());
        builder.leftMotorList.pop_front();
    }

    // Set the right motors
    while(builder.rightMotorList.size() > 0)
    {
        this->rightMotorList.push_back(builder.rightMotorList.front());
        builder.rightMotorList.pop_front();
    }

    // Set the PID controller
    this->liftPID = builder.liftPID;

    // Set the start angle
    if(builder.startAngle != -1.0)
        this->startAngle = builder.startAngle;
    else
        this->startAngle = 140.0;

    // Set the counts per degree
    if(builder.countsPerDegree != -1.0)
        this->countsPerDegree = builder.countsPerDegree;
    else
        this->countsPerDegree = 25.0;
}

// Private method definitions -------------------------------------------------
void Lift::SetLift(float power)
{
    for (std::list<pros::Motor>::iterator iterator = leftMotorList.begin(); 
        iterator != leftMotorList.end(); iterator++)
    {
        iterator->move(power);
    }
    for (std::list<pros::Motor>::iterator iterator = rightMotorList.begin(); 
        iterator != rightMotorList.end(); iterator++)
    {
        iterator->move(power);
    }
}

bool Lift::AtBottom()
{
    return GetAngle() <= bottomAngle;
}

bool Lift::AtTop()
{
    return GetAngle() >= topAngle;
}

float Lift::GetAngle()
{
    return startAngle + (leftMotorList.front().get_position() / countsPerDegree);
}

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    // Set the positions to 0
    for (std::list<pros::Motor>::iterator iterator = leftMotorList.begin(); 
        iterator != leftMotorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }
    for (std::list<pros::Motor>::iterator iterator = rightMotorList.begin(); 
        iterator != rightMotorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }
}

void Lift::Raise()
{
    //if(!AtTop())
    if(true)
        SetLift(127.0);
    else
        SetLift(0.0);
    liftPID.SetTargetValue(GetAngle());
}

void Lift::Lower()
{
    //if(!AtBottom())
    if(true)
        SetLift(-127.0);
    else
        SetLift(0.0);
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