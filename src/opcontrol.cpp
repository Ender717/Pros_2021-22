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
	// Create the robot
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	//Autons::RightAuton();
	
	Robot::liftPID.SetTargetValue(Robot::lift.GetPosition());
	
	pros::screen::erase();
	
	while(true)
	{
		Robot::DriveControl(master);

		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "Distance: %f", Robot::drive.GetDistance());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Y: %f", Robot::position.GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Theta: %f", Robot::position.GetTheta());
	}
}