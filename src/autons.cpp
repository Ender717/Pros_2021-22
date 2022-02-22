#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 5;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills1(Robot& robot)
    {
        AutonController control(-55.0, -36.0, 0.0);

        // Move forward
        control.DoPositionTask(-15.0, -36.0, 110.0, -17.0, false, false, false);

        // Grab the neutral goal
        control.DoPositionTask(-10.0, -36.0, 30.0, -17.0, true, false, false);

        // Move backward
        control.DoPositionTask(-36.0, -36.0, 127.0, 110.0, true, false, false);

        // Turn toward the alliance goal
        control.DoTurnTask(90.0, 127.0, 110.0, true, true, false);

        // Move backward
        control.DoPositionTask(-36.0, -45.0, 127.0, 110.0, true, true, false);

        // Grab the alliance goal
        control.DoPositionTask(-36.0, -50.0, 30.0, 110.0, true, true, false);

        // Align with the tiles
        control.DoPositionTask(-36.0, -48.0, 30.0, 110.0, true, false, false);

        // Turn toward the wall
        control.DoTurnTask(180.0, 127.0, 110.0, true, false, false);

        // Wait for the match loads
        pros::delay(10000);

        // Grab the match loads
        control.DoPositionTask(-10.0, -48.0, 40.0, 110.0, true, false, true);
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