// Included libraries
#include "subsystems/Claw.h"

// Constructor definitions ----------------------------------------------------
Claw::ClawBuilder::ClawBuilder()
{
    openPosition = -1;
    closedPosition = -1;
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
    this->clawPID = pid;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithOpenPosition(float openPosition)
{
    this->openPosition = openPosition;
    return *this;
}

Claw::ClawBuilder Claw::ClawBuilder::WithClosedPosition(float closedPosition)
{
    this->closedPosition = closedPosition;
    return *this;
}

Claw Claw::ClawBuilder::Build()
{
    return Claw(*this);
}

// Constructor definitions ----------------------------------------------------
Claw::Claw()
{
    PID::PIDBuilder builder;
    clawPID = builder.WithKd(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
    openPosition = 0.0;
    isClosed = true;
    clawPID.SetTargetValue(closedPosition);
}

Claw::Claw(ClawBuilder builder)
{
    // Get the motors
    while(builder.motorList.size() > 0)
    {
        this->motorList.push_back(builder.motorList.front());
        builder.motorList.pop_front();
    }
    
    // Get the pistons
    while(builder.pistonList.size() > 0)
    {
        this->pistonList.push_back(builder.pistonList.front());
        builder.pistonList.pop_front();
    }

    // Get the PID controller
    this->clawPID = builder.clawPID;

    // Get the up position
    if(builder.openPosition != -1.0)
        this->openPosition = builder.openPosition;
    else
        this->openPosition = 0.0;

    // Get the down position
    if(builder.closedPosition != -1.0)
        this->closedPosition = builder.closedPosition;
    else
        this->closedPosition = 0.0;

    // Initialize the position
    isClosed = false;
}

// Public method definitions --------------------------------------------------
void Claw::Initialize()
{
    // Initialize the motors
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    // Initialize the pistons
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(isClosed);
    }

    // Initialize the PID controller
    clawPID.SetTargetValue(closedPosition);
}

void Claw::SetClosed()
{
    // Set the pistons
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(true);
    }

    // Update the PID controller
    clawPID.SetTargetValue(closedPosition);

    // Update the position
    isClosed = true;
}

void Claw::SetOpen()
{
    // Set the pistons
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(false);
    }

    // Update the PID controller
    clawPID.SetTargetValue(openPosition);

    // Update the position
    isClosed = false;
}

void Claw::HoldPosition()
{
    if(motorList.size() > 0)
    {
        float position = motorList.front().get_position();
        bool inPosition = (isClosed && (position <= closedPosition)) ||
                        (!isClosed && (position >= openPosition));
        //if(!inPosition)
        if(true)
        {
            // Set the motors
            for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
                iterator != motorList.end(); iterator++)
            {
                iterator->move(clawPID.GetControlValue(position));
            }
        }
    }
}

bool Claw::IsClosed() const
{
    return isClosed;
}