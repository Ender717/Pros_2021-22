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
    const int NUM_AUTONS = 5;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills1()
    {
        //pros::Task positionTask(PositionTask);
    }

    void ProgrammingSkills2()
    {

    }

    void LeftAuton()
    {
        //AutonController::robot->drive->SetPosition(-54.5, -36.0, 0.0);
        //pros::Task positionTask(PositionTask);

        AutonController::DoStartTask();
        AutonController::DoDistanceTask(27.5, 0.0, 110.0, true, false, false);
        AutonController::DoTurnTask(90.0, 110.0, true, true, false);
        AutonController::DoDistanceTask(-8.0, 90.0, 110.0, true, true, false);
        AutonController::DoDistanceTask(-2.0, 90.0, 110.0, true, true, false);
        AutonController::DoDistanceTask(0.0, 90.0, 110.0, true, false, false);

        //positionTask.remove();
    }

    void MiddleAuton()
    {

    }

    void RightAuton()
    {

    }
}