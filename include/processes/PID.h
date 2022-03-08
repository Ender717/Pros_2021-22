// Standard inclusion guard
#ifndef PID_H
#define PID_H

// Included libraries
#include "PIDBuilder.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class PID
{
private:
    //-------------------------------------------------------------------------
    // Constants
    // MOTOR_MIN: The minimum control value of a motor
    // MOTOR_MAX: The maximum control value of a motor
    //-------------------------------------------------------------------------
    static const float MOTOR_MIN = -127.0;
    static const float MOTOR_MAX = 127.0;
    
    //-------------------------------------------------------------------------
    // Control constants:
    // kp: Proportional constant
    // ki: Integral constant
    // kd: Derivative constant
    //-------------------------------------------------------------------------
    float kp;
    float ki;
    float kd;

    //-------------------------------------------------------------------------
    // Limiting values:
    // min: Minimum output value
    // max: Maximum output value
    // integralLimit: Maximum integral controller value
    //-------------------------------------------------------------------------
    float min;
    float max;
    float integralLimit;

    //-------------------------------------------------------------------------
    // Time values:
    // pastTime: The previous time on the system clock
    //-------------------------------------------------------------------------
    float pastTime;

    //-------------------------------------------------------------------------
    // Input values:
    // targetValue: The target value of the external system
    // pastError: The error during the previous system loop
    //-------------------------------------------------------------------------
    float targetValue;
    float pastError;

    //-------------------------------------------------------------------------
    // Control values:
    // iValue: The value of the integral controller
    //-------------------------------------------------------------------------
    float iValue;

public:
    //-------------------------------------------------------------------------
    // Default constructor for PID class
    // v1: Created the constructor - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    PID();

    //-------------------------------------------------------------------------
    // Builder constructor for PID class
    // v7: Converted to a builder constructor - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    PID(PIDBuilder* builder);

    //-------------------------------------------------------------------------
    // Returns the control variable based on the target and current values
    // float currentValue - the current value of the system's output
    // returns: The value of the control variable (system output)
    // v1: Created the method - Nathan S, 9-10-21
    //-------------------------------------------------------------------------
    float GetControlValue(float currentValue);

    //-------------------------------------------------------------------------
    // Setter method for targetValue
    // float targetValue - the value to set targetValue to
    // v1: Created the method - Nathan S, 9-11-21
    //-------------------------------------------------------------------------
    void SetTargetValue(float targetValue);

    //-------------------------------------------------------------------------
    // Setter method for min
    // float min - the value to set min to
    // v1: Created the method - Nathan S, 9-11-21
    //-------------------------------------------------------------------------
    void SetMin(float min);

    //-------------------------------------------------------------------------
    // Setter method for max
    // float min - the value to set max to
    // v1: Created the method - Nathan S, 9-11-21
    //-------------------------------------------------------------------------
    void SetMax(float max);
};

#endif