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
        // Move forward
        robot.drive.SetPosition(-55.0, -36.0, 0.0);
        robot.lift.SetTargetAngle(10.0);
        while(true)
        {
            robot.lift.HoldPosition();
            pros::delay(5);
        }

        /*
        while(!robot.drive.TaskComplete())
        {

        }
        robot.drive.TurnToAngle(-90.0);
        */

        /*
        robot.carrier.SetUp();
        robot.claw.SetOpen();
        robot.intake.Stop();
        robot.lift.SetTargetAngle(10.0);
        while(!robot.drive.TaskComplete())
        {
            robot.drive.GoToPositionTask(-35.0, 46.0, 127.0);
            robot.claw.HoldPosition();
            robot.lift.HoldPosition();
            pros::delay(10);
        }
        */
        
        // Move backward
        //robot.drive.GoToPosition(-52.0, 27.0, 127.0);
    }

    void ProgrammingSkills2(Robot& robot)
    {
        robot.drive.SetPosition(-55.0, -36.0, 0.0);
        robot.drive.TurnToAngle(90.0);
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