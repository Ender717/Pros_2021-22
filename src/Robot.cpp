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
    PositionCalculation position(0.0, 0.0, 0.0);

    // Subsystems
    Drive drive(1);
	Carrier carrier(1);
	Lift lift(1);
	Claw claw(1);
	Intake intake(1);

    void Initialize()
    {
        // Initialize the variables
        leftDrivePower = 0.0;
        rightDrivePower = 0.0;
        intakePower = 0.0;
        clawClosed = true;
        carrierDown = false;

        // Initialize the processes
        liftPID.SetTargetValue(0.0);

        // Initialize the subsystems
        drive.Initialize();
        carrier.Initialize();
        lift.Initialize();
        claw.Initialize();
        intake.Initialize();
    }

    void DriveControl(pros::Controller& master)
    {
		// Update and display the coordinate system
		position.UpdatePosition();

		// Calculate the power level of each motor
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
					- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
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
				carrier.SetDown();
				carrierDown = true;
			}
		}
		
		// Set the lift
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1) && (lift.GetPosition() < LiftConfig::TOP_POSITION))
		{
			lift.SetLift(127.0);
			liftPID.SetTargetValue(lift.GetPosition());
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2) && (lift.GetPosition() > LiftConfig::BOTTOM_POSITION))
		{
			lift.SetLift(-127.0);
			liftPID.SetTargetValue(lift.GetPosition());
		}
		else
			lift.SetLift(liftPID.GetControlValue(lift.GetPosition()));
			

		// Set the claw
        if(clawClosed)
		{
			if(claw.GetPosition() > ClawConfig::CLOSED_POSITION)
				claw.SetClaw(-125.0);
			else
				claw.SetClaw(0.0);
		}
		else
		{
			if(claw.GetPosition() < ClawConfig::OPEN_POSITION)
				claw.SetClaw(125.0);
			else
				claw.SetClaw(0.0);
		}

        // Set the intake
		intake.SetIntake(intakePower);
		
		pros::delay(5);
	}
}