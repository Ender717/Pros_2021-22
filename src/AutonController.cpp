// Library being defined
#include "AutonController.h"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController() : robot(RobotColor::ORANGE)
{

}

// Public method definitions --------------------------------------------------
void AutonController::DoDriveTask(float targetX, float targetY, 
    float drivePower, float liftAngle, bool clawClosed, bool carrierDown)
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

    // Loop until the target is met
    while(!robot.drive.TaskComplete())
    {
        Menu::DrawPosition(robot);
        robot.drive.GoToPositionTask(targetX, targetY, drivePower);
        robot.lift.HoldPosition();
        robot.claw.HoldPosition();
        pros::delay(10);
    }
}