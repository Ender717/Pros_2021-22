#include "autons.hpp"

void PositionTask()
{
    while (true)
    {
        AutonController::robot->drive->UpdatePosition();
        pros::Task::delay(20);
    }
}

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 8;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkillsBlue()
    {
        //pros::Task positionTask(PositionTask);
    }

    void ProgrammingSkillsOrange()
    {

    }

    void LeftAutonBlue()
    {
        //AutonController::robot->drive->SetPosition(-54.5, -36.0, 0.0);
        //pros::Task positionTask(PositionTask);

        AutonController::DoLeftStartTaskBlue();
        AutonController::DoDistanceTask(5.5, 6.0, 110.0, true, false, false);
        AutonController::DoTurnTask(96.0, 110.0, true, true, false);
        AutonController::DoGoalTask();
        pros::delay(100);

        //positionTask.remove();
    }

    void MiddleAutonBlue()
    {
        AutonController::DoMiddleStartTaskBlue();
    }

    void RightAutonBlue()
    {
        AutonController::DoRightStartTaskBlue();
        pros::delay(100);
        AutonController::DoDistanceTask(33.5, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(75.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoDistanceTask(-10.5, 75.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoGoalTask();
        pros::delay(100);
        AutonController::DoTurnTask(180.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(10.0, 180.0, 110.0, true, false, true);
        pros::delay(2000);
        AutonController::DoMatchLoads();
        pros::delay(100);
        AutonController::DoRingTask();
        pros::delay(100);
        AutonController::DoDistanceTask(-10.0, 180.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoRingTask();
        pros::delay(100);
        AutonController::DoDistanceTask(-17.0, 270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(360.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoDistanceTask(16.0, 360.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoRingTask();
        pros::delay(100);
        AutonController::DoDistanceTask(-30.0, 0.0, 110.0, true, false, true);
    }

    void LeftAutonOrange()
    {
        //AutonController::robot->drive->SetPosition(-54.5, -36.0, 0.0);
        //pros::Task positionTask(PositionTask);

        AutonController::DoLeftStartTaskOrange();
        AutonController::DoDistanceTask(5.5, 6.0, 110.0, true, false, false);
        AutonController::DoTurnTask(96.0, 110.0, true, true, false);
        AutonController::DoGoalTask();
        pros::delay(100);

        //positionTask.remove();
    }

    void MiddleAutonOrange()
    {
        AutonController::DoMiddleStartTaskOrange();
    }

    void RightAutonOrange()
    {
        AutonController::DoRightStartTaskOrange();
        AutonController::DoDistanceTask(33.5, 0.0, 110.0, true, false, false);
        AutonController::DoTurnTask(75.0, 110.0, true, true, false);
        AutonController::DoDistanceTask(-9.5, 75.0, 110.0, true, true, false);
        AutonController::DoGoalTask();
        pros::delay(100);
        AutonController::DoTurnTask(180.0, 110.0, true, false, false);
    }
}