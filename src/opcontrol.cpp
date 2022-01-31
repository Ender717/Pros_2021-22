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
	Drive* drive = new Drive();
	Carrier* carrier = new Carrier();
	Lift* lift = new Lift();
	Claw* claw = new Claw();
	
	// Initialize the processes
	drive->Initialize();
	carrier->Initialize();
	lift->Initialize();
	claw->Initialize();
	PID carrierPID(3.5, 0.95, 0.1, 0.0, -125.0, 125.0, 85.0, 0.0);
	PID liftPID(4.3, 0.85, 0.43, 5.0, -power, power, (power / 1.5), height);
	PID clawPID(3.5, 0.35, 0.1, 0.0, -125.0, 125.0, 85.0, 0.0);
	PositionCalculation position(0.0, 0.0, 0.0);

	// Create the control variables
	float leftDrivePower, rightDrivePower, carrierPower, liftPower, clawPower;
	bool clawClosed = false;

	// Run the driver control loop
	while (true) 
	{
		// Update and display the coordinate system
		position.UpdatePosition();
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "X: %f", position.GetX());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Y: %f", position.GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Theta: %f", position.GetTheta());

		// Calculate the power level of each motor
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		carrierPower = (master.get_digital(E_CONTROLLER_DIGITAL_Y) - master.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) * 127;
		liftPower = (master.get_digital(E_CONTROLLER_DIGITAL_L1) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 127;

		// Update the claw position
		if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
			clawClosed = false;
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
			clawClosed = true;

		// Set the drive
		drive->SetLeftDrive(leftDrivePower);
		drive->SetRightDrive(rightDrivePower);

		// Set the carrier
		if(carrierPower != 0)
		{
			carrier->SetCarrier(carrierPower);
			carrierPID.SetTargetValue(carrier->GetPosition());
		}
		else
			carrier->SetCarrier(carrierPID.GetControlValue(carrier->GetPosition()));
		
		// Set the lift
		if(liftPower != 0)
		{
			lift->SetLift(liftPower);
			liftPID.SetTargetValue(lift->GetHeight());
		}
		else
			lift->SetLift(liftPID.GetControlValue(lift->GetHeight()));

		// Set the claw
		if(clawClosed)
		{
			clawPID.SetTargetValue(8000.0);
			claw->SetClaw(clawPID.GetControlValue(claw->GetPosition()));
		}
		else
		{
			clawPID.SetTargetValue(5000.0);
			claw->SetClaw(clawPID.GetControlValue(claw->GetPosition()));
		}
		
		pros::delay(5);
	}

	// Deallocate pointers
	delete drive;
	delete carrier;
	delete lift;
	delete claw;
}
