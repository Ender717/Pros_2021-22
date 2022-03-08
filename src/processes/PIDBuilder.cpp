// Included libraries
#include "./processes/PIDBuilder.h"

// Constructor definitions ------------------------------------------------
PIDBuilder::PIDBuilder()
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
PIDBuilder PIDBuilder::WithKp(float kp)
{
    this->kp = kp;
    return *this;
}

PIDBuilder PIDBuilder::WithKi(float ki)
{
    this->ki = ki;
    return *this;
}

PIDBuilder PIDBuilder::WithKd(float kd)
{
    this->kd = kd;
    return *this;
}

PIDBuilder PIDBuilder::WithMin(float min)
{
    this->min = min;
    return *this;
}

PIDBuilder PIDBuilder::WithMax(float max)
{
    this->max = max;
    return *this;
}

PIDBuilder PIDBuilder::WithIntegralLimit(float integralLimit)
{
    this->integralLimit = integralLimit;
    return *this;
}

PIDBuilder PIDBuilder::WithStartTarget(float startTarget)
{
    this->startTarget = startTarget;
    return *this;
}

PID PIDBuilder::Build()
{
    return PID(this);
}