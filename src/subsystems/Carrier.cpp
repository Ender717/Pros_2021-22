// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::CarrierBuilder::CarrierBuilder()
{
    upPosition = -1;
    downPosition = -1;
}

// Public method definitions --------------------------------------------------
Carrier::CarrierBuilder Carrier::CarrierBuilder::WithMotor(pros::Motor motor)
{
    motorList.push_back(motor);
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithPiston(pros::ADIDigitalOut piston)
{
    pistonList.push_back(piston);
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithPID(PID pid)
{
    this->carrierPID = pid;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithUpPosition(float upPosition)
{
    this->upPosition = upPosition;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithDownPosition(float downPosition)
{
    this->downPosition = downPosition;
    return *this;
}

Carrier Carrier::CarrierBuilder::Build()
{
    return Carrier(*this);
}

// Constructor definitions ----------------------------------------------------
Carrier::Carrier() 
{
    isDown = false;
}

Carrier::Carrier(CarrierBuilder builder)
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
    this->carrierPID = builder.carrierPID;

    // Get the up position
    if(builder.upPosition != -1.0)
        this->upPosition = builder.upPosition;
    else
        this->upPosition = 0.0;

    // Get the down position
    if(builder.downPosition != -1.0)
        this->downPosition = builder.downPosition;
    else
        this->downPosition = 0.0;

    // Initialize the position
    isDown = false;
}

// Public method definitions --------------------------------------------------
void Carrier::Initialize()
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
        iterator->set_value(isDown);
    }

    // Initialize the PID controller
    carrierPID.SetTargetValue(upPosition);
}

void Carrier::SetPower(float power)
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->move(power);
    }
}

void Carrier::SetDown()
{
    // Set the pistons
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(true);
    }

    // Update the PID controller
    carrierPID.SetTargetValue(downPosition);

    // Update the position
    isDown = true;
}

void Carrier::SetUp()
{
    // Set the pistons
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(false);
    }

    // Update the PID controller
    carrierPID.SetTargetValue(upPosition);

    // Update the position
    isDown = false;
}

void Carrier::HoldPosition()
{
    if(motorList.size() > 0)
    {
        float position = motorList.front().get_position();
        bool inPosition = (isDown && (position <= downPosition)) ||
                        (!isDown && (position >= upPosition));
        //if(!inPosition)
        if(true)
        {
            for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
                iterator != motorList.end(); iterator++)
            {
                iterator->move(carrierPID.GetControlValue(position));
            }
        }
        else
            for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
                iterator != motorList.end(); iterator++)
            {
                iterator->move(0.0);
            }
    }
}

bool Carrier::IsDown() const
{
    return isDown;
}