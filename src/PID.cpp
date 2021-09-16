// Include the header file for this class
#include "PID.h"

// Private methods ------------------------------------------------------------
void PID::CalculateError()
{
   pastError = error;
   error = targetValue - currentValue;
}

void PID::SetCurrentValue(float currentValue)
{
   this->currentValue = currentValue;
}

void PID::SaturationClamp()
{
   if (rawValue < min)
      satValue = min;
   else if (rawValue > max)
      satValue = max;
   else
      satValue = rawValue;
}

void PID::UpdateController()
{
   UpdateProportional();
   UpdateIntegral();
   UpdateDerivative();
   rawValue = (kp * pvalue) + (ki * ivalue) + (kd * dvalue);
}

void PID::UpdateProportional()
{
   pvalue = error;
}

void PID::UpdateIntegral()
{
   if (!IsSaturated() || (rawValue * error < 0))
   {
      ivalue += error * loopTime;
   }
}

void PID::UpdateDerivative()
{
   dvalue = (error - pastError) / loopTime;
}

bool PID::IsSaturated()
{
   return !(rawValue >= min && rawValue <= max);
}

// Constructors ---------------------------------------------------------------
PID::PID(float kp, float ki, float kd, float min, float max, float loopTime, 
   float startValue)
{
   this->kp = kp; 
   this->ki = ki;
   this->kd = kd;
   this->min = min;
   this->max = max;
   this->loopTime = loopTime;
   pvalue = 0.0;
   ivalue = 0.0;
   dvalue = 0.0;
   this->startValue = startValue;
   currentValue = 0.0;
   targetValue = 0.0;
   error = 0.0;
   pastError = 0.0;
   rawValue = 0.0;
   satValue = 0.0;
}

// Public methods -------------------------------------------------------------
float PID::GetControlValue(float currentValue)
{
   SetCurrentValue(currentValue);
   CalculateError();
   UpdateController();
   SaturationClamp();
   return satValue;
}

void PID::SetTargetValue(float targetValue)
{
   this->targetValue = targetValue;
}

float PID::PercentTarget()
{
   return currentValue * (100 / startValue);
}
