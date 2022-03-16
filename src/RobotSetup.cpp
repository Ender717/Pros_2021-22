// Included libraries
#include "RobotSetup.hpp"

Robot RobotSetup::robot;

void RobotSetup::Initialize(int robotSelected)
{
    switch(robotSelected)
    {
        case 1:
            robot.CreateBlueRobot();
            break;
        case 2:
            robot.CreateOrangeRobot();
            break;
        case 3:
            robot.CreateOldBlueRobot();
            break;
        case 4:
            robot.CreateOldOrangeRobot();
            break;
        default:
            robot.CreateBlueRobot();
            break;
    }
}