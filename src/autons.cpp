#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 3;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills()
    {
        // Run the routine
        Robot::drive.SetLeftDrive(127.0);
        Robot::drive.SetRightDrive(127.0);
    }
}