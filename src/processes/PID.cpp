// Included libraries
#include "processes/PID.hpp"

// Constructor definitions ------------------------------------------------
PID::PIDBuilder::PIDBuilder()
{
    kp = 0.0;
    ki = 0.0;
    kd = 0.0;
    min = MOTOR_MIN;
    max = MOTOR_MAX;
    integralLimit = 0.0;
    startTarget = 0.0;
}

// Public method definitions ----------------------------------------------
PID::PIDBuilder PID::PIDBuilder::WithKp(double kp)
{
    this->kp = kp;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithKi(double ki)
{
    this->ki = ki;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithKd(double kd)
{
    this->kd = kd;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithMin(double min)
{
    this->min = min;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithMax(double max)
{
    this->max = max;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithIntegralLimit(double integralLimit)
{
    this->integralLimit = integralLimit;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithStartTarget(double startTarget)
{
    this->startTarget = startTarget;
    return *this;
}

PID PID::PIDBuilder::Build()
{
    return PID(*this);
}

// Constructors ---------------------------------------------------------------
PID::PID()
{
    kp = 0.0;
    ki = 0.0;
    kd = 0.0;
    min = 0.0;
    max = 0.0;
    integralLimit = 0.0;
    targetValue = 0.0;
    pastTime = 0.0;
    iValue = 0.0;
    pastError = 0.0;
}

PID::PID(PIDBuilder builder)
{
    // Initialize builder variables
    this->kp = builder.kp;
    this->ki = builder.ki;
    this->kd = builder.kd;
    this->min = builder.min;
    this->max = builder.max;
    this->integralLimit = builder.integralLimit;
    this->targetValue = builder.startTarget;

    // Initialize other variables
    pastTime = pros::c::millis();
    iValue = 0.0;
    pastError = 0.0;
}

// Public methods -------------------------------------------------------------
double PID::GetControlValue(double currentValue)
{
    // Calculate the current error
    double error = targetValue - currentValue;

    // Calculate the loop time
    double currentTime = pros::c::millis();
    double loopTime = (currentTime - pastTime) / 1000;

    // Set the proportional control value
    double pValue = error;

    // Set the integral control value
    if (pValue > min && pValue < max)
        iValue += error * loopTime;
    if (fabs(iValue) > integralLimit)
        iValue = (iValue / fabs(iValue)) * integralLimit;

    // Set the derivative control value
    double dValue = (error - pastError) / loopTime;

    // Calculate the control value
    double rawValue = (kp * pValue) + (ki * iValue) + (kd * dValue);
    double satValue = rawValue;

    // Saturate the control value
    if (satValue < min)
        satValue = min;
    else if (satValue > max)
        satValue = max;

    // Update the stored previous values
    pastError = error;
    pastTime = currentTime;

    // Return the result
    return satValue;
}

void PID::SetTargetValue(double targetValue)
{
    this->targetValue = targetValue;
}