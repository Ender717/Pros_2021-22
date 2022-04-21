// Library being defined
#include "AutonController.hpp"

// Task function definitions --------------------------------------------------
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
    while (true)
    {
        AutonController::robot->lift->HoldPosition();
        pros::Task::delay(5);
    }
}

namespace AutonController
{
    Robot* robot = nullptr;

    // Public method definitions ----------------------------------------------
    void DoDistanceTask(double distance, double liftAngle, 
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
        parameter = &liftAngle;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraight(distance);

        liftTask.suspend();
        liftTask.remove();

        robot->lift->Stop();
        robot->intake->Stop();
        parameter = nullptr;
    }

    void DoTurnTask(double targetAngle, double liftAngle,
        bool clawClosed, bool carrierDown, bool intake)
    {

    }

    void DoLiftDistanceTask(double distance, double liftAngle,
        bool clawClosed, bool carrierDown, bool intake)
    {

    }

    void DoLiftTurnTask(double targetAngle, double liftAngle,
        bool clawClosed, bool carrierDown, bool intake)
    {

    }
}