// Inclusion guard
#ifndef PID_BUILDER_H
#define PID_BUILDER_H

// Included libraries
#include "PID.h"

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

#endif