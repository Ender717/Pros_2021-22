#include "autonomous/autons.hpp"
#include "autonomous/AutonController.hpp"

namespace Autons
{
    // Constants
    const int NUM_AUTONS = 8;

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
        AutonController::DoDistanceTask(5.5, 6.0, 110.0, true, false, false);
        AutonController::DoTurnTask(96.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(15.0, 96.0, 40.0, 110.0, true, false, false);
        pros::delay(500);

        // Back up and grab the alliance goal
        AutonController::DoDistanceTask(-16.5, 96.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-5.0, 96.0, 30.0, 110.0, true, false, false);
        pros::delay(300);
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, true, false);
        pros::delay(100);

        // Do match load rings
        for (int i = 0; i < 6; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, false, true);
        }
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, false, true);
        pros::delay(2000);
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, false, false);
    }

    void MiddleAutonBlue()
    {
        // Start the routine
        AutonController::DoMiddleStartTaskBlue();
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(10.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(90.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-15.0, 75.0, 40.0, 110.0, true, true, false);
        pros::delay(500);

        // Grab the alliance goal
        AutonController::DoDistanceTask(5.0, 90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, 180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(10.0, 180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 2; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, false, true);
        }
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 180.0, 40.0, 110.0, true, false, true);
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(-10.0, 180.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 270.0, 40.0, 110.0, true, false, true);
        pros::delay(500);

        // Align with the field rings
        AutonController::DoDistanceTask(-17.0, 270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(360.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoDistanceTask(16.0, 360.0, 110.0, true, false, true);
        pros::delay(100);

        // Grab the field rings
        AutonController::DoThroughDistanceTask(15.0, 360.0, 30.0, 110.0, true, false, true);;
        pros::delay(100);
        AutonController::DoDistanceTask(-30.0, 0.0, 110.0, true, false, true);
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
        AutonController::DoDistanceTask(15.0, -90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(2.0, -90.0, 40.0, 110.0, true, false, false);
        pros::delay(800);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-6.0, -90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-13.0, -180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 2; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(500);
        }
        pros::delay(100);
        AutonController::DoThroughDistanceTask(10.0, -180.0, 30.0, 110.0, true, false, true);
        pros::delay(500);

        // Align against the second wall
        AutonController::DoDistanceTask(-10.0, -180.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(-90.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(1.0, -90.0, 40.0, 110.0, true, false, true);
        pros::delay(1000);

        // Align with the field rings
        AutonController::DoDistanceTask(-16.3, -90.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(0.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoDistanceTask(15.0, 0.0, 110.0, true, false, true);
        pros::delay(100);

        // Grab the field rings
        AutonController::DoThroughDistanceTask(20.0, 0.0, 30.0, 110.0, true, false, true);;
        pros::delay(100);
        AutonController::DoDistanceTask(-30.0, 0.0, 110.0, true, false, true);
        AutonController::DoDistanceTask(0.0, 0.0, 110.0, true, false, true);
    }

    void LeftAutonOrange()
    {
        // Start the routine
        AutonController::DoLeftStartTaskOrange();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoDistanceTask(5.5, 6.0, 110.0, true, false, false);
        AutonController::DoTurnTask(96.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(15.0, 96.0, 40.0, 110.0, true, false, false);
        pros::delay(500);

        // Back up and grab the alliance goal
        AutonController::DoDistanceTask(-16.5, 96.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-5.0, 96.0, 30.0, 110.0, true, false, false);
        pros::delay(300);
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, true, false);
        pros::delay(100);

        // Do match load rings
        for (int i = 0; i < 6; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, false, true);
        }
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, false, true);
        pros::delay(2000);
        AutonController::DoDistanceTask(0.0, 96.0, 110.0, true, false, false);
    }

    void MiddleAutonOrange()
    {
        // Start the routine
        AutonController::DoMiddleStartTaskOrange();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(70.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoDistanceTask(55.0, 70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(40.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(13.0, 40.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(-13.0, 40.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(10.0, 70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(2.0, 70.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(-15.0, 70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(160.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(12.0, 160.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(2.0, 160.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-5.0, 160.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(70.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-7.0, 70.0, 20.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(-2.0, 70.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, 70.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, 70.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, 70.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, 70.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoDistanceTask(0.0, 70.0, 110.0, true, false, true);
        pros::delay(1000);
        AutonController::DoDistanceTask(0.0, 70.0, 110.0, true, false, false);
    }

    void RightAutonOrange()
    {
        // Start the routine
        AutonController::DoRightStartTaskOrange();
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(10.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(90.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-15.0, 75.0, 40.0, 110.0, true, true, false);
        pros::delay(500);

        // Grab the alliance goal
        AutonController::DoDistanceTask(5.0, 90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, 180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(10.0, 180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 2; i++)
        {
            AutonController::DoThroughDistanceTask(10.0, 180.0, 40.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-10.0, 180.0, 40.0, 110.0, true, false, true);
        }
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 180.0, 40.0, 110.0, true, false, true);
        pros::delay(100);

        // Align against the second wall
        AutonController::DoDistanceTask(-10.0, 180.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 270.0, 40.0, 110.0, true, false, true);
        pros::delay(500);

        // Align with the field rings
        AutonController::DoDistanceTask(-17.0, 270.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(360.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoDistanceTask(16.0, 360.0, 110.0, true, false, true);
        pros::delay(100);

        // Grab the field rings
        AutonController::DoThroughDistanceTask(15.0, 360.0, 30.0, 110.0, true, false, true);;
        pros::delay(100);
        AutonController::DoDistanceTask(-30.0, 0.0, 110.0, true, false, true);
    }
}