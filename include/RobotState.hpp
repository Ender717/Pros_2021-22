// Inclusion guard
#ifndef ROBOT_STATE_HPP
#define ROBOT_STATE_HPP

// Included libraries
#include "Robot.hpp"
#include "RobotManager.hpp"
#include "main.h"

//-----------------------------------------------------------------------------
// This namespace stores the state of the robot
// v1: Created the namespace - Nathan S, 4-13-22
//-----------------------------------------------------------------------------
namespace RobotState
{
    // The robot state
    extern Robot* robot;
    extern RobotConfigs* configuration;
};

#endif