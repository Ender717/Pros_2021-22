#include "opcontrol.h"

void ClawTask(void* param)
{
	Robot* robot = (Robot*)param;
	robot->claw->GrabObject();
}

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
	// Create the robot and controller
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	Robot* robot = RobotState::robot;
	AutonController::robot = RobotState::robot;
	Menu::Erase(0, 0, 480, 272);
		
	while(true)
	{
		robot->RobotControl(master);
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 32, "Angle: %.2f", robot->drive->GetTheta());
	}

	delete robot;
}