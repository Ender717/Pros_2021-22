// Included libraries
#include "subsystems/Carrier.hpp"

// CARRIER BUILDER

// Constructor definitions ----------------------------------------------------
Carrier::CarrierBuilder::CarrierBuilder()
{
    startAngle = 0.0;
    minAngle = -1.0;
    maxAngle = -1.0;
    startHeight = 0.0;
    minHeight = -1.0;
    maxHeight = -1.0;
    countsPerDegree = DBL_MIN;
    countsPerInch = DBL_MIN;
    armLength = DBL_MIN;
    downPosition = -DBL_MAX;
    upPosition = DBL_MAX;
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
    carrierPID = pid;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithStartAngle(double startAngle)
{
    this->startAngle = startAngle;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithMinAngle(double minAngle)
{
    this->minAngle = minAngle;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithMaxAngle(double maxAngle)
{
    this->maxAngle = maxAngle;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithStartHeight(double startHeight)
{
    this->startHeight = startHeight;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithMinHeight(double minHeight)
{
    this->minHeight = minHeight;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithMaxHeight(double maxHeight)
{
    this->maxHeight = maxHeight;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithCountsPerDegree(double countsPerDegree)
{
    this->countsPerDegree = countsPerDegree;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithCountsPerInch(double countsPerInch)
{
    this->countsPerInch = countsPerInch;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithArmLength(double armLength)
{
    this->armLength = armLength;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithDownPosition(double downPosition)
{
    this->downPosition = downPosition;
    return *this;
}

Carrier::CarrierBuilder Carrier::CarrierBuilder::WithUpPosition(double upPosition)
{
    this->upPosition = upPosition;
    return *this;
}

Carrier Carrier::CarrierBuilder::Build()
{
    return Carrier(*this);
}

// CARRIER

// Constructor definitions ----------------------------------------------------
Carrier::Carrier()
{
    PID::PIDBuilder builder;
    carrierPID = builder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();

    startAngle = 0.0;
    startHeight = 0.0;
    countsPerDegree = 10.0;
    countsPerInch = 10.0;
    armLength = 10.0;
    minPosition = -DBL_MAX;
    maxPosition = DBL_MAX;
}

Carrier::Carrier(CarrierBuilder builder)
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
    this->carrierPID = builder.carrierPID;
    this->startAngle = builder.startAngle;
    this->startHeight = builder.startHeight;
    this->countsPerDegree = builder.countsPerDegree;
    this->countsPerInch = builder.countsPerInch;
    this->armLength = builder.armLength;
    this->downPosition = builder.downPosition;
    this->upPosition = builder.upPosition;

    // Set the minimum position
    if (builder.minAngle != -1.0)
        minPosition = AngleToPosition(builder.minAngle);
    else if (builder.minHeight != -1.0)
        minPosition = HeightToPosition(builder.minHeight);
    else
        minPosition = -DBL_MAX;

    // Set the maximum position
    if (builder.maxAngle != -1.0)
        maxPosition = AngleToPosition(builder.maxAngle);
    else if (builder.maxHeight != -1.0)
        maxPosition = HeightToPosition(builder.maxHeight);
    else
        maxPosition = DBL_MAX;
}

// Private method definitions -------------------------------------------------
void Carrier::SetCarrier(double power)
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
         iterator != motorList.end(); iterator++)
        iterator->move(power);
}

double Carrier::GetPosition()
{
    if (!motorList.empty())
        return motorList.front().get_position();
    else
        return 0.0;
}

double Carrier::AngleToPosition(double angle)
{
    double position = (angle * countsPerDegree) - (startAngle * countsPerDegree);
    return position;
}

double Carrier::HeightToPosition(double height)
{
    double position = (height * countsPerInch) - (startHeight * countsPerInch);
    position += armLength * sin(GetAngle());
    return position;
}

bool Carrier::AtBottom()
{
    return GetPosition() <= minPosition;
}

bool Carrier::AtTop()
{
    return GetPosition() >= maxPosition;
}

// Public method definitions --------------------------------------------------
void Carrier::Initialize()
{
    // Set the positions to 0
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    carrierPID.SetTargetValue(0.0);
}

void Carrier::Raise()
{
    if(!AtTop())
        SetCarrier(127.0);
    else
        SetCarrier(0.0);

    carrierPID.SetTargetValue(GetPosition());
}

void Carrier::Lower()
{
    if(!AtBottom())
        SetCarrier(-127.0);
    else
        SetCarrier(0.0);

    carrierPID.SetTargetValue(GetPosition());
}

void Carrier::HoldPosition()
{
    if (motorList.size() > 0)
    {
        if(!AtBottom() && !AtTop())
            SetCarrier(carrierPID.GetControlValue(GetPosition()));
        else
            SetCarrier(0.0);
    }
}

void Carrier::SetAngle(double targetAngle)
{
    double targetPosition = AngleToPosition(targetAngle);
    carrierPID.SetTargetValue(targetPosition);
}

void Carrier::SetHeight(double targetHeight)
{
    double targetPosition = HeightToPosition(targetHeight);
    carrierPID.SetTargetValue(targetPosition);
}

double Carrier::GetAngle()
{
    double angle = startAngle;
    if(countsPerDegree > 0.1)
        angle += GetPosition() / countsPerDegree;
    return angle;
}

double Carrier::GetHeight()
{
    double height = startHeight + (armLength * sin(GetAngle()));
    if(countsPerInch > 0.1)
        height += GetPosition() / countsPerInch;
    return height;
}

void Carrier::SetDown()
{
    carrierPID.SetTargetValue(downPosition);
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(true);
    }
    isDown = true;
}

void Carrier::SetUp()
{
    carrierPID.SetTargetValue(upPosition);
    for (std::list<pros::ADIDigitalOut>::iterator iterator = pistonList.begin(); 
        iterator != pistonList.end(); iterator++)
    {
        iterator->set_value(false);
    }
    isDown = false;
}

void Carrier::TogglePosition()
{
    if (isDown)
        SetUp();
    else
        SetDown();
}