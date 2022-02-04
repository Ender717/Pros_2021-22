#include "autonomous.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
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

    //drive->DriveStraight(10.0, 127.0, position);
    //drive->TurnToAngle(90.0, 127.0, position);
    //lift->SetPosition(-3000.0);
    claw->SetClosed();
}