// Standard inclusion guard
#ifndef PID_H
#define PID_H

class PID
{
private:
   //-----------------------------------------------------------------------------
   // Control constants:
   // kp: Proportional constant
   // ki: Integral constant
   // kd: Derivative constant
   // kc: System constant
   //-----------------------------------------------------------------------------
   float kp;
   float ki;
   float kd;
   float kc;

   //-----------------------------------------------------------------------------
   // Limiting values:
   // min: Minimum output value
   // max: Maximum output value
   // integralLimit: Maximum integral controller value
   //-----------------------------------------------------------------------------
   float min;
   float max;
   float integralLimit;

   //-----------------------------------------------------------------------------
   // Time values:
   // pastTime: The previous time on the system clock
   //-----------------------------------------------------------------------------
   float pastTime;

   //-----------------------------------------------------------------------------
   // Input values:
   // targetValue: The target value of the external system
   // pastError: The error during the previous system loop
   //-----------------------------------------------------------------------------
   float targetValue;
   float pastError;

   //-----------------------------------------------------------------------------
   // Control values:
   // iValue: The value of the integral controller
   //-----------------------------------------------------------------------------
   float iValue;

public:
   //-----------------------------------------------------------------------------
   // Default constructor for PID class
   // float kp - the proportional constant for this system
   // float ki - the integral constant for this system
   // float kd - the derivative constant for this system
   // float kc - the control constant for this system
   // float min - the minimum value the controller can output
   // float max - the maximum value the controller can output
   // float startValue - the starting value of the system
   // v1: Created blank constructor - Nathan S, 9-10-21
   // v2: Added variable minimum and maximum initialization - Nathan S, 9-10-21
   // v3: Added constant read initializations - Nathan S, 9-10-21
   // v4: Added parameter for system loop time - Nathan S, 9-12-21
   // v5: Removed system loop time parameter - Nathan S, 1-12-22
   // v6: Added a control constant - Nathan S, 1-27-22
   //-----------------------------------------------------------------------------
   PID(float kp, float ki, float kd, float kc, float min, float max, float integralLimit, 
      float startValue);

   //-----------------------------------------------------------------------------
   // Returns the control variable based on the target and current values
   // float currentValue - the current value of the system's output
   // returns: The value of the control variable (system output)
   // v1: Created the method - Nathan S, 9-10-21
   //-----------------------------------------------------------------------------
   float GetControlValue(float currentValue);

   //-----------------------------------------------------------------------------
   // Setter method for targetValue
   // float targetValue - the value to set targetValue to
   // v1: Created the method - Nathan S, 9-11-21
   //-----------------------------------------------------------------------------
   void SetTargetValue(float targetValue);

   //-----------------------------------------------------------------------------
   // Setter method for min
   // float min - the value to set min to
   // v1: Created the method - Nathan S, 9-11-21
   //-----------------------------------------------------------------------------
   void SetMin(float min);

   //-----------------------------------------------------------------------------
   // Setter method for max
   // float min - the value to set max to
   // v1: Created the method - Nathan S, 9-11-21
   //-----------------------------------------------------------------------------
   void SetMax(float max);
};

#endif
