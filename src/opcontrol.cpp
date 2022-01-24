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
	Robot* robot = new Robot();

	float leftDrivePower, rightDrivePower;
	robot->Initialize();

	while (true) 
	{
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		robot->drive->SetLeftDrive(leftDrivePower);
		robot->drive->SetRightDrive(rightDrivePower);

		robot->drive->UpdatePosition();
		pros::lcd::set_text(1, "x: " + std::to_string(robot->drive->GetX()));
		pros::lcd::set_text(2, "y: " + std::to_string(robot->drive->GetY()));
		pros::lcd::set_text(3, "angle: " + std::to_string(robot->drive->GetTheta()));

		pros::delay(2);
	}
}
