#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 5;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills1()
    {
        AutonController control(-60.0, 45.0, 90.0);

        // Grab the goal
        control.DoPositionTask(-60.0, 42.0, 100.0, 110.0, true, true, false);
        pros::delay(250);

        control.DoPositionTask(-60.0, 56.0, 110.0, 110.0, true, false, false);
        pros::delay(250);

        control.DoPositionTask(-30.0, 36.0, 110.0, 0.0, false, false, true);
        pros::delay(250);

        control.DoTurnTask(0.0, 110.0, 0.0, false, false, false);
        pros::delay(250);

        control.DoPositionTask(-15.0, 36.0, 110.0, -17.0, false, false, false);
        pros::delay(250);

        control.DoPositionTask(-10.0, 36.0, 110.0, -17.0, true, false, false);
        pros::delay(250);

        control.DoPositionTask(0.0, 36.0, 110.0, 110.0, true, false, false);
        pros::delay(250);
    }

    void ProgrammingSkills2()
    {

    }

    void LeftAuton()
    {

    }

    void MiddleAuton()
    {

    }

    void RightAuton()
    {

    }
}