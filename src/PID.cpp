#include "main.h"
#include "PID.h"

// Private methods ------------------------------------------------------------
void PID::CalculateError()
{
   // Update the error values
   pastError = error;
   error = targetValue - currentValue;
}

void PID::CalculateTime()
{
   // Update the time records of the previous and current system loop
   pastTime = currentTime;
   currentTime = pros::c::millis();
   loopTime = (currentTime - pastTime) / 1000;
}

void PID::SetCurrentValue(float currentValue)
{
   this->currentValue = currentValue;
}

void PID::SaturationClamp()
{
   // Clamp the controller values within the minimum and maximum output values
   if (rawValue < min)
      satValue = min;
   else if (rawValue > max)
      satValue = max;
   else
      satValue = rawValue;
}

void PID::UpdateController()
{
   // Update each of the three components of the controller
   UpdateProportional();
   UpdateIntegral();
   UpdateDerivative();

   // Set the result of the controller calculation
   rawValue = (kp * pValue) + (ki * iValue) + (kd * dValue) + kc;
}

void PID::UpdateProportional()
{
   // Set the proportional controller value to the error
   pValue = error;
}

void PID::UpdateIntegral()
{
   // Update the integral controller value based on the error in the past loop,
   // but only if the system is not maxed
   if (pValue > min && pValue < max)
      iValue += error * loopTime;
   if (fabs(iValue) > integralLimit)
      iValue = (iValue / fabs(iValue)) * integralLimit;
}

void PID::UpdateDerivative()
{
   // Set the derivative controller value to the change in error per second
   dValue = (error - pastError) / loopTime;
}

// Constructors ---------------------------------------------------------------
PID::PID(float kp, float ki, float kd, float min, float max, float integralLimit, 
   float startValue)
{
   this->kp = kp;
   this->ki = ki;
   this->kd = kd;
   this->min = min;
   this->max = max;
   this->integralLimit = integralLimit;
   currentTime = pros::c::millis();
   pastTime = pros::c::millis();
   loopTime = 0.0;
   pValue = 0.0;
   iValue = 0.0;
   dValue = 0.0;
   currentValue = startValue;
   targetValue = startValue;
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
   CalculateTime();
   UpdateController();
   SaturationClamp();
   return satValue;
}

void PID::SetTargetValue(float targetValue)
{
   this->targetValue = targetValue;
}