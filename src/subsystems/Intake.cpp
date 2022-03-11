// Included libraries
#include "subsystems/Intake.h"

// Constructor definitions ----------------------------------------------------
Intake::IntakeBuilder::IntakeBuilder()
{

}

// Public method definitions --------------------------------------------------
Intake::IntakeBuilder Intake::IntakeBuilder::WithMotor(pros::Motor motor)
{
    motorList.push_back(motor);
    return *this;
}

Intake::IntakeBuilder Intake::IntakeBuilder::WithPID(PID pid)
{
    intakePID = pid;
    return *this;
}

Intake Intake::IntakeBuilder::Build()
{
    return Intake(*this);
}

// Constructor definitions ----------------------------------------------------
Intake::Intake() 
{
    intakeSpeed = 127.0;
}

Intake::Intake(IntakeBuilder builder)
{
    // Set the motors
    while(builder.motorList.size() > 0)
    {
        this->motorList.push_back(builder.motorList.front());
        builder.motorList.pop_front();
    }

    // Set the PID controller
    this->intakePID = builder.intakePID;

    // Set the intake speed
    intakeSpeed = 127.0;
}

// Public method definitions --------------------------------------------------
void Intake::Initialize()
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }
}

void Intake::SetSpeed(float speed)
{
    intakeSpeed = speed;
}

void Intake::Suck()
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->move(intakeSpeed);
    }
}

void Intake::Blow()
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->move(-intakeSpeed);
    }
}

void Intake::Stop()
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->move(0.0);
    }
}