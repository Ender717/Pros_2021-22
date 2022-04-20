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

void AutonController::TurnDriveTask(void* angle)
{
    double value = *(double*)angle;
    robot->drive->TurnToAngle(value);
}

void AutonController::LiftTask(void* liftAngle)
{
    double value = *(double*)liftAngle;
    robot->lift->SetAngle(value);
}

// Public method definitions --------------------------------------------------
void AutonController::DoDistanceTask(double distance, double liftAngle, 
    bool clawClosed, bool carrierDown, bool intake)
{
    void* parameter = nullptr;

    parameter = &distance;
    pros::Task driveTask(DistanceDriveTask, parameter, "Drive task");
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
