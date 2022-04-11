// Standard inclusion guard
#ifndef PID_HPP
#define PID_HPP

// Included libraries
#include <cfloat>
#include "./main.h"

//-----------------------------------------------------------------------------
// This class manages a PID controller
// v1: Created the class - Nathan S, 9-10-21
//-----------------------------------------------------------------------------
class PID
{
private:
    //-------------------------------------------------------------------------
    // Class constants:
    // MILLISECONDS_PER_SECOND: The number of milliseconds per second
    //-------------------------------------------------------------------------
    static constexpr int MILLISECONDS_PER_SECOND = 1000;

    //-------------------------------------------------------------------------
    // Control constants:
    // kp: Proportional constant
    // ki: Integral constant
    // kd: Derivative constant
    //-------------------------------------------------------------------------
    double* kp;
    double* ki;
    double* kd;

    //-------------------------------------------------------------------------
    // Limiting values:
    // min: Minimum output value
    // max: Maximum output value
    // integralLimit: Maximum integral controller value
    //-------------------------------------------------------------------------
    double* min;
    double* max;
    double* integralLimit;

    //-------------------------------------------------------------------------
    // Time values:
    // pastTime: The previous time on the system clock
    //-------------------------------------------------------------------------
    double* pastTime;

    //-------------------------------------------------------------------------
    // Input values:
    // targetValue: The target value of the external system
    // pastError: The error during the previous system loop
    //-------------------------------------------------------------------------
    double* targetValue;
    double* pastError;

    //-------------------------------------------------------------------------
    // Control values:
    // iValue: The value of the integral controller
    //-------------------------------------------------------------------------
    double* iValue;

public:
    //-------------------------------------------------------------------------
    // This is a builder class for PID controllers
    // v1: Created the class - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    class PIDBuilder
    {
    public:    
        //---------------------------------------------------------------------
        // Attributes:
        // kp: The proportional constant
        // ki: The integral constant
        // kd: The derivative constant
        // min: The minimum output of the controller
        // max: The maximum output of the controller
        // integralLimit: The maximum value of the integral controller output
        // startTarget: The initial target of the systems
        //---------------------------------------------------------------------
        double* kp;
        double* ki;
        double* kd;
        double* min;
        double* max;
        double* integralLimit;
        double* startTarget;

        //---------------------------------------------------------------------
        // Default constructor for the PIDBuilder class
        // v1: Created the constructor - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder();

        //---------------------------------------------------------------------
        // Default destructor for the PIDBuilder class
        // v1: Created the destructor - Nathan S, 4-11-22
        //---------------------------------------------------------------------
        ~PIDBuilder();

        //---------------------------------------------------------------------
        // Wither method for the kp attribute
        // kp: The value to set kp to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithKp(double kp);

        //---------------------------------------------------------------------
        // Wither method for the ki attribute
        // ki: The value to set ki to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithKi(double ki);

        //---------------------------------------------------------------------
        // Wither method for the kd attribute
        // kd: The value to set kd to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithKd(double kd);

        //---------------------------------------------------------------------
        // Wither method for the min attribute
        // min: The value to set min to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithMin(double min);

        //---------------------------------------------------------------------
        // Wither method for the max attribute
        // max: The value to set max to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithMax(double max);

        //---------------------------------------------------------------------
        // Wither method for the integralLimit attribute
        // integralLimit: The value to set integralLimit to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithIntegralLimit(double integralLimit);

        //---------------------------------------------------------------------
        // Wither method for the startTarget attribute
        // startTarget: The value to set startTarget to
        // return: The builder for build chaining
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PIDBuilder* WithStartTarget(double startTarget);

        //---------------------------------------------------------------------
        // Constructs and returns a new PID from the builder
        // return: The new PID controller
        // v1: Created the method - Nathan S, 3-8-22
        //---------------------------------------------------------------------
        PID* Build();
    };

    //-------------------------------------------------------------------------
    // Builder constructor for PID class
    // v7: Converted to a builder constructor - Nathan S, 3-8-22
    //-------------------------------------------------------------------------
    PID(PIDBuilder* builder);

    //-------------------------------------------------------------------------
    // Default destructor for PID class
    // v1: Created the destructor - Nathan S, 4-11-22
    //-------------------------------------------------------------------------
    ~PID();

    //-------------------------------------------------------------------------
    // Returns the control variable based on the target and current values
    // double currentValue - the current value of the system's output
    // returns: The value of the control variable (system output)
    // v1: Created the method - Nathan S, 9-10-21
    //-------------------------------------------------------------------------
    double GetControlValue(double currentValue);

    //-------------------------------------------------------------------------
    // Setter method for targetValue
    // double targetValue - the value to set targetValue to
    // v1: Created the method - Nathan S, 9-11-21
    //-------------------------------------------------------------------------
    void SetTargetValue(double targetValue);
};

#endif