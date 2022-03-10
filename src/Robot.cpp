// Included libraries
#include "Robot.h"

// Constructor definitions ----------------------------------------------------
Robot::Robot()
{
	/*
	PID::PIDBuilder pidBuilder;
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	PositionCalculation position;

	Carrier::CarrierBuilder carrierBuilder;
	carrier = carrierBuilder.WithPiston(OrangeConfig::carrier1Piston).
							 WithPiston(OrangeConfig::carrier2Piston).
							 Build();
	
	Claw::ClawBuilder clawBuilder;
	claw = clawBuilder.WithMotor(OrangeConfig::claw1Motor).
					   WithPID(clawPID).
					   WithOpenPosition(OrangeConfig::CLAW_OPEN_POSITION).
					   WithClosedPosition(OrangeConfig::CLAW_CLOSED_POSITION).
					   Build();

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(OrangeConfig::leftDrive1Motor).
						 WithLeftMotor(OrangeConfig::leftDrive2Motor).
						 WithLeftMotor(OrangeConfig::leftDrive3Motor).
						 WithRightMotor(OrangeConfig::rightDrive1Motor).
						 WithRightMotor(OrangeConfig::rightDrive2Motor).
						 WithRightMotor(OrangeConfig::rightDrive3Motor).
						 WithTrackingSensor(OrangeConfig::leftDriveTrackingSensor).
						 WithTrackingSensor(OrangeConfig::rightDriveTrackingSensor).
						 WithTrackingSensor(OrangeConfig::strafeDriveTrackingSensor).
						 WithDistancePID(distancePID).
						 WithAnglePID(anglePID).
						 WithTurnPID(turnPID).
						 WithPosition(position).
						 WithWheelSize(OrangeConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(OrangeConfig::intake1Motor).Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithLeftMotor(OrangeConfig::leftLift1Motor).
					   WithRightMotor(OrangeConfig::rightLift1Motor).
					   WithPID(liftPID).
					   WithTopAngle(OrangeConfig::LIFT_TOP_POSITION).
					   WithBottomAngle(OrangeConfig::LIFT_BOTTOM_POSITION).
					   WithStartAngle(OrangeConfig::LIFT_START_POSITION).
					   WithCountsPerDegree(OrangeConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
	*/

	PID::PIDBuilder pidBuilder;
	PID carrierPID = pidBuilder.WithKp(5.3).WithKi(0.5).WithKd(0.25).WithIntegralLimit(65.0).Build();
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	PositionCalculation position;

	Carrier::CarrierBuilder carrierBuilder;
	carrier = carrierBuilder.WithMotor(OldConfig::carrier1Motor).
							 WithMotor(OldConfig::carrier2Motor).
							 WithPID(carrierPID).
							 WithDownPosition(OldConfig::CARRIER_DOWN_POSITION).
							 WithUpPosition(OldConfig::CARRIER_UP_POSITION).
							 Build();
	
	Claw::ClawBuilder clawBuilder;
	claw = clawBuilder.WithMotor(OldConfig::claw1Motor).
					   WithPID(clawPID).
					   WithOpenPosition(OldConfig::CLAW_OPEN_POSITION).
					   WithClosedPosition(OldConfig::CLAW_CLOSED_POSITION).
					   Build();

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(OldConfig::leftDrive1Motor).
						 WithLeftMotor(OldConfig::leftDrive2Motor).
						 WithLeftMotor(OldConfig::leftDrive3Motor).
						 WithRightMotor(OldConfig::rightDrive1Motor).
						 WithRightMotor(OldConfig::rightDrive2Motor).
						 WithRightMotor(OldConfig::rightDrive3Motor).
						 WithTrackingSensor(OldConfig::leftDriveTrackingSensor).
						 WithTrackingSensor(OldConfig::rightDriveTrackingSensor).
						 WithTrackingSensor(OldConfig::strafeDriveTrackingSensor).
						 WithDistancePID(distancePID).
						 WithAnglePID(anglePID).
						 WithTurnPID(turnPID).
						 WithPosition(position).
						 WithWheelSize(OldConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(OldConfig::intake1Motor).Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithLeftMotor(OldConfig::leftLift1Motor).
					   WithRightMotor(OldConfig::rightLift1Motor).
					   WithPID(liftPID).
					   WithTopAngle(OldConfig::LIFT_TOP_POSITION).
					   WithBottomAngle(OldConfig::LIFT_BOTTOM_POSITION).
					   WithStartAngle(OldConfig::LIFT_START_POSITION).
					   WithCountsPerDegree(OldConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

// Private method definitions -------------------------------------------------
void Robot::UpdateCarrier(pros::Controller& master)
{
	/*
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
	{
		if(carrier.IsDown())
			carrier.SetUp();
		else
			carrier.SetDown();
	}
	carrier.HoldPosition();
	*/
	if (master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
		carrier.SetPower(20);
	else if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
		carrier.SetPower(-20);
	else
		carrier.SetPower(0.0);
}

void Robot::UpdateClaw(pros::Controller& master)
{
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
	{
		if(claw.IsClosed())
			claw.SetOpen();	
		else
			claw.SetClosed();
	}
	claw.HoldPosition();
}

void Robot::UpdateDrive(pros::Controller& master)
{
	// Arcade drive mode
	float leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) 
						+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
	float rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
						- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

	/*
	// Tank drive mode
	float leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	float rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
	*/

	// Update
	drive.SetDrive(leftDrivePower, rightDrivePower);
	drive.UpdatePosition();
}

void Robot::UpdateIntake(pros::Controller& master)
{
	if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
		intake.Suck();
	else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
		intake.Blow();
	else
		intake.Stop();
}

void Robot::UpdateLift(pros::Controller& master)
{
	if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
		lift.Raise();
	else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
		lift.Lower();
	else
		lift.HoldPosition();
}

// Public method definitions --------------------------------------------------
void Robot::Initialize()
{
	carrier.Initialize();
	claw.Initialize();
	drive.Initialize();
	intake.Initialize();
	lift.Initialize();
}

void Robot::RobotControl(pros::Controller& master)
{
	UpdateCarrier(master);
	UpdateClaw(master);
	UpdateDrive(master);
	UpdateIntake(master);
	UpdateLift(master);

	// Delay for the next loop
	pros::delay(5);
}