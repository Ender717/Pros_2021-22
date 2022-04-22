#include "autons.hpp"

void PositionTask()
{
    while (true)
    {
        AutonController::robot->drive->UpdatePosition();
        pros::Task::delay(10);
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
        pros::Task positionTask(PositionTask);
    }

    void ProgrammingSkills2()
    {

    }

    void LeftAuton()
    {
        AutonController::robot->drive->SetPosition(17.5, -36.0, 0.0);
        pros::Task positionTask(PositionTask);

        AutonController::DoStartTask();
        //AutonController::DoDistanceTask(30.1, -18.0, false, false, false);

        positionTask.remove();
    }

    void MiddleAuton()
    {

    }

    void RightAuton()
    {

    }
}