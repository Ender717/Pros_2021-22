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
	pros::screen::erase();

	if (master.get_digital(E_CONTROLLER_DIGITAL_X))
	{
		//Autons::LeftAuton();
		Autons::RightAuton();
	}
		
	while(true)
	{
		robot->RobotControl(master);
		//Menu::DrawPosition(robot);
	}

	delete robot;
}