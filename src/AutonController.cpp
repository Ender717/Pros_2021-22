// Library being defined
#include "AutonController.hpp"

// Task function definitions --------------------------------------------------
void TimerTask(void* time)
{
    double value = *(double*)time;
    double targetTime = pros::c::millis() + value;
    while (pros::c::millis() < targetTime)
        pros::Task::delay(10);
    *AutonController::taskComplete = true;
    while (true)
        pros::Task::delay(500);
}

void ThroughDriveTask(void* params)
{
    double* value = (double*)params;
    AutonController::robot->drive->DriveStraightThrough(value[0], value[1]);
    *AutonController::taskComplete = true;
    while (true)
        pros::Task::delay(500);
}

void DistanceDriveTask(void* params)
{
    double* value = (double*)params;
    AutonController::robot->drive->DriveStraight(value[0], value[1]);
    *AutonController::taskComplete = true;
    while (true)
        pros::Task::delay(500);
}

void TurnDriveTask(void* angle)
{
    double value = *(double*)angle;
    AutonController::robot->drive->TurnToAngle(value);
    *AutonController::taskComplete = true;
    while (true)
        pros::Task::delay(500);
}

void LiftTask(void* liftAngle)
{
    double value = *(double*)liftAngle;
    AutonController::robot->lift->SetAngle(value);
    while (true)
    {
        AutonController::robot->lift->HoldPosition();
        pros::Task::delay(10);
    }
}

void ClawTask()
{
    AutonController::robot->claw->GrabObject();
    *AutonController::taskComplete = true;
    while (true)
        pros::Task::delay(500);
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
        void* parameter = nullptr;

        double time = 2000.0;
        parameter = &time;
        pros::Task timerTask(TimerTask, parameter, "Timer Task");

        double params[2] = { 33.0, 0.0 };
        parameter = &params;
        pros::Task driveTask(ThroughDriveTask, parameter, "Drive Task");

        double liftHeight = -15.0;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        //pros::Task clawTask(ClawTask, "Claw Task");

        while (!*taskComplete)
            pros::Task::delay(50);
        
        timerTask.remove();
        driveTask.remove();
        liftTask.remove();
        //clawTask.remove();

        robot->claw->SetClosed();
        robot->lift->Stop();
        pros::delay(100);
        robot->drive->DriveStraightThrough(-30.0, 0.0);
        robot->drive->SetDrive(0.0, 0.0);
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

        robot->drive->DriveStraight(distance, robot->drive->GetTheta());

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