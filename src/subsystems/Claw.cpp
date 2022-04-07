// Included libraries
#include "subsystems/Claw.hpp"

// CLAW BUILDER

// Constructor definitions ----------------------------------------------------
Claw::ClawBuilder::ClawBuilder()
{
    maxPosition = DBL_MAX;
    minPosition = -DBL_MAX;
    openPosition = DBL_MAX;
    closedPosition = -DBL_MAX;
}

// Public method definitions --------------------------------------------------
Claw::ClawBuilder Claw::ClawBuilder::WithMotor(pros::Motor motor)
{
    motorList.push_back(motor);
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithPiston(pros::ADIDigitalOut piston)
{
    pistonList.push_back(piston);
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithPID(PID pid)
{
    clawPID = pid;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithMinPosition(double minPosition)
{
    this->minPosition = minPosition;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithMaxPosition(double maxPosition)
{
    this->maxPosition = maxPosition;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithOpenPosition(double openPosition)
{
    this->openPosition = openPosition;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithClosedPosition(double closedPosition)
{
    this->closedPosition = closedPosition;
    return *this;
}

Claw Claw::ClawBuilder::Build()
{
    return Claw(*this);
}

// CLAW

// Constructor definitions ----------------------------------------------------
Claw::Claw()
{
    PID::PIDBuilder builder;
    clawPID = builder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
    minPosition = -DBL_MAX;
    maxPosition = DBL_MAX;
    openPosition = DBL_MAX;
    closedPosition = -DBL_MAX;
}

Claw::Claw(ClawBuilder builder)
{
    // Set the motors
    for (std::list<pros::Motor>::iterator iterator = builder.motorList.begin(); 
         iterator != builder.motorList.end(); iterator++)
        this->motorList.push_back(*iterator);
    
    // Set the motors
    for (std::list<pros::ADIDigitalOut>::iterator iterator = builder.pistonList.begin(); 
         iterator != builder.pistonList.end(); iterator++)
        this->pistonList.push_back(*iterator);

    // Set the direct transfer variables
    this->clawPID = builder.clawPID;
    this->minPosition = builder.minPosition;
    this->maxPosition = builder.maxPosition;
    this->openPosition = builder.openPosition;
    this->closedPosition = builder.closedPosition;

    // Set non-builder defaults
    isOpen = false;
}

// Private method definitions -------------------------------------------------
void Claw::SetClaw(double power)
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
         iterator != motorList.end(); iterator++)
        iterator->move(power);
}

double Claw::GetPosition()
{
    if (!motorList.empty())
        return motorList.front().get_position();
    else
        return 0.0;
}

bool Claw::IsOpened()
{
    return GetPosition() <= minPosition;
}

bool Claw::IsClosed()
{
    return GetPosition() >= maxPosition;
}

// Public method definitions --------------------------------------------------
void Claw::Initialize()
{
    // Set the positions to 0
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    clawPID.SetTargetValue(0.0);
}

void Claw::Open()
{
    if(!IsOpened())
        SetClaw(127.0);
    else
        SetClaw(0.0);

    clawPID.SetTargetValue(GetPosition());
}

void Claw::Close()
{
    if(!IsClosed())
        SetClaw(-127.0);
    else
        SetClaw(0.0);

    clawPID.SetTargetValue(GetPosition());
}

void Claw::HoldPosition()
{
    if(!IsOpened() && !IsClosed())
        SetClaw(clawPID.GetControlValue(GetPosition()));
    else
        SetClaw(0.0);
}

void Claw::SetOpen()
{
    clawPID.SetTargetValue(openPosition);
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(true);
    }
    isOpen = true;
}

void Claw::SetClosed()
{
    clawPID.SetTargetValue(closedPosition);
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(false);
    }
    isOpen = false;
}

void Claw::TogglePosition()
{
    if (isOpen)
        SetClosed();
    else
        SetOpen();
}