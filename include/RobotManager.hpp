// Inclusion guard
#ifndef ROBOT_MANAGER_HPP
#define ROBOT_MANAGER_HPP

// Included libraries
#include "config/BlueConfig.hpp"
#include "config/OrangeConfig.hpp"
#include "config/OldBlueConfig.hpp"
#include "config/OldOrangeConfig.hpp"
#include "Robot.hpp"
#include "main.h"

//-----------------------------------------------------------------------------
// This enum manages the different available types of robot configurations
// v1: Created the enum - Nathan S, 4-13-22
//-----------------------------------------------------------------------------
enum class RobotConfigs
{
    BLUE,
    ORANGE,
    OLD_BLUE,
    OLD_ORANGE
};

//-----------------------------------------------------------------------------
// This class manages the creation and storage of a robot
// v1: Created the class - Nathan S, 4-13-22
//-----------------------------------------------------------------------------
class RobotManager
{
private:
    //-------------------------------------------------------------------------
    // Attributes:
    // robot: The robot being stored in the manager
    //-------------------------------------------------------------------------
    static Robot* robot;

    //-------------------------------------------------------------------------
    // Creates a pre-configured blue robot
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void CreateBlueRobot();

    //-------------------------------------------------------------------------
    // Creates a pre-configured orange robot
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void CreateOrangeRobot();

    //-------------------------------------------------------------------------
    // Creates a pre-configured old blue robot
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void CreateOldBlueRobot();

    //-------------------------------------------------------------------------
    // Creates a pre-configured old orange robot
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void CreateOldOrangeRobot();

public:
    //-------------------------------------------------------------------------
    // Initializes the robot attribute to nullptr
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void Intialize();

    //-------------------------------------------------------------------------
    // Creates a robot with the specified configuration
    // config: The specified configuration
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static void CreateRobot(RobotConfigs config);

    //-------------------------------------------------------------------------
    // Gets the current instance of the robot
    // return: The current robot instance
    // v1: Created the method - Nathan S, 4-13-22
    //-------------------------------------------------------------------------
    static Robot* GetRobot();
};

#endif