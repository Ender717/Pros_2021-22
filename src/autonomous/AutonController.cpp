// Library being defined
#include "autonomous/AutonController.hpp"

// Task function definitions --------------------------------------------------
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

void HoldLiftTask()
{
    AutonController::robot->lift->SetAngle(110.0);
    while (true)
    {
        AutonController::robot->lift->HoldUp();
        pros::delay(10);
    }
}

namespace AutonController
{
    Robot* robot = nullptr;
    bool* taskComplete = new bool(false);

    // Public method definitions ----------------------------------------------
    void DoLeftStartTaskBlue()
    {
        *AutonController::taskComplete = false;
        robot->claw->SetOpen();
        void* parameter = nullptr;

        double liftHeight = -18.5;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraightThrough(28.0, 0.0, 127.0);
        
        liftTask.remove();
        robot->lift->Stop();

        robot->claw->SetClosed();
        pros::delay(130);        

        robot->drive->DriveStraightThrough(-30.0, 0.0, 127.0);

        robot->drive->SetDrive(-40.0, -40.0);
        pros::delay(1000);
        robot->drive->SetDrive(0.0, 0.0);

        liftHeight = 110.0;
        parameter = &liftHeight;
        pros::Task liftTask2(HoldLiftTask, /*parameter,*/ "Lift task");

        pros::delay(1000);
        liftTask2.remove();
        robot->lift->Stop();
    }

    void DoMiddleStartTaskBlue()
    {

    }

    void DoRightStartTaskBlue()
    {
        robot->claw->SetOpen();
        void* parameter = nullptr;

        double liftHeight = -17.8;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraightThrough(28.5, 0.0, 127.0);
        
        liftTask.remove();
        robot->lift->Stop();

        robot->claw->SetClosed();
        pros::delay(130);        

        robot->drive->DriveStraightThrough(-30.0, 0.0, 127.0);

        robot->drive->SetDrive(-40.0, -40.0);
        pros::delay(1000);
        robot->drive->SetDrive(0.0, 0.0);

        robot->lift->SetLift(127.0);
        pros::delay(2000);
        robot->lift->Stop();
    }

    void DoLeftStartTaskOrange()
    {
        *AutonController::taskComplete = false;
        robot->claw->SetOpen();
        void* parameter = nullptr;

        double liftHeight = -19.0;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraightThrough(20.0, 0.0, 127.0);
        
        liftTask.remove();
        robot->lift->Stop();

        robot->claw->SetClosed();
        pros::delay(130);        

        robot->drive->DriveStraightThrough(-30.0, 0.0, 127.0);

        robot->drive->SetDrive(-40.0, -40.0);
        pros::delay(1000);
        robot->drive->SetDrive(0.0, 0.0);

        robot->lift->SetLift(127.0);
        pros::delay(2000);
        robot->lift->Stop();
    }

    void DoMiddleStartTaskOrange()
    {
        robot->claw->SetOpen();
        void* parameter = nullptr;

        double liftHeight = -20.0;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraightThrough(2.0, 0.0, 127.0);
        robot->carrier->SetDown();
        robot->drive->DriveStraightThrough(22.0, 0.0, 127.0);
        
        liftTask.remove();
        robot->lift->Stop();

        robot->claw->SetClosed();
        pros::delay(130);        

        robot->drive->DriveStraightThrough(-25.0, 0.0, 127.0);
        robot->drive->DriveStraight(0.0, 0.0);

        robot->lift->SetLift(127.0);
        pros::delay(2000);
        robot->lift->Stop();
    }

    void DoRightStartTaskOrange()
    {
        robot->claw->SetOpen();
        void* parameter = nullptr;

        double liftHeight = -19.0;
        parameter = &liftHeight;
        pros::Task liftTask(LiftTask, parameter, "Lift task");

        robot->drive->DriveStraightThrough(20.5, 0.0, 127.0);
        
        liftTask.remove();
        robot->lift->Stop();

        robot->claw->SetClosed();
        pros::delay(130);        

        robot->drive->DriveStraightThrough(-30.0, 0.0, 127.0);

        robot->drive->SetDrive(-40.0, -40.0);
        pros::delay(1000);
        robot->drive->SetDrive(0.0, 0.0);

        liftHeight = 110.0;
        parameter = &liftHeight;
        pros::Task liftTask2(LiftTask, parameter, "Lift task");

        pros::delay(1000);
        liftTask2.remove();
        robot->lift->Stop();
    }

    void DoDistanceTask(double distance, double angle, double liftAngle, 
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
        pros::Task liftTask(HoldLiftTask, /*parameter,*/ "Lift task");

        robot->drive->DriveStraight(distance, angle);

        liftTask.remove();
        robot->lift->Stop();
        parameter = nullptr;
    }

    void DoThroughDistanceTask(double distance, double angle, double power, 
        double liftAngle, bool clawClosed, bool carrierDown, bool intake)
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
        pros::Task liftTask(HoldLiftTask, /*parameter,*/ "Lift task");

        robot->drive->DriveStraightThrough(distance, angle, power);

        liftTask.remove();
        robot->lift->Stop();
        parameter = nullptr;
    }

    void DoTurnTask(double targetAngle, double liftAngle,
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
        pros::Task liftTask(HoldLiftTask, /*parameter,*/ "Lift task");

        robot->drive->TurnToAngle(targetAngle);

        liftTask.remove();
        robot->lift->Stop();
        parameter = nullptr;
    }
}