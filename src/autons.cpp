#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 5;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills1(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, 36.0, 0.0);
        robot.drive.GoToPosition(-35.0, 46.0);
        robot.drive.GoToPosition(-52.0, 27.0);
    }

    void ProgrammingSkills2(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, -36.0, 0.0);
        robot.drive.GoToPosition(-75.0, -36.0);
    }

    void LeftAuton(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, 36.0, 0.0);
    }

    void MiddleAuton(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, -36.0, 33.2);
    }

    void RightAuton(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, -36.0, 0.0);
    }
}