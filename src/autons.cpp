#include "autons.h"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 2;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkills()
    {
        Robot::Initialize();

        // Run the routine
        Robot::drive.SetLeftDrive(127.0);
        Robot::drive.SetRightDrive(127.0);
    }
}