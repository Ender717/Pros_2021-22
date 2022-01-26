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
   // currentTime: The current time on the system clock
   // pastTime: The previous time on the system clock
   // loopTime: The amount of time elapsed during the system loop
   //-----------------------------------------------------------------------------
   float currentTime;
   float pastTime;
   float loopTime;

   //-----------------------------------------------------------------------------
   // Input values:
   // currentValue: The current value of the external system
   // targetValue: The target value of the external system
   // error: The distance between the current and target values
   // pastError: The error during the previous system loop
   //-----------------------------------------------------------------------------
   float currentValue;
   float targetValue;
   float error;
   float pastError;

   //-----------------------------------------------------------------------------
   // Control values:
   // pValue: The value of the proportional controller
   // iValue: The value of the integral controller
   // dValue: The value of the derivative controller
   //-----------------------------------------------------------------------------
   float pValue; // The value of the proportional controller
   float iValue; // The value of the integral controller
   float dValue; // The value of the derivative controller
   
   //-----------------------------------------------------------------------------
   // Output values:
   // rawValue: The unmodified result of the controller calculation
   // satValue: The value of the controller calculation with a saturation clamp
   //-----------------------------------------------------------------------------
   float rawValue; 
   float satValue; 

   //-----------------------------------------------------------------------------
   // Calculates the current error in the system
   // v1: Created the method - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void CalculateError();

   //-----------------------------------------------------------------------------
   // Calculates the time taken for the last loop of the system
   // v1: Created the method - Nathan S, 1-12-21
   //-----------------------------------------------------------------------------
   void CalculateTime();

   //-----------------------------------------------------------------------------
   // Sets the current value of the system
   // float currentValue - the value to set the current to
   // v1: Created the method - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void SetCurrentValue(float currentValue);

   //-----------------------------------------------------------------------------
   // Constrains the control value within the required minimum and maximum values,
   // then returns the constrained value
   // v1: Created the method - Nathan S, 9-10-21
   // v2: Removed parameter rawValue and made it part of class - Nathan S, 9-11-21
   // v3: Changed method to void and made result class member - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void SaturationClamp();

   //-----------------------------------------------------------------------------
   // Updates all components of the controller and returns its control value
   // v1: Created the method - Nathan S, 9-10-21
   // v2: Changed method to void and made result class member - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void UpdateController();

   //-----------------------------------------------------------------------------
   // Updates the value of the Proportional portion of the controller
   // v1: Created the method - Nathan S, 9-14-21
   //-----------------------------------------------------------------------------
   void UpdateProportional();

   //-----------------------------------------------------------------------------
   // Updates the value of the Integral portion of the controller
   // returns: The value of the integral portion of the controller
   // v1: Created method - Nathan S, 9-10-21
   // v2: Changed method to void and made result class member - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void UpdateIntegral();

   //-----------------------------------------------------------------------------
   // Updates the value of the Derivative portion of the controller
   // v1: Created the method - Nathan S, 9-14-21
   //-----------------------------------------------------------------------------
   void UpdateDerivative();

public:
   //-----------------------------------------------------------------------------
   // Default constructor for PID class
   // float kp - the proportional constant for this system
   // float ki - the integral constant for this system
   // float kd - the derivative constant for this system
   // float min - the minimum value the controller can output
   // float max - the maximum value the controller can output
   // float startValue - the starting value of the system
   // v1: Created blank constructor - Nathan S, 9-10-21
   // v2: Added variable minimum and maximum initialization - Nathan S, 9-10-21
   // v3: Added constant read initializations - Nathan S, 9-10-21
   // v4: Added parameter for system loop time - Nathan S, 9-12-21
   // v5: Removed system loop time parameter - Nathan S, 1-12-21
   //-----------------------------------------------------------------------------
   PID(float kp, float ki, float kd, float min, float max, float integralLimit, 
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
};

#endif
