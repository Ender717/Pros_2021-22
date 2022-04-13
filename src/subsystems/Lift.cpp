// Included libraries
#include "subsystems/Lift.hpp"

// LIFT BUILDER

// Constructor definitions ----------------------------------------------------
Lift::LiftBuilder::LiftBuilder()
{
    motorList = nullptr;
    liftPID = nullptr;
    startAngle = nullptr;
    minAngle = nullptr;
    maxAngle = nullptr;
    startHeight = nullptr;
    minHeight = nullptr;
    maxHeight = nullptr;
    countsPerDegree = nullptr;
    countsPerInch = nullptr;
    armLength = nullptr;
}

// Destructor definitions -----------------------------------------------------
Lift::LiftBuilder::~LiftBuilder()
{
    if (motorList != nullptr)
    {
        delete motorList;
        motorList = nullptr;
    }
    liftPID = nullptr;
    if (startAngle != nullptr)
    {
        delete startAngle;
        startAngle = nullptr;
    }
    if (minAngle != nullptr)
    {
        delete minAngle;
        minAngle = nullptr;
    }
    if (maxAngle != nullptr)
    {
        delete maxAngle;
        maxAngle = nullptr;
    }
    if (startHeight != nullptr)
    {
        delete startHeight;
        startHeight = nullptr;
    }
    if (minHeight != nullptr)
    {
        delete minHeight;
        minHeight = nullptr;
    }
    if (maxHeight != nullptr)
    {
        delete maxHeight;
        maxHeight = nullptr;
    }
    if (countsPerDegree != nullptr)
    {
        delete countsPerDegree;
        countsPerDegree = nullptr;
    }
    if (countsPerInch != nullptr)
    {
        delete countsPerInch;
        countsPerInch = nullptr;
    }
    if (armLength != nullptr)
    {
        delete armLength;
        armLength = nullptr;
    }
}

// Public method definitions --------------------------------------------------
Lift::LiftBuilder* Lift::LiftBuilder::WithMotor(pros::Motor* motor)
{
    if (motorList == nullptr)
        motorList = new std::list<pros::Motor*>();
    motorList->push_back(motor);
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithPID(PID* pid)
{
    liftPID = pid;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithStartAngle(double startAngle)
{
    if (this->startAngle == nullptr)
        this->startAngle = new double;
    *this->startAngle = startAngle;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithMinAngle(double minAngle)
{
    if (this->minAngle == nullptr)
        this->minAngle = new double;
    *this->minAngle = minAngle;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithMaxAngle(double maxAngle)
{
    if (this->maxAngle == nullptr)
        this->maxAngle = new double;
    *this->maxAngle = maxAngle;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithStartHeight(double startHeight)
{
    if (this->startHeight == nullptr)
        this->startHeight = new double;
    *this->startHeight = startHeight;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithMinHeight(double minHeight)
{
    if (this->minHeight == nullptr) 
        this->minHeight = new double;
    *this->minHeight = minHeight;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithMaxHeight(double maxHeight)
{
    if (this->maxHeight == nullptr)
        this->maxHeight = new double;
    *this->maxHeight = maxHeight;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithCountsPerDegree(double countsPerDegree)
{
    if (this->countsPerDegree == nullptr)
        this->countsPerDegree = new double;
    *this->countsPerDegree = countsPerDegree;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithCountsPerInch(double countsPerInch)
{
    if (this->countsPerInch == nullptr)
        this->countsPerInch = new double;
    *this->countsPerInch = countsPerInch;
    return this;
}

Lift::LiftBuilder* Lift::LiftBuilder::WithArmLength(double armLength)
{
    if (this->armLength == nullptr)
        this->armLength = new double;
    *this->armLength = armLength;
    return this;
}

Lift* Lift::LiftBuilder::Build()
{
    return new Lift(this);
}

// LIFT

// Constructor definitions ----------------------------------------------------
Lift::Lift(LiftBuilder* builder)
{
    // Initialize the pointers
    motorList = new std::list<pros::Motor*>();
    startAngle = new double;
    startHeight = new double;
    countsPerDegree = new double;
    countsPerInch = new double;
    armLength = new double;
    minPosition = new double;
    maxPosition = new double;

    // Set the motors
    if (builder->motorList != nullptr)
        for (std::list<pros::Motor*>::iterator iterator = builder->motorList->begin(); 
            iterator != builder->motorList->end(); iterator++)
            this->motorList->push_back(*iterator);

    // Set the PID controller
    this->liftPID = builder->liftPID;

    // Set the starting angle
    if (builder->startAngle != nullptr)
        *this->startAngle = *builder->startAngle;
    else
        *this->startAngle = 0.0;
    
    // Set the starting height
    if (builder->startHeight != nullptr)
        *this->startHeight = *builder->startHeight;
    else
        *this->startHeight = 0.0;
    
    // Set the number of counts per degree
    if (builder->countsPerDegree != nullptr)
        *this->countsPerDegree = *builder->countsPerDegree;
    else
        *this->countsPerDegree = DBL_MIN;

    // Set the number of counts per inch
    if (builder->countsPerInch != nullptr)
        *this->countsPerInch = *builder->countsPerInch;
    else
        *this->countsPerInch = DBL_MIN;

    // Set the arm length
    if (builder->armLength != nullptr)
        *this->armLength = *builder->armLength;
    else
        *this->armLength = DBL_MIN;

    // Set the minimum position
    if (builder->minAngle != nullptr)
        *minPosition = AngleToPosition(*builder->minAngle);
    else if (builder->minHeight != nullptr)
        *minPosition = HeightToPosition(*builder->minHeight);
    else
        *minPosition = -DBL_MAX;

    // Set the maximum position
    if (builder->maxAngle != nullptr)
        *maxPosition = AngleToPosition(*builder->maxAngle);
    else if (builder->maxHeight != nullptr)
        *maxPosition = HeightToPosition(*builder->maxHeight);
    else
        *maxPosition = DBL_MAX;
}

// Destructor definitions -----------------------------------------------------
Lift::~Lift()
{
    if (motorList != nullptr)
    {
        for (std::list<pros::Motor*>::iterator iterator = motorList->begin(); 
            iterator != motorList->end(); iterator++)
        {
            delete *iterator;
            *iterator = nullptr;
        }
        delete motorList;
        motorList = nullptr;
    }
    if (liftPID != nullptr)
    {
        delete liftPID;
        liftPID = nullptr;
    }
    if (startAngle != nullptr)
    {
        delete startAngle;
        startAngle = nullptr;
    }
    if (startHeight != nullptr)
    {
        delete startHeight;
        startHeight = nullptr;
    }
    if (countsPerDegree != nullptr)
    {
        delete countsPerDegree;
        countsPerDegree = nullptr;
    }
    if (countsPerInch != nullptr)
    {
        delete countsPerInch;
        countsPerInch = nullptr;
    }
    if (armLength != nullptr)
    {
        delete armLength;
        armLength = nullptr;
    }
    if (minPosition != nullptr)
    {
        delete minPosition;
        minPosition = nullptr;
    }
    if (maxPosition != nullptr)
    {
        delete maxPosition;
        maxPosition = nullptr;
    }
}

// Private method definitions -------------------------------------------------
void Lift::SetLift(double power)
{
    for (std::list<pros::Motor*>::iterator iterator = motorList->begin(); 
         iterator != motorList->end(); iterator++)
        (*iterator)->move(power);
}

double Lift::GetPosition()
{
    return motorList->front()->get_position();
}

double Lift::AngleToPosition(double angle)
{
    double position = (angle * *countsPerDegree) - (*startAngle * *countsPerDegree);
    return position;
}

double Lift::HeightToPosition(double height)
{
    double position = (height * *countsPerInch) - (*startHeight * *countsPerInch);
    position += *armLength * sin(GetAngle());
    return position;
}

bool Lift::AtBottom()
{
    return GetPosition() <= *minPosition;
}

bool Lift::AtTop()
{
    return GetPosition() >= *maxPosition;
}

// Public method definitions --------------------------------------------------
void Lift::Initialize()
{
    // Set the positions to 0
    for (std::list<pros::Motor*>::iterator iterator = motorList->begin(); 
        iterator != motorList->end(); iterator++)
    {
        (*iterator)->tare_position();
        (*iterator)->set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    liftPID->SetTargetValue(0.0);
}

void Lift::Raise()
{
    if(!AtTop())
        SetLift(60.0);
    else
        SetLift(0.0);

    liftPID->SetTargetValue(GetPosition());
}

void Lift::Lower()
{
    if(!AtBottom())
        SetLift(-60.0);
    else
        SetLift(0.0);

    liftPID->SetTargetValue(GetPosition());
}

void Lift::HoldPosition()
{
    if(!AtBottom() && !AtTop())
        SetLift(liftPID->GetControlValue(GetPosition()));
    else
        SetLift(0.0);
}

void Lift::SetAngle(double targetAngle)
{
    double targetPosition = AngleToPosition(targetAngle);
    liftPID->SetTargetValue(targetPosition);
}

void Lift::SetHeight(double targetHeight)
{
    double targetPosition = HeightToPosition(targetHeight);
    liftPID->SetTargetValue(targetPosition);
}

double Lift::GetAngle()
{
    double angle = *startAngle;
    if(*countsPerDegree > 0.1)
        angle += GetPosition() / *countsPerDegree;
    return angle;
}

double Lift::GetHeight()
{
    double height = *startHeight + (*armLength * sin(GetAngle()));
    if(*countsPerInch > 0.1)
        height += GetPosition() / *countsPerInch;
    return height;
}