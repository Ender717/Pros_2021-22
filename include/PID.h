// Standard inclusion guard
#ifndef PID_H
#define PID_H

class PID
{
private:
   float kp; // Proportional constant
   float ki; // Integral constant
   float kd; // Derivative constant
   float min; // The minimum value of the output
   float max; // The maximum value of the output
   float loopTime; // The amount of time per system loop
   float pvalue; // The value of the proportional controller
   float ivalue; // The value of the integral controller
   float dvalue; // The value of the derivative controller
   float startValue; // The value the system started at
   float currentValue; // The current value of the system
   float targetValue; // The target value of the system
   float error; // The error between the target value and current value
   float pastError; // The error during the last iteration of the loop
   float rawValue; // The unmodified result of the controller calculation
   float satValue; // The result of the calculation constrained to the sat limit

   //-----------------------------------------------------------------------------
   // Calculates the current error in the system
   // v1: Created the method - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   void CalculateError();

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
   // Checks if the controller is saturated
   // float rawValue - the unconstrained control value
   // float controlValue - the constrained control value
   // returns: true if the controller is saturated, false if not
   // v1: Created the method - Nathan S, 9-10-21
   //-----------------------------------------------------------------------------
   bool IsSaturated();

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
   // v1: Created blank constructor - Nathan S, 9-10-21
   // v2: Added variable minimum and maximum initialization - Nathan S, 9-10-21
   // v3: Added constant read initializations - Nathan S, 9-10-21
   // v4: Added parameter for system loop time - Nathan S, 9-12-21
   //-----------------------------------------------------------------------------
   PID(float kp, float ki, float kd, float min, float max, float loopTime,
      float startValue);

   //-----------------------------------------------------------------------------
   // Returns the control variable based on the target and current values
   // float currentValue - the current value of the system's output
   // float targetValue - the desired value for the system to reach
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
   // Checks whether the pid controller has reached its target
   float PercentTarget();
};

#endif
