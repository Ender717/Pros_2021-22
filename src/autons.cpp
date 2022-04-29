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
        // Start the routine
        AutonController::DoRightStartTaskBlue();
        pros::delay(100);

        // Reset against the side wall
        AutonController::DoDistanceTask(6.0, 0.0, 110.0, true, false, false);
        AutonController::DoTurnTask(90.0, 110.0, true, false, false);
        AutonController::DoDistanceTask(-20.0, 90.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(-1.0, 90.0, 40.0, 110.0, true, false, false);
        pros::delay(400);

        // Grab the goal
        AutonController::DoDistanceTask(4.0, 90.0, 110.0, true, false, false);
        AutonController::DoTurnTask(180.0, 110.0, true, false, false);
        AutonController::DoDistanceTask(-4.0, 180.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-1.0, 180.0, 40.0, 110.0, true, true, false);
        pros::delay(400);
        AutonController::DoDistanceTask(-1.0, 180.0, 110.0, true, false, false);
        pros::delay(100);

        // Get match load rings
        for (int i = 0; i < 2; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, false, true);
        }
        AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
        pros::delay(400);

        // Align against the side wall
        AutonController::DoDistanceTask(-6.0, 180.0, 110.0, true, false, false);
        AutonController::DoTurnTask(270.0, 110.0, true, false, false);
        AutonController::DoDistanceTask(4.0, 270.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(1.0, 270.0, 40.0, 110.0, true, false, false);
        pros::delay(400);

        // Grab the field rings
        AutonController::DoDistanceTask(-16.0, 270.0, 110.0, true, false, false);
        AutonController::DoTurnTask(360.0, 110.0, true, false, false);
        AutonController::DoDistanceTask(24.0, 360.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(15.0, 270.0, 30.0, 110.0, true, false, true);
        AutonController::DoDistanceTask(-34.0, 360.0, 110.0, true, false, false);
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