// Standard inclusion guard
#ifndef PID_H
#define PID_H

// Included libraries
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages a PID controller
// v1: Created the class - Nathan S, 9-10-21
//-----------------------------------------------------------------------------
class PID
{
private:
    //-------------------------------------------------------------------------
    // Constants
    // MOTOR_MIN: The minimum control value of a motor
    // MOTOR_MAX: The maximum control value of a motor
    //-------------------------------------------------------------------------
    static constexpr float MOTOR_MIN = -127.0;
    static constexpr float MOTOR_MAX = 127.0;
    
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
    //-----------------------------------------------------------------------------
    // This is a builder class for PID controllers
    // v1: Created the class - Nathan S, 3-8-22
    //-----------------------------------------------------------------------------
    class PIDBuilder
    {
    public:
        //-------------------------------------------------------------------------
        // Attributes:
        // kp: The proportional constant
        // ki: The integral constant
        // kd: The derivative constant
        // min: The minimum output of the controller
        // max: The maximum output of the controller
        // integralLimit: The maximum value of the integral controller output
        // startTarget: The initial target of the systems
        //-------------------------------------------------------------------------
        float kp;
        float ki;
        float kd;
        float min;
        float max;
        float integralLimit;
        float startTarget;

        //-------------------------------------------------------------------------
        // Default constructor for the PIDBuilder class
        // v1: Created the constructor - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder();

        //-------------------------------------------------------------------------
        // Wither method for the kp attribute
        // kp: The value to set kp to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithKp(float kp);

        //-------------------------------------------------------------------------
        // Wither method for the ki attribute
        // ki: The value to set ki to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithKi(float ki);

        //-------------------------------------------------------------------------
        // Wither method for the kd attribute
        // kd: The value to set kd to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithKd(float kd);

        //-------------------------------------------------------------------------
        // Wither method for the min attribute
        // min: The value to set min to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithMin(float min);

        //-------------------------------------------------------------------------
        // Wither method for the max attribute
        // max: The value to set max to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithMax(float max);

        //-------------------------------------------------------------------------
        // Wither method for the integralLimit attribute
        // integralLimit: The value to set integralLimit to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithIntegralLimit(float integralLimit);

        //-------------------------------------------------------------------------
        // Wither method for the startTarget attribute
        // startTarget: The value to set startTarget to
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PIDBuilder WithStartTarget(float startTarget);

        //-------------------------------------------------------------------------
        // Constructs and returns a new PID from the builder
        // return: The new PID controller
        // v1: Created the method - Nathan S, 3-8-22
        //-------------------------------------------------------------------------
        PID Build();
    };
    //-------------------------------------------------------------------------
    // Default constructor for PID class
    // v1: Created the constructor - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    PID();

    //-------------------------------------------------------------------------
    // Builder constructor for PID class
    // v7: Converted to a builder constructor - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    PID(PIDBuilder builder);

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