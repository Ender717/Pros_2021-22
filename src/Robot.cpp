// Included libraries
#include "Robot.h"

// Constructor definitions ----------------------------------------------------
Robot::Robot(RobotColor color) :
    drive(0.0, 0.0, 0.0),
	carrier(false),
	lift(70.0),
	claw(true),
	intake(127.0)
{
	robotColor = color;
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
	float leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	float rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
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

	Menu::DrawPosition(drive.GetX(), drive.GetY(), drive.GetTheta());

	// Delay for the next loop
	pros::delay(5);
}