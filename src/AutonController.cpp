// Library being defined
#include "AutonController.hpp"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController(Robot* robot)
{
    this->robot = robot;
}

// Private method definitions -------------------------------------------------
void DistanceDriveTask(void* distance)
{
    double value = *(double*)distance;
    AutonController::robot->drive->DriveStraight(value);
}

void TurnDriveTask(void* angle)
{
    double value = *(double*)angle;
    AutonController::robot->drive->TurnToAngle(value);
}

void LiftTask(void* liftAngle)
{
    double value = *(double*)liftAngle;
    AutonController::robot->lift->SetAngle(value);
    AutonController::robot->lift->HoldPosition();
}

// Public method definitions --------------------------------------------------
void AutonController::DoDistanceTask(double distance, double liftAngle, 
    bool clawClosed, bool carrierDown, bool intake)
{
    if (clawClosed)
        robot->claw->SetClosed();
    else
        robot->claw->SetOpen();

    if (carrierDown)
        robot->carrier->SetDown();
    else
        robot->carrier->SetUp();

    if (intake)
        robot->intake->Suck();
    else
        robot->intake->Stop();

    void* parameter = nullptr;

    parameter = &distance;
    pros::Task driveTask(DistanceDriveTask, parameter, "Drive task");

    parameter = &liftAngle;
    pros::Task liftTask(LiftTask, parameter, "Lift task");
}

void AutonController::DoTurnTask(double targetAngle, double liftAngle,
    bool clawClosed, bool carrierDown, bool intake)
{

}

void AutonController::DoLiftDistanceTask(double distance, double liftAngle,
    bool clawClosed, bool carrierDown, bool intake)
{

}

void AutonController::DoLiftTurnTask(double targetAngle, double liftAngle,
    bool clawClosed, bool carrierDown, bool intake)
{

}
