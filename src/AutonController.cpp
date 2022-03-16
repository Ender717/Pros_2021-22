// Library being defined
#include "AutonController.hpp"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController(float x, float y, float theta)
{
    RobotSetup::robot.drive.SetPosition(x, y, theta);
}

// Public method definitions --------------------------------------------------
void AutonController::DoPositionTask(float targetX, float targetY, float drivePower, 
    float liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    RobotSetup::robot.drive.NewTask();
    RobotSetup::robot.lift.SetAngle(liftAngle);
    if(clawClosed)
        RobotSetup::robot.claw.SetClosed();
    else
        RobotSetup::robot.claw.SetOpen();
    if(carrierDown)
        RobotSetup::robot.carrier.SetDown();
    else
        RobotSetup::robot.carrier.SetUp();
    if(intake)
        RobotSetup::robot.intake.Suck();
    else
        RobotSetup::robot.intake.Stop();

    // Loop until the target is met
    while(!RobotSetup::robot.drive.TaskComplete())
    {
        //Menu::DrawPosition(robot);
        RobotSetup::robot.drive.GoToPositionTask(targetX, targetY, drivePower);
        RobotSetup::robot.lift.HoldPosition();
        RobotSetup::robot.claw.HoldPosition();
        pros::delay(10);
    }
}

void AutonController::DoTurnTask(float targetAngle, float drivePower, 
    float liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    RobotSetup::robot.drive.NewTask();
    RobotSetup::robot.lift.SetAngle(liftAngle);
    if (clawClosed)
        RobotSetup::robot.claw.SetClosed();
    else
        RobotSetup::robot.claw.SetOpen();
    if (carrierDown)
        RobotSetup::robot.carrier.SetDown();
    else
        RobotSetup::robot.carrier.SetUp();
    if (intake)
        RobotSetup::robot.intake.Suck();
    else
        RobotSetup::robot.intake.Stop();

    // Loop until the target is met
    while (!RobotSetup::robot.drive.TaskComplete())
    {
        //Menu::DrawPosition(robot);
        RobotSetup::robot.drive.TurnToAngleTask(targetAngle, drivePower);
        RobotSetup::robot.lift.HoldPosition();
        RobotSetup::robot.claw.HoldPosition();
        pros::delay(10);
    }
}