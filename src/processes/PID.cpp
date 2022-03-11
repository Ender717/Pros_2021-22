// Included libraries
#include "processes/PID.h"
#include "main.h"

// Constructor definitions ------------------------------------------------
PID::PIDBuilder::PIDBuilder()
{
    kp = -1.0;
    ki = -1.0;
    kd = -1.0;
    min = -1.0;
    max = -1.0;
    integralLimit = -1.0;
    startTarget = -1.0;
}

// Public method definitions ----------------------------------------------
PID::PIDBuilder PID::PIDBuilder::WithKp(float kp)
{
    this->kp = kp;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithKi(float ki)
{
    this->ki = ki;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithKd(float kd)
{
    this->kd = kd;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithMin(float min)
{
    this->min = min;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithMax(float max)
{
    this->max = max;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithIntegralLimit(float integralLimit)
{
    this->integralLimit = integralLimit;
    return *this;
}

PID::PIDBuilder PID::PIDBuilder::WithStartTarget(float startTarget)
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
    // Initialize KP
    this->kp = builder.kp;

    // Initialize KI
    this->ki = builder.ki;

    // Initialize KD
    this->kd = builder.kd;

    // Initialize min
    if(builder.min != -1.0)
        this->min = builder.min;
    else
        this->min = MOTOR_MIN;

    // Initialize max
    if(builder.max != -1.0)
        this->max = builder.max;
    else
        this->max = MOTOR_MAX;

    // Initialize integralLimit
    if(builder.integralLimit != -1.0)
        this->integralLimit = builder.integralLimit;
    else
        this->integralLimit = 0.0;

    // Initialize targetValue
    if(builder.startTarget != -1.0)
        this->targetValue = builder.startTarget;
    else
        this->targetValue = 0.0;

    // Initialize other variables
    pastTime = pros::c::millis();
    iValue = 0.0;
    pastError = 0.0;
}

// Public methods -------------------------------------------------------------
float PID::GetControlValue(float currentValue)
{
    // Calculate the current error
    float error = targetValue - currentValue;

    // Calculate the loop time
    float currentTime = pros::c::millis();
    float loopTime = (currentTime - pastTime) / 1000;

    // Set the proportional control value
    float pValue = error;

    // Set the integral control value
    if (pValue > min && pValue < max)
        iValue += error * loopTime;
    if (fabs(iValue) > integralLimit)
        iValue = (iValue / fabs(iValue)) * integralLimit;

    // Set the derivative control value
    float dValue = (error - pastError) / loopTime;

    // Calculate the control value
    float rawValue = (kp * pValue) + (ki * iValue) + (kd * dValue);
    float satValue = rawValue;

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

void PID::SetTargetValue(float targetValue)
{
    this->targetValue = targetValue;
}

void PID::SetMin(float min)
{
    this->min = min;
}

void PID::SetMax(float max)
{
    this->max = max;
}