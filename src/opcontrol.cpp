#include "main.h"
#include "opcontrol.h"
#include "controllers/PositionCalculation.h"

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
	pros::Rotation leftEncoder(14);
	pros::Rotation centerEncoder(15);
	pros::Rotation rightEncoder(16);
	pros::Imu inertial(17);

	leftEncoder.set_position(0.0);
	rightEncoder.set_position(0.0);
	centerEncoder.set_position(0.0);

	PositionCalculation *pos = new PositionCalculation(0.0, 0.0, 0.0);
	float leftInches, rightInches, centerInches, inertialRadians;

	pros::delay(5000);

	while (true) 
	{
		leftInches = leftEncoder.get_position()*((2.807 * 3.1415) / 36000);
		rightInches = rightEncoder.get_position()*((2.807 * 3.1415) / -36000);
		centerInches = centerEncoder.get_position()*((2.807 * 3.1415) / -36000);
		inertialRadians = inertial.get_rotation() * 3.1415 / 180;

		pos->UpdatePosition(leftInches, rightInches, centerInches, inertialRadians);

		pros::lcd::set_text(1, std::to_string(pos->getX()));
		pros::lcd::set_text(2, std::to_string(pos->getY()));
		pros::lcd::set_text(3, std::to_string(pos->getAngle() * 180 / 3.1415));

		pros::delay(2);
	}
}
