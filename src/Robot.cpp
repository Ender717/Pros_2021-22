// Included libraries
#include "Robot.h"

// Constructor definitions ----------------------------------------------------
Robot::Robot() :
    drive(),
	carrier(),
	lift(140.0),
	claw(true),
	intake(127.0)
{
	
}

// Private method definitions -------------------------------------------------
void Robot::UpdateCarrier(pros::Controller& master)
{
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
	{
		if(carrier.IsDown())
			carrier.SetUp();
		else
			carrier.SetDown();
	}
}

void Robot::UpdateClaw(pros::Controller& master)
{
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
	{
		if(claw.IsClosed())
			claw.SetOpen();	
		else
			claw.SetClosed();
	}
	claw.HoldPosition();
}

void Robot::UpdateDrive(pros::Controller& master)
{
	// Arcade drive mode
	float leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) 
						+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
	float rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
						- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

	/*
	// Tank drive mode
	float leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	float rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
	*/

	// Update
	drive.SetDrive(leftDrivePower, rightDrivePower);
	drive.UpdatePosition();
}

void Robot::UpdateIntake(pros::Controller& master)
{
	if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
		intake.Suck();
	else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
		intake.Blow();
	else
		intake.Stop();
}

void Robot::UpdateLift(pros::Controller& master)
{
	if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
		lift.Raise();
	else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
		lift.Lower();
	else
		lift.HoldPosition();
}

// Public method definitions --------------------------------------------------
void Robot::Initialize()
{
	carrier.Initialize();
	claw.Initialize();
	drive.Initialize();
	intake.Initialize();
	lift.Initialize();
}

void Robot::RobotControl(pros::Controller& master)
{
	UpdateCarrier(master);
	UpdateClaw(master);
	UpdateDrive(master);
	UpdateIntake(master);
	UpdateLift(master);

	// Delay for the next loop
	pros::delay(5);
}