// Library being defined
#include "AutonController.h"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController(float x, float y, float theta) : robot(RobotColor::ORANGE)
{
    robot.drive.SetPosition(x, y, theta);
}

// Public method definitions --------------------------------------------------
void AutonController::DoPositionTask(float targetX, float targetY, float drivePower, 
    float liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    robot.drive.NewTask();
    robot.lift.SetTargetAngle(liftAngle);
    if(clawClosed)
        robot.claw.SetClosed();
    else
        robot.claw.SetOpen();
    if(carrierDown)
        robot.carrier.SetDown();
    else
        robot.carrier.SetUp();
    if(intake)
        robot.intake.Suck();
    else
        robot.intake.Stop();

    // Loop until the target is met
    while(!robot.drive.TaskComplete())
    {
        Menu::DrawPosition(robot);
        robot.drive.GoToPositionTask(targetX, targetY, drivePower);
        robot.lift.HoldPosition();
        if(!clawClosed || (clawClosed && robot.claw.HasGoal()))
            robot.claw.HoldPosition();
        pros::delay(10);
    }
}

void AutonController::DoTurnTask(float targetAngle, float drivePower, 
    float liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    robot.drive.NewTask();
    robot.lift.SetTargetAngle(liftAngle);
    if (clawClosed)
        robot.claw.SetClosed();
    else
        robot.claw.SetOpen();
    if (carrierDown)
        robot.carrier.SetDown();
    else
        robot.carrier.SetUp();
    if (intake)
        robot.intake.Suck();
    else
        robot.intake.Stop();

    // Loop until the target is met
    while (!robot.drive.TaskComplete())
    {
        Menu::DrawPosition(robot);
        robot.drive.TurnToAngleTask(targetAngle, drivePower);
        robot.lift.HoldPosition();
        if(!clawClosed || (clawClosed && robot.claw.HasGoal()))
            robot.claw.HoldPosition();
        pros::delay(10);
    }
}