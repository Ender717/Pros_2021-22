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
        while (Robot::drive.GetDistance() > 81000.0)
        {
            Robot::drive.SetLeftDrive(-127.0);
            Robot::drive.SetRightDrive(-127.0);
            if (Robot::claw.GetPosition() > ClawConfig::CLOSED_POSITION)
                Robot::claw.SetClaw(-127.0);
            else
                Robot::claw.SetClaw(0.0);
            pros::delay(5);
        }
        Robot::drive.SetLeftDrive(0.0);
        Robot::drive.SetRightDrive(0.0);
        pros::delay(2000);

        // Turn toward the goal
        PID turnPID(5.2, 0.05, 0.05, 0.0, -127.0, 127.0, 33.0, Robot::position.GetTheta());
        PID armPID(4.3, 0.15, 0.05, 0.0, -127.0, 127.0, 80.0, 0.0);
        turnPID.SetTargetValue(-90.0);
        armPID.SetTargetValue(-2300.0);
        Robot::position.UpdatePosition();
        float driveControlValue = turnPID.GetControlValue(Robot::position.GetTheta());
        float liftControlValue = armPID.GetControlValue(Robot::lift.GetPosition());
        Robot::carrier.SetDown();

        int timer = 0;
        while(timer < 2000)
        {
            Robot::position.UpdatePosition();
            driveControlValue = turnPID.GetControlValue(Robot::position.GetTheta());
            liftControlValue = armPID.GetControlValue(Robot::lift.GetPosition());
            Robot::drive.SetLeftDrive(driveControlValue);
            Robot::drive.SetRightDrive(-driveControlValue);
            Robot::lift.SetLift(liftControlValue);
            timer = timer + 5;
            pros::delay(5);
        }
        Robot::drive.SetLeftDrive(0.0);
        Robot::drive.SetRightDrive(0.0);
        Robot::lift.SetLift(0.0);

        timer = 0;
        while (timer < 500)
        {
            Robot::drive.SetLeftDrive(-50.0);
            Robot::drive.SetRightDrive(-50.0);
            timer = timer + 5;
            pros::delay(5);
        }
        Robot::drive.SetLeftDrive(0.0);
        Robot::drive.SetRightDrive(0.0);

        Robot::intake.SetIntake(127.0);
        pros::delay(2000);
        Robot::intake.SetIntake(0.0);
    }
}