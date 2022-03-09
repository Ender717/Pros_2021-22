// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::CarrierBuilder::CarrierBuilder()
{

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
    carrierPID = builder.carrierPID;

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
    carrierPID.SetTargetValue(CarrierConfig::UP_POSITION);
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
    carrierPID.SetTargetValue(CarrierConfig::DOWN_POSITION);

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
    carrierPID.SetTargetValue(CarrierConfig::UP_POSITION);

    // Update the position
    isDown = false;
}

void Carrier::HoldPosition()
{
    if(motorList.size() > 0)
    {
        float position = motorList.front().get_position();
        bool inPosition = (isDown && (position <= CarrierConfig::DOWN_POSITION)) ||
                        (!isDown && (position >= CarrierConfig::UP_POSITION));
        if(!inPosition)
        {
            // Initialize the motors
            for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
                iterator != motorList.end(); iterator++)
            {
                iterator->move(carrierPID.GetControlValue(position));
            }
        }
    }
}

bool Carrier::IsDown() const
{
    return isDown;
}