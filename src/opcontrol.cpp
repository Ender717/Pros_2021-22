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
	// Create the robot and controller
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	Robot* robot = RobotState::robot;
	AutonController::robot = RobotState::robot;
	pros::screen::erase();

	if (master.get_digital(E_CONTROLLER_DIGITAL_Y))
	{
		AutonController::DoDistanceTask(30, -8.0, false, false, false);
		AutonController::DoDistanceTask(1, -10.0, false, false, false);
		AutonController::DoDistanceTask(4, -10.0, true, false, false);
		AutonController::DoDistanceTask(-34, -10.0, true, false, false);
	}
		
	while(true)
	{
		robot->RobotControl(master);
		Menu::DrawPosition(robot);
	}

	delete robot;
}