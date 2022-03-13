// Included libraries
#include "subsystems/Lift.h"

// LIFT BUILDER

// Constructor definitions ----------------------------------------------------
Lift::LiftBuilder::LiftBuilder()
{
    startAngle = -1;
    minAngle = -1;
    maxAngle = -1;
    startHeight = -1;
    minHeight = -1;
    maxHeight = -1;
    countsPerDegree = -1;
    countsPerInch = -1;
    armLength = -1;
}

// Public method definitions --------------------------------------------------
Lift::LiftBuilder Lift::LiftBuilder::WithMotor(pros::Motor motor)
{
    motorList.push_back(motor);
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithPID(PID pid)
{
    liftPID = pid;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithStartAngle(double startAngle)
{
    this->startAngle = startAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithMinAngle(double minAngle)
{
    this->minAngle = minAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithMaxAngle(double maxAngle)
{
    this->maxAngle = maxAngle;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithStartHeight(double startHeight)
{
    this->startHeight = startHeight;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithMinHeight(double minHeight)
{
    this->minHeight = minHeight;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithMaxHeight(double maxHeight)
{
    this->maxHeight = maxHeight;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithCountsPerDegree(double countsPerDegree)
{
    this->countsPerDegree = countsPerDegree;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithCountsPerInch(double countsPerInch)
{
    this->countsPerInch = countsPerInch;
    return *this;
}

Lift::LiftBuilder Lift::LiftBuilder::WithArmLength(double armLength)
{
    this->armLength = armLength;
    return *this;
}

Lift Lift::LiftBuilder::Build()
{
    return Lift(*this);
}

// LIFT

// Constructor definitions ----------------------------------------------------
Lift::Lift()
{
    PID::PIDBuilder builder;
    liftPID = builder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();

    startAngle = 0.0;
    startHeight = 0.0;
    countsPerDegree = 10.0;
    countsPerInch = 10.0;
    armLength = 10.0;
    minPosition = -DBL_MAX;
    maxPosition = DBL_MAX;
}

Lift::Lift(LiftBuilder builder)
{
    // Set the motors
    for (std::list<pros::Motor>::iterator iterator = builder.motorList.begin(); 
         iterator != builder.motorList.end(); iterator++)
        this->motorList.push_back(*iterator);

    // Set the PID controller
    this->liftPID = builder.liftPID;

    // Set the starting angle
    if (builder.startAngle != -1)
        this->startAngle = builder.startAngle;
    else
        this->startAngle = 0.0;
    
    // Set the starting height
    if (builder.startHeight != -1)
        this->startHeight = builder.startHeight;
    else
        this->startHeight = 0.0;
    
    // Set the number of counts per degree
    if (builder.countsPerDegree != -1)
        this->countsPerDegree = builder.countsPerDegree;
    else
        this->countsPerDegree = DBL_MIN;

    // Set the number of counts per inch
    if (builder.countsPerInch != -1)
        this->countsPerInch = builder.countsPerInch;
    else
        this->countsPerInch = DBL_MIN;

    // Set the arm length
    if (builder.armLength != -1)
        this->armLength = builder.armLength;
    else
        this->armLength = DBL_MIN;

    // Set the minimum position
    if (builder.minAngle != -1)
        minPosition = AngleToPosition(builder.minAngle);
    else if (builder.minHeight != -1)
        minPosition = HeightToPosition(builder.minHeight);
    else
        minPosition = -DBL_MAX;

    // Set the maximum position
    if (builder.maxAngle != -1)
        maxPosition = AngleToPosition(builder.maxAngle);
    else if (builder.maxHeight != -1)
        maxPosition = HeightToPosition(builder.maxHeight);
    else
        maxPosition = DBL_MAX;
}

// Private method definitions -------------------------------------------------
void Lift::SetLift(float power)
{
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
         iterator != motorList.end(); iterator++)
        iterator->move(power);
}

double Lift::GetPosition()
{
    return motorList.front().get_position();
}

double Lift::AngleToPosition(double angle)
{
    double position = (angle * countsPerDegree) - (startAngle * countsPerDegree)
    return position;
}

double Lift::HeightToPosition(double height)
{
    double position = (height * countsPerInch) - (startHeight * countsPerInch);
    position += armLength * sin(GetAngle());
    return position;
}

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    // Set the positions to 0
    for (std::list<pros::Motor>::iterator iterator = motorList.begin(); 
        iterator != motorList.end(); iterator++)
    {
        iterator->tare_position();
        iterator->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    liftPID.SetTargetValue(0.0);
}

void Lift::Raise()
{
    if(!AtTop())
        SetLift(127.0);
    else
        SetLift(0.0);

    liftPID.SetTargetValue(GetPosition());
}

void Lift::Lower()
{
    if(!AtBottom())
        SetLift(-127.0);
    else
        SetLift(0.0);

    liftPID.SetTargetValue(GetPosition());
}

void Lift::HoldPosition()
{
    if(!AtBottom() && !AtTop())
        SetLift(liftPID.GetControlValue(GetPosition()));
    else
        SetLift(0.0);
}

void Lift::SetAngle(float targetAngle)
{
    double targetPosition = AngleToPosition(targetAngle);
    liftPID.SetTargetValue(targetPosition);
}

void Lift::SetHeight(float targetHeight)
{
    double targetPosition = HeightToPosition(targetHeight);
    liftPID.SetTargetValue(targetPosition);
}

double Lift::GetAngle()
{
    double angle = startAngle;
    if(countsPerDegree > 0.1)
        angle += GetPosition() / countsPerDegree;
    return angle;
}

double Lift::GetHeight()
{
    double height = startHeight + (armLength * sin(GetAngle()));
    if(countsPerInch > 0.1)
        height += GetPosition() / countsPerInch;
    return height;
}

bool Lift::AtBottom()
{
    return GetPosition() <= minPosition;
}

bool Lift::AtTop()
{
    return GetPosition() >= maxPosition;
}