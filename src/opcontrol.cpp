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
	Intake* intake = new Intake();
	
	// Initialize the processes
	drive->Initialize();
	carrier->Initialize();
	lift->Initialize();
	claw->Initialize();
	intake->Initialize();
	PID carrierPID(2.1, 0.15, 0.05, 0.0, -127.0, 127.0, 85.0, 0.0);
	PID liftPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 70.0, 0.0);
	PID clawPID(1.7, 0.05, 0.05, 0.0, -127.0, 127.0, 65.0, 0.0);
	PID intakePID(1.7, 0.05, 0.05, 0.0, -127.0, 127.0, 65.0, 0.0);
	PositionCalculation position(0.0, 0.0, 0.0);

	// Create the control variables
	float leftDrivePower, rightDrivePower, intakePower, liftPower, clawPower;
	bool clawClosed = false;
	bool carrierUp = false;

	// Run the driver control loop
	while (true) 
	{
		// Update and display the coordinate system
		//position.UpdatePosition();
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "Lift: %f", LiftConfig::leftLiftMotor.get_position());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Claw: %f", ClawConfig::clawMotor.get_position());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Theta: %f", position.GetTheta());

		// Calculate the power level of each motor
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		liftPower = (master.get_digital(E_CONTROLLER_DIGITAL_R1) - master.get_digital(E_CONTROLLER_DIGITAL_R2)) * 127;
		intakePower = (master.get_digital(E_CONTROLLER_DIGITAL_L1) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 127;

		// Set the drive
		drive->SetLeftDrive(leftDrivePower);
		drive->SetRightDrive(rightDrivePower);

		// Update the carrier position
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
		{
			if(carrierUp)
			{
				carrierUp = false;
				carrier->SetDown();
			}	
			else
			{
				carrierUp = true;
				carrier->SetUp();
			}	
		}

		// Update the claw position
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
		{
			if(clawClosed)
				clawClosed = false;
			else
				clawClosed = true;
		}
		
		// Set the lift
		if(liftPower != 0)
		{
			lift->SetLift(liftPower);
			liftPID.SetTargetValue(lift->GetPosition());
		}
		else
			lift->SetLift(liftPID.GetControlValue(lift->GetPosition()));

		// Set the claw
		if(clawClosed)
		{
			clawPID.SetTargetValue(5.0);
			claw->SetClaw(clawPID.GetControlValue(claw->GetPosition()));
		}
		else
		{
			clawPID.SetTargetValue(500.0);
			claw->SetClaw(clawPID.GetControlValue(claw->GetPosition()));
		}

		// Set the intake
		if(intakePower != 0)
		{
			intake->SetIntake(intakePower);
			intakePID.SetTargetValue(intake->GetPosition());
		}
		else
			intake->SetIntake(intakePID.GetControlValue(intake->GetPosition()));
		
		pros::delay(5);
	}

	// Deallocate pointers
	delete drive;
	delete carrier;
	delete lift;
	delete claw;
}
