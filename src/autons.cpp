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
        AutonController::DoDistanceTask(33.5, 0.0, 110.0, true, false, false);
        AutonController::DoTurnTask(75.0, 110.0, true, true, false);
        AutonController::DoDistanceTask(-9.5, 75.0, 110.0, true, true, false);
        AutonController::DoGoalTask();
        pros::delay(100);
        AutonController::DoTurnTask(180.0, 110.0, true, false, false);
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