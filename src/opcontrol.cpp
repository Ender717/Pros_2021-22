#include "opcontrol.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() 
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	Drive* drive = new Drive();

	//float leftDrivePower, rightDrivePower;
	drive->SpinTurn(180.0);
	pros::delay(1000);
	drive->SpinTurn(-180.0);
	pros::delay(1000);
	while (true) 
	{
		/*
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 60, "x: %f", Drive::GetX());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 120, "y: %f", Drive::GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 180, "theta: %f", Drive::GetTheta());
		*/

		/*
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		Drive::SetLeftDrive(leftDrivePower);
		Drive::SetRightDrive(rightDrivePower);
		*/

		pros::delay(2);
	}
}
