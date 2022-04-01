// Library being defined
#include "AutonController.hpp"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController(double x, double y, double theta)
{
    robot.drive.SetPosition(x, y, theta);
}

// Public method definitions --------------------------------------------------
void AutonController::DoPositionTask(double targetX, double targetY, double drivePower, 
    double liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    robot.drive.NewTask();
    robot.lift.SetAngle(liftAngle);
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
        //Menu::DrawPosition(robot);
        robot.drive.GoToPosition(targetX, targetY, drivePower);
        robot.lift.HoldPosition();
        robot.claw.HoldPosition();
        pros::delay(10);
    }
}

void AutonController::DoTurnTask(double targetAngle, double drivePower, 
    double liftAngle, bool clawClosed, bool carrierDown, bool intake)
{
    // Initialize the new positions
    robot.drive.NewTask();
    robot.lift.SetAngle(liftAngle);
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
        //Menu::DrawPosition(robot);
        robot.drive.TurnToAngle(targetAngle, drivePower);
        robot.lift.HoldPosition();
        robot.claw.HoldPosition();
        pros::delay(10);
    }
}