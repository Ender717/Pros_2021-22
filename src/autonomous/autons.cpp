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
        LeftAutonBlue();

        AutonController::DoDistanceTask(5.0, 101.0, 110.0, true, false, true);
        pros::delay(1000);
        AutonController::DoTurnTask(-34.0, 110.0, true, false, false);
        pros::delay(10000);
        AutonController::DoDistanceTask(90.0, -34.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(-15.0, -34.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(56.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(50.0, 56.0, 110.0, true, false, false);
    }

    void ProgrammingSkillsOrange()
    {
        // Start the routine
        AutonController::DoRightStartTaskOrange();
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
        AutonController::DoDistanceTask(-26.3, -90.0, 110.0, true, false, true);
        pros::delay(100);
        AutonController::DoTurnTask(0.0, 110.0, true, false, true);
        pros::delay(100);

        AutonController::DoDistanceTask(90.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(10.0, -45.0, 110.0, true, false, false);
        pros::delay(200);
        AutonController::DoTurnTask(0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(5.0, 0.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);
        AutonController::DoDistanceTask(-4.0, 0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(36.0, 90.0, 127.0, 110.0, true, false, false);
        AutonController::DoDistanceTask(3.0, 90.0, 110.0, true, false, false);
        while (true)
        {
            AutonController::DoDistanceTask(0.0, 90.0, 110.0, true, false, false);
        }
    }

    void LeftAutonBlue()
    {
        // Start the routine
        AutonController::DoLeftStartTaskBlue();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(98.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 98.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(-14.0, 98.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(188.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(12.0, 188.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(2.0, 188.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-6.5, 188.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(98.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-7.0, 98.0, 20.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(-2.0, 98.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, 98.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, 98.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, 98.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, 98.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoDistanceTask(5.0, 98.0, 110.0, true, false, true);
        pros::delay(1000);
        AutonController::DoDistanceTask(0.0, 98.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 98.0, 110.0, true, true, false);
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
        AutonController::DoDistanceTask(15.0, -90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(2.0, -90.0, 40.0, 110.0, true, false, false);
        pros::delay(800);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-6.7, -90.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-180.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-13.0, -180.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -180.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoTurnTask(0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(0.0, 0.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 0.0, 110.0, true, true, false);
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
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoTurnTask(0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(0.0, 0.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 0.0, 110.0, true, true, false);
    }

    void LeftAutonOrange()
    {
        // Start the routine
        AutonController::DoLeftStartTaskOrange();
        pros::delay(100);

        // Align against the side wall
        AutonController::DoTurnTask(101.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(15.0, 101.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the back wall
        AutonController::DoDistanceTask(-15.0, 101.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(191.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(12.0, 191.0, 110.0, true, false, false);
        AutonController::DoThroughDistanceTask(2.0, 191.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-4.3, 191.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(101.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-7.0, 101.0, 20.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(-2.0, 101.0, 110.0, true, false, false);
        pros::delay(100);

        // Do match loads
        AutonController::DoDistanceTask(5.0, 101.0, 110.0, true, false, false);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, 101.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, 101.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, 101.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoDistanceTask(5.0, 101.0, 110.0, true, false, true);
        pros::delay(1000);
        AutonController::DoDistanceTask(0.0, 101.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 101.0, 110.0, true, true, false);
    }

    void MiddleLeftAutonOrange()
    {
        // Start the routine
        AutonController::DoMiddleLeftStartTaskOrange();
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
        AutonController::DoDistanceTask(5.0, 70.0, 110.0, true, false, true);
        pros::delay(1000);
        AutonController::DoDistanceTask(0.0, 70.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 70.0, 110.0, true, true, false);
    }

    void MiddleRightAutonOrange()
    {
        // Start the routine
        AutonController::DoMiddleLeftStartTaskOrange();
        pros::delay(100);

        // Align against the back wall
        AutonController::DoTurnTask(70.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoDistanceTask(-23.0, 70.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-18.0, -20.0, 40.0, 110.0, true, false, false);
        pros::delay(1000);

        // Align against the second wall
        AutonController::DoDistanceTask(6.0, -20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(15.0, -110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(2.0, -110.0, 40.0, 110.0, true, false, false);
        pros::delay(800);

        // Grab the alliance goal
        AutonController::DoDistanceTask(-6.0, -110.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoTurnTask(-200.0, 110.0, true, true, false);
        pros::delay(100);
        AutonController::DoThroughDistanceTask(-13.0, -200.0, 40.0, 110.0, true, true, false);
        AutonController::DoThroughDistanceTask(-2.0, -200.0, 40.0, 110.0, true, false, false);

        // Do match load rings
        AutonController::DoDistanceTask(4.0, -200.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -200.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -200.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -200.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoTurnTask(-20.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(0.0, -20.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, -20.0, 110.0, true, true, false);
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

        AutonController::DoDistanceTask(4.0, -180.0, 110.0, true, false, true);
        pros::delay(1000);
        for (int i = 0; i < 4; i++)
        {
            AutonController::DoThroughDistanceTask(14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoThroughDistanceTask(-14.0, -180.0, 30.0, 110.0, true, false, true);
            AutonController::DoDistanceTask(0.0, -180.0, 110.0, true, false, true);
            pros::delay(600);
        }
        AutonController::DoTurnTask(0.0, 110.0, true, false, false);
        pros::delay(100);
        AutonController::DoDistanceTask(0.0, 0.0, 110.0, true, true, false);
        pros::delay(500);
        AutonController::DoDistanceTask(5.0, 0.0, 110.0, true, true, false);
    }
}