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
        robot.drive.SetPosition(-55.0, -36.0, 0.0);

        // Move forward
        robot.drive.NewTask();
        robot.lift.SetTargetAngle(-17.0);
        robot.claw.SetOpen();
        while(!robot.drive.TaskComplete())
        {
            Menu::DrawPosition(robot);
            robot.drive.GoToPositionTask(-25.0, -36.0, 110.0);
            robot.lift.HoldPosition();
            robot.claw.HoldPosition();
            pros::delay(10);
        }

        robot.drive.NewTask();
        robot.lift.SetTargetAngle(-17.0);
        robot.claw.SetClosed();
        while(!robot.drive.TaskComplete())
        {
            Menu::DrawPosition(robot);
            robot.drive.GoToPositionTask(-20.0, -36.0, 30.0);
            robot.lift.HoldPosition();
            robot.claw.HoldPosition();
            pros::delay(10);
        }

        // Move backward
        robot.drive.NewTask();
        robot.lift.SetTargetAngle(110.0);
        robot.claw.SetClosed();
        while(!robot.drive.TaskComplete())
        {
            Menu::DrawPosition(robot);
            robot.drive.GoToPositionTask(-60.0, -36.0, 127.0);
            robot.lift.HoldPosition();
            robot.claw.HoldPosition();
            pros::delay(10);
        }

        robot.drive.TurnToAngle(90.0);

        robot.drive.NewTask();
        robot.lift.SetTargetAngle(30.0);
        robot.claw.SetClosed();
        while(!robot.drive.TaskComplete())
        {
            Menu::DrawPosition(robot);
            robot.drive.GoToPositionTask(-60.0, -26.0, 40.0);
            robot.lift.HoldPosition();
            robot.claw.HoldPosition();
            pros::delay(10);
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