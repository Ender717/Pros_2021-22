// Included libraries
#include "main.h"
#include "processes/PID.h"

// Constructors ---------------------------------------------------------------
PID::PID(PIDBuilder* builder)
{
    // Initialize KP
    if(builder->kp != -1.0)
        this->kp = builder->kp;
    else
        this->kp = 0.0;

    // Initialize KI
    if(builder->ki != -1.0)
        this->ki = builder->ki;
    else
        this->ki = 0.0;

    // Initialize KD
    if(builder->kd != -1.0)
        this->kd = builder->kd;
    else
        this->kd = 0.0;

    // Initialize min
    if(builder->min != -1.0)
        this->min = builder->min;
    else
        this->min = MOTOR_MIN;

    // Initialize max
    if(builder->max != -1.0)
        this->max = builder->max;
    else
        this->max = MOTOR_MAX;

    // Initialize integralLimit
    if(builder->integralLimit != -1.0)
        this->integralLimit = builder->integralLimit;
    else
        this->integralLimit = 0.0;

    // Initialize targetValue
    if(builder->startTarget != -1.0)
        this->targetValue = builder->startTarget;
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