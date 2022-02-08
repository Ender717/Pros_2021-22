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
        // Create the robot
	    Drive* drive = new Drive();
        Carrier* carrier = new Carrier();
        Lift* lift = new Lift();
        Claw* claw = new Claw();
        
        // Initialize the processes
        drive->Initialize();
        carrier->Initialize();
        lift->Initialize();
        claw->Initialize();
        PositionCalculation position(0.0, 0.0, 0.0);

        // Run the routine
        drive->SetLeftDrive(127.0);
        drive->SetRightDrive(127.0);
    }
}