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

	float leftDrivePower, rightDrivePower;
	Drive::Initialize;
	//pros::delay(3000);

	while (true) 
	{
		Drive::UpdatePosition();
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 60, "x: %f", Drive::GetX());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 120, "y: %f", Drive::GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 180, "theta: %f", Drive::GetTheta());

		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		Drive::SetLeftDrive(leftDrivePower);
		Drive::SetRightDrive(rightDrivePower);

		//robot->drive->UpdatePosition();

		//pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE, 100, 200, "x: ");
		//pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE, 125, 200, std::to_string(robot->drive->GetX()));
		//pros::lcd::set_text(2, "y: " + std::to_string(robot->drive->GetY()));
		//pros::lcd::set_text(3, "angle: " + std::to_string(robot->drive->GetTheta()));

		pros::delay(2);
	}
}
