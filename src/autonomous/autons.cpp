#include "autonomous/autons.hpp"
#include "autonomous/AutonController.hpp"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 9;

    // Variables
    int selectedAuton;

    // Functions
    void ProgrammingSkillsBlue()
    {

    }

    void ProgrammingSkillsOrange()
    {

    }

    void LeftAutonBlue()
    {
        // Start the routine
        AutonController::DoLeftStartTaskBlue();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(-82.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-10.0, -82.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(14.0, -82.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-172.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(12.0, -172.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.4, -172.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-262.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-5.0, -262.0, 25.0, 110.0, true, true, false);
        pros::delay(700);
        AutonController::DoDistanceTask(-2.0, -262.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, -262.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -262.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -262.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -262.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void MiddleAutonBlue()
    {
        // Start the routine
        AutonController::DoMiddleStartTaskBlue();
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(6.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, -90.0, 70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(2.0, -90.0, 30.0, 110.0, true, false, false);
        pros::delay(800);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, -90.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-16.0, -180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void RightAutonBlue()
    {
        // Start the routine
        AutonController::DoRightStartTaskBlue();
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(6.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(17.0, -90.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, -90.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-13.0, -180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void LeftAutonOrange()
    {
        // Start the routine
        AutonController::DoLeftStartTaskOrange();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(-82.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-10.0, -82.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(14.0, -82.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-172.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(12.0, -172.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.4, -172.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-262.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-5.0, -262.0, 20.0, 110.0, true, true, false);
        pros::delay(1000);
        AutonController::DoDistanceTask(-2.0, -262.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, -262.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -262.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -262.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -262.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void MiddleLeftAutonOrange()
    {
        // Start the routine
        AutonController::DoMiddleLeftStartTaskOrange();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(-110.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-40.0, -110.0, 60.0, 110.0, true, false, false);
        AutonController::robot->drive->SetDrive(0.0, 0.0);
        pros::delay(100);
        AutonController::DoTurnTask(-140.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-15.0, -140.0, 40.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(15.0, -140.0, 40.0, 110.0, true, false, false);
        AutonController::robot->drive->SetDrive(0.0, 0.0);
        pros::delay(100);
        AutonController::DoTurnTask(-110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-20.0, -110.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(14.0, -110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(160.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(12.0, 160.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, 160.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(70.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-5.0, 70.0, 20.0, 110.0, true, true, false);
        pros::delay(700);
        AutonController::DoDistanceTask(-2.0, 70.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, 70.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, 70.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, 70.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, 70.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void MiddleRightAutonOrange()
    {
        // Start the routine
        AutonController::DoMiddleLeftStartTaskOrange();
        pros::delay(500);

        // Align against the back wall
        AutonController::DoTurnTask(70.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-19.0, 70.0, 40.0, 110.0, true, false, false);
        AutonController::robot->drive->SetDrive(0.0, 0.0);
        pros::delay(100);
        AutonController::DoTurnTask(-20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-14.0, -20.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the second wall
        AutonController::DoDistanceTask(6.0, -20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(12.0, -110.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, -110.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-200.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-15.0, -200.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -200.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoThroughDistanceTask(6.0, -200.0, 40.0, 110.0, true, false, true);
        AutonController::robot->drive->SetDrive(0.0, 0.0);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -200.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -200.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -200.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }

    void RightAutonOrange()
    {
        // Start the routine
        AutonController::DoRightStartTaskOrange();
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(6.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(17.0, -90.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, -90.0, 110.0, true, false, false);
        pros::delay(500);
        AutonController::DoTurnTask(-180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-13.0, -180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 5; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
    }
}