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

	pros::Motor frontLeftDrive(18);
	pros::Motor rearLeftDrive(11);
	pros::Motor frontRightDrive(20, true);
	pros::Motor rearRightDrive(13, true);

	pros::Rotation leftEncoder(14);
	pros::Rotation centerEncoder(15);
	pros::Rotation rightEncoder(16);
	pros::Imu inertial(17);

	leftEncoder.set_position(0.0);
	rightEncoder.set_position(0.0);
	centerEncoder.set_position(0.0);

	float leftDrive, rightDrive;
	PID *basePID = new PID(2.66, 0.00, 0.16, -125.0, 125.0, 0.002, 0.0);
	PositionCalculation *pos = new PositionCalculation(0.0, 0.0, 0.0);
	float leftInches, rightInches, centerInches, inertialRadians, drivePower;
	// basePID->SetTargetValue(360.0);
	pros::delay(5000);

	while (true) 
	{
		leftDrive = (master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) 
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
		rightDrive = (master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) 
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
		
		frontLeftDrive.move(leftDrive);
		rearLeftDrive.move(leftDrive);
		frontRightDrive.move(rightDrive);
		rearRightDrive.move(rightDrive);

		leftInches = leftEncoder.get_position()*((2.807 * 3.1415) / 36000);
		rightInches = rightEncoder.get_position()*((2.807 * 3.1415) / -36000);
		centerInches = centerEncoder.get_position()*((2.807 * 3.1415) / -36000);
		inertialRadians = inertial.get_rotation() * (3.1415 / 180.0) * (360.0 / 355.3);
		pos->UpdatePosition(leftInches, rightInches, centerInches, inertialRadians);
		
		/*
		drivePower = basePID->GetControlValue(inertialRadians * (180.0 / 3.1415));
		frontLeftDrive.move(drivePower);
		rearLeftDrive.move(drivePower);
		frontRightDrive.move(-drivePower);
		rearRightDrive.move(-drivePower);
		*/

		pros::lcd::set_text(1, std::to_string(pos->getX()));
		pros::lcd::set_text(2, std::to_string(pos->getY()));
		pros::lcd::set_text(3, std::to_string(pos->getAngle() * 180 / 3.1415));

		pros::delay(2);
	}
}
