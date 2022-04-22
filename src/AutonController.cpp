// Library being defined
#include "AutonController.hpp"

// Task function definitions --------------------------------------------------
void ThroughDriveTask(void* distance)
{
    double value = *(double*)distance;
    AutonController::robot->drive->DriveStraightThrough(value);
    *AutonController::taskComplete = true;
}

void DistanceDriveTask(void* distance)
{
    double value = *(double*)distance;
    AutonController::robot->drive->DriveStraight(value);
    *AutonController::taskComplete = true;
}

void TurnDriveTask(void* angle)
{
    double value = *(double*)angle;
    AutonController::robot->drive->TurnToAngle(value);
    *AutonController::taskComplete = true;
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

void ClawTask()
{
    AutonController::robot->claw->GrabObject();
    *AutonController::taskComplete = true;
}

namespace AutonController
{
    Robot* robot = nullptr;
    bool* taskComplete = new bool(false);

    // Public method definitions ----------------------------------------------
    void DoStartTask()
    {
        *AutonController::taskComplete = false;
        robot->claw->SetOpen();

        double distance = 33.0;
        void* parameter = &distance;
        pros::Task driveTask(ThroughDriveTask, parameter, "Drive Task");

        double liftHeight = -18.0;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        pros::Task clawTask(ClawTask, "Claw Task");

        while (!*taskComplete)
            pros::Task::delay(50);
        
        driveTask.remove();
        liftTask.remove();
        clawTask.remove();

        robot->claw->SetClosed();
        robot->lift->Stop();
        robot->drive->DriveStraight(-30.0);
    }

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