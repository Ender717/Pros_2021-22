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
	Carrier* carrier = new Carrier();
	pros::Motor clawMotor(15, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
	pros::Motor leftArmMotor(17, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
	pros::Motor rightArmMotor(7, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);
	clawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftArmMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightArmMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	
	drive->Initialize();
	carrier->Initialize();
	PositionCalculation position(0.0, 0.0, 0.0);

	float leftDrivePower, rightDrivePower;
	while (true) 
	{
		
		position.UpdatePosition();
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "X: %f", position.GetX());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Y: %f", position.GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Theta: %f", position.GetTheta());

		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		drive->SetLeftDrive(leftDrivePower);
		drive->SetRightDrive(rightDrivePower);
		leftArmMotor.move((master.get_digital(E_CONTROLLER_DIGITAL_L1) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 125);
		rightArmMotor.move((master.get_digital(E_CONTROLLER_DIGITAL_L1) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 125);
		clawMotor.move((master.get_digital(E_CONTROLLER_DIGITAL_R1) - master.get_digital(E_CONTROLLER_DIGITAL_R2)) * 125);
		carrier->SetCarrier((master.get_digital(E_CONTROLLER_DIGITAL_Y) - master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) * 125);
		
		pros::delay(2);
	}
	delete drive;
}
