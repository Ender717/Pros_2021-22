// Included libraries
#include "Robot.h"

namespace Robot
{
    // Variables
    float leftDrivePower;
    float rightDrivePower;
    float liftPower;
    float intakePower;
    bool clawClosed;
    bool carrierDown;

    // Processes
	PID liftPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 70.0, 0.0);
	PID clawPID(1.7, 0.05, 0.05, 0.0, -127.0, 127.0, 65.0, 0.0);
    PositionCalculation position(0.0, 0.0, 0.0);

    // Subsystems
    Drive drive(1);
	Carrier carrier(1);
	Lift lift(1);
	Claw claw(1);
	Intake intake(1);

    void Initialize()
    {
        // Initialize the subsystems
        drive.Initialize();
        carrier.Initialize();
        lift.Initialize();
        claw.Initialize();
        intake.Initialize();

        // Initialize the variables
        leftDrivePower = 0.0;
        rightDrivePower = 0.0;
        liftPower = 0.0;
        intakePower = 0.0;
        clawClosed = false;
        carrierDown = false;
    }

    extern void DriveControl(pros::Controller& master)
    {
		// Update and display the coordinate system
		position.UpdatePosition();

		// Calculate the power level of each motor
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		liftPower = (master.get_digital(E_CONTROLLER_DIGITAL_R1) - master.get_digital(E_CONTROLLER_DIGITAL_R2)) * 127;
		intakePower = (master.get_digital(E_CONTROLLER_DIGITAL_L1) - master.get_digital(E_CONTROLLER_DIGITAL_L2)) * 127;

		// Update the claw position
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
		{
			if(clawClosed)
				clawClosed = false;
			else
				clawClosed = true;
		}
			
		// Set the drive
		drive.SetLeftDrive(leftDrivePower);
		drive.SetRightDrive(rightDrivePower);

		// Set the carrier
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
		{
			if(carrierDown)
			{
				carrier.SetUp();
				carrierDown = false;
			}
			else
			{
				carrier.SetUp();
				clawClosed = true;
			}
		}
		
		// Set the lift
		if(liftPower != 0)
		{
			lift.SetLift(liftPower);
			liftPID.SetTargetValue(lift.GetPosition());
		}
		else
			lift.SetLift(liftPID.GetControlValue(lift.GetPosition()));

		// Set the claw
		if(clawClosed)
		{
			clawPID.SetTargetValue(3000.0);
			claw.SetClaw(clawPID.GetControlValue(claw.GetPosition()));
		}
		else
		{
			clawPID.SetTargetValue(5.0);
			claw.SetClaw(clawPID.GetControlValue(claw.GetPosition()));
		}

		intake.SetIntake(intakePower);
		
		pros::delay(5);
	}
}