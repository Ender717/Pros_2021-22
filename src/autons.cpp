#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 4;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills()
    {
        // Run the routine
        Robot::drive.SetDrive(127.0, 127.0);
        pros::delay(2000);
        Robot::drive.SetDrive(0.0, 0.0);
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