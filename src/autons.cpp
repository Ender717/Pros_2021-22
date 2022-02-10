#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 4;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills()
    {
        // Run the routine
        Robot::drive.SetLeftDrive(127.0);
        Robot::drive.SetRightDrive(127.0);
    }

    void LeftAuton()
    {

    }

    void MiddleAuton()
    {

    }

    void RightAuton()
    {
        // Drive to the goal
        while (Robot::drive.GetDistance() < 130000.0)
        {
            Robot::drive.SetLeftDrive(120.0);
            Robot::drive.SetRightDrive(120.0);
            if (Robot::lift.GetPosition() > (LiftConfig::BOTTOM_POSITION - 2.0))
                Robot::lift.SetLift(-127.0);
            else
                Robot::lift.SetLift(0.0);
            if (Robot::claw.GetPosition() < ClawConfig::OPEN_POSITION)
                Robot::claw.SetClaw(127.0);
            else
                Robot::claw.SetClaw(0.0);
            pros::delay(5);
        }
        
        // Grab the goal
        while (Robot::claw.GetPosition() > ClawConfig::CLOSED_POSITION)
        {
            Robot::drive.SetLeftDrive(5.0);
            Robot::drive.SetRightDrive(5.0);
            Robot::claw.SetClaw(-127.0);
            pros::delay(5);
        }

        // Drive back
        while (Robot::drive.GetDistance() > 40000.0)
        {
            Robot::drive.SetLeftDrive(-127.0);
            Robot::drive.SetRightDrive(-127.0);
            if (Robot::claw.GetPosition() > ClawConfig::CLOSED_POSITION)
                Robot::claw.SetClaw(-127.0);
            else
                Robot::claw.SetClaw(0.0);
            pros::delay(5);
        }
    }
}