#include "autons.hpp"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 5;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills1()
    {
        AutonController control(-60.0, 46.0, 90.0);

        // Grab the goal
        control.DoPositionTask(-60.0, 44.0, 127.0, 110.0, true, true, false);
        pros::delay(50);

        control.DoPositionTask(-60.0, 51.0, 127.0, 110.0, true, false, false);
        pros::delay(50);

        control.DoTurnTask(-5.0, 127.0, 110.0, false, false, false);
        pros::delay(50);

        control.DoPositionTask(45.0, 40.0, 127.0, 110.0, false, false, true);
        pros::delay(50);

        control.DoPositionTask(40.0, 40.0, 127.0, 110.0, false, false, true);
        pros::delay(50);

        control.DoTurnTask(30.0, 127.0, 110.0, false, false, false);
        pros::delay(50);

        control.DoPositionTask(60.0, 67.0, 127.0, 110.0, false, true, true);
        pros::delay(50);

        control.DoTurnTask(0.0, 127.0, 110.0, false, true, false);
        pros::delay(50);

        control.DoPositionTask(-40.0, 67.0, 127.0, 110.0, false, false, true);
        pros::delay(50);

        /*
        control.DoPositionTask(-30.0, 40.0, 127.0, 70.0, false, false, true);
        pros::delay(50);

        control.DoTurnTask(0.0, 127.0, 0.0, false, false, false);
        pros::delay(50);

        control.DoPositionTask(-15.0, 46.0, 127.0, -20.0, false, false, false);
        pros::delay(50);

        control.DoTurnTask(0.0, 127.0, -17.0, false, false, false);
        pros::delay(50);

        control.DoPositionTask(-9.0, 46.0, 127.0, -20.0, true, false, false);
        pros::delay(50);

        control.DoPositionTask(0.0, 32.0, 127.0, 110.0, true, false, false);
        pros::delay(50);

        control.DoPositionTask(24.0, 8.0, 127.0, 110.0, true, false, false);
        pros::delay(50);

        control.DoTurnTask(0.0, 127.0, 110.0, true, false, false);
        pros::delay(50);

        control.DoPositionTask(40.0, 0.0, 127.0, 110.0, true, false, false);
        pros::delay(50);
        */
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