// Included libraries
#include "main.h"
#include "processes/PID.h"

// Constructors ---------------------------------------------------------------
PID::PID(float kp, float ki, float kd, float kc, float min, float max, float integralLimit, 
   float startValue)
{
   this->kp = kp;
   this->ki = ki;
   this->kd = kd;
   this->kc = kc;
   this->min = min;
   this->max = max;
   this->integralLimit = integralLimit;
   pastTime = pros::c::millis();
   iValue = 0.0;
   targetValue = startValue;
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
   float rawValue = (kp * pValue) + (ki * iValue) + (kd * dValue) + kc;
   float satValue = rawValue;
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