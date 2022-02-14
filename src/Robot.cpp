// Included libraries
#include "Robot.h"

namespace Robot
{
    // Variables
    float leftDrivePower;
    float rightDrivePower;
    float liftPower;

    // Processes
	PID liftPID(2.3, 0.05, 0.05, 0.0, -127.0, 127.0, 70.0, 0.0);

    // Subsystems
    Drive drive(0.0, 0.0, 0.0);
	Carrier carrier(false);
	Lift lift(1);
	Claw claw(true);
	Intake intake(127.0);

    void Initialize()
    {
        // Initialize the variables
        leftDrivePower = 0.0;
        rightDrivePower = 0.0;

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
		// Update the coordinate system
		drive.UpdatePosition();

		// Update the drive
		leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
		drive.SetDrive(leftDrivePower, rightDrivePower);

		// Update the claw
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
		{
			if(claw.IsClosed())
                claw.SetOpen();	
			else
                claw.SetClosed();
		}
		claw.HoldPosition();

		// Update the carrier
		if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
		{
			if(carrier.IsDown())
				carrier.SetUp();
			else
				carrier.SetDown();
		}

		// Update the intake
		if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
			intake.Intake();
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
			intake.Outtake();
		else
			intake.Stop();
		
		// Update the lift
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
		
		pros::delay(5);
	}
}