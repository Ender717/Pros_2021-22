// Included libraries
#include "Robot.hpp"

// Constructor definitions ----------------------------------------------------
Robot::Robot()
{
	CreateOldOrangeRobot();
}

// Private method definitions -------------------------------------------------
void Robot::CreateBlueRobot()
{
	PID::PIDBuilder pidBuilder;
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	Position::PositionBuilder positionBuilder;
	Position position = positionBuilder.WithLeftDistance(BlueConfig::DRIVE_LEFT_TRACKING_DISTANCE).
										WithRightDistance(BlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE).
										WithStrafeDistance(BlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE).
										Build();

	Carrier::CarrierBuilder carrierBuilder;
	carrier = carrierBuilder.WithPiston(BlueConfig::carrier1Piston).
							 WithPiston(BlueConfig::carrier2Piston).
							 Build();
	
	Claw::ClawBuilder clawBuilder;
	claw = clawBuilder.WithMotor(BlueConfig::claw1Motor).
					   WithPID(clawPID).
					   WithOpenPosition(BlueConfig::CLAW_OPEN_POSITION).
					   WithClosedPosition(BlueConfig::CLAW_CLOSED_POSITION).
					   Build();

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(BlueConfig::leftDrive1Motor).
						 WithLeftMotor(BlueConfig::leftDrive2Motor).
						 WithLeftMotor(BlueConfig::leftDrive3Motor).
						 WithLeftMotor(BlueConfig::leftDrive4Motor).
						 WithRightMotor(BlueConfig::rightDrive1Motor).
						 WithRightMotor(BlueConfig::rightDrive2Motor).
						 WithRightMotor(BlueConfig::rightDrive3Motor).
						 WithRightMotor(BlueConfig::rightDrive4Motor).
						 WithTrackingSensor(BlueConfig::leftDriveTrackingSensor).
						 WithTrackingSensor(BlueConfig::rightDriveTrackingSensor).
						 WithTrackingSensor(BlueConfig::strafeDriveTrackingSensor).
						 WithDistancePID(distancePID).
						 WithAnglePID(anglePID).
						 WithTurnPID(turnPID).
						 WithPosition(position).
						 WithWheelSize(BlueConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(BlueConfig::intake1Motor).Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(BlueConfig::leftLift1Motor).
					   WithMotor(BlueConfig::leftLift2Motor).
					   WithMotor(BlueConfig::rightLift1Motor).
					   WithMotor(BlueConfig::rightLift2Motor).
					   WithPID(liftPID).
					   WithStartAngle(BlueConfig::LIFT_START_POSITION).
					   WithMinAngle(BlueConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(BlueConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(BlueConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOrangeRobot()
{
	PID::PIDBuilder pidBuilder;
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	Position::PositionBuilder positionBuilder;
	Position position = positionBuilder.WithLeftDistance(OrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE).
										WithRightDistance(OrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE).
										WithStrafeDistance(OrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE).
										Build();

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
						 WithLeftMotor(OrangeConfig::leftDrive4Motor).
						 WithRightMotor(OrangeConfig::rightDrive1Motor).
						 WithRightMotor(OrangeConfig::rightDrive2Motor).
						 WithRightMotor(OrangeConfig::rightDrive3Motor).
						 WithRightMotor(OrangeConfig::rightDrive4Motor).
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
	lift = liftBuilder.WithMotor(OrangeConfig::leftLift1Motor).
					   WithMotor(OrangeConfig::leftLift2Motor).
					   WithMotor(OrangeConfig::rightLift1Motor).
					   WithMotor(OrangeConfig::rightLift2Motor).
					   WithPID(liftPID).
					   WithStartAngle(OrangeConfig::LIFT_START_POSITION).
					   WithMinAngle(OrangeConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OrangeConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OrangeConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOldBlueRobot()
{
	PID::PIDBuilder pidBuilder;
	PID carrierPID = pidBuilder.WithKp(5.3).WithKi(0.5).WithKd(0.25).WithIntegralLimit(65.0).Build();
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(5.0).WithKi(0.3).WithKd(0.25).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	Position::PositionBuilder positionBuilder;
	Position position = positionBuilder.WithLeftDistance(OldBlueConfig::DRIVE_LEFT_TRACKING_DISTANCE).
										WithRightDistance(OldBlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE).
										WithStrafeDistance(OldBlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE).
										Build();

	Carrier::CarrierBuilder carrierBuilder;
	carrier = carrierBuilder.WithMotor(OldBlueConfig::carrier1Motor).
							 WithMotor(OldBlueConfig::carrier2Motor).
							 WithPID(carrierPID).
							 WithDownPosition(OldBlueConfig::CARRIER_DOWN_POSITION).
							 WithUpPosition(OldBlueConfig::CARRIER_UP_POSITION).
							 Build();
	
	Claw::ClawBuilder clawBuilder;
	claw = clawBuilder.WithMotor(OldBlueConfig::claw1Motor).
					   WithPID(clawPID).
					   WithOpenPosition(OldBlueConfig::CLAW_OPEN_POSITION).
					   WithClosedPosition(OldBlueConfig::CLAW_CLOSED_POSITION).
					   Build();

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(OldBlueConfig::leftDrive1Motor).
						 WithLeftMotor(OldBlueConfig::leftDrive2Motor).
						 WithLeftMotor(OldBlueConfig::leftDrive3Motor).
						 WithRightMotor(OldBlueConfig::rightDrive1Motor).
						 WithRightMotor(OldBlueConfig::rightDrive2Motor).
						 WithRightMotor(OldBlueConfig::rightDrive3Motor).
						 WithTrackingSensor(OldBlueConfig::leftDriveTrackingSensor).
						 WithTrackingSensor(OldBlueConfig::rightDriveTrackingSensor).
						 WithTrackingSensor(OldBlueConfig::strafeDriveTrackingSensor).
						 WithDistancePID(distancePID).
						 WithAnglePID(anglePID).
						 WithTurnPID(turnPID).
						 WithPosition(position).
						 WithWheelSize(OldBlueConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(OldBlueConfig::intake1Motor).Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(OldBlueConfig::leftLift1Motor).
					   WithMotor(OldBlueConfig::rightLift1Motor).
					   WithPID(liftPID).
					   WithStartAngle(OldBlueConfig::LIFT_START_POSITION).
					   WithMinAngle(OldBlueConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OldBlueConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OldBlueConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOldOrangeRobot()
{
	PID::PIDBuilder pidBuilder;
	PID clawPID = pidBuilder.WithKp(2.3).WithKi(0.05).WithKd(0.05).WithIntegralLimit(65.0).Build();
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	PID liftPID = pidBuilder.WithKp(1.0).WithKi(0.06).WithKd(0.05).WithIntegralLimit(70.0).WithStartTarget(140.0).Build();
	
	Position::PositionBuilder positionBuilder;
	Position position = positionBuilder.WithLeftDistance(OldOrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE).
										WithRightDistance(OldOrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE).
										WithStrafeDistance(OldOrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE).
										Build();

	Carrier::CarrierBuilder carrierBuilder;
	carrier = carrierBuilder.WithPiston(OldOrangeConfig::carrier1Piston).
							 WithPiston(OldOrangeConfig::carrier2Piston).
							 Build();
	
	Claw::ClawBuilder clawBuilder;
	claw = clawBuilder.WithMotor(OldOrangeConfig::claw1Motor).
					   WithPID(clawPID).
					   WithOpenPosition(OldOrangeConfig::CLAW_OPEN_POSITION).
					   WithClosedPosition(OldOrangeConfig::CLAW_CLOSED_POSITION).
					   Build();

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(OldOrangeConfig::leftDrive1Motor).
						 WithLeftMotor(OldOrangeConfig::leftDrive2Motor).
						 WithLeftMotor(OldOrangeConfig::leftDrive3Motor).
						 WithRightMotor(OldOrangeConfig::rightDrive1Motor).
						 WithRightMotor(OldOrangeConfig::rightDrive2Motor).
						 WithRightMotor(OldOrangeConfig::rightDrive3Motor).
						 WithTrackingSensor(OldOrangeConfig::leftDriveTrackingSensor).
						 WithTrackingSensor(OldOrangeConfig::rightDriveTrackingSensor).
						 WithTrackingSensor(OldOrangeConfig::strafeDriveTrackingSensor).
						 WithDistancePID(distancePID).
						 WithAnglePID(anglePID).
						 WithTurnPID(turnPID).
						 WithPosition(position).
						 WithWheelSize(OldOrangeConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(OldOrangeConfig::intake1Motor).Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(OldOrangeConfig::leftLift1Motor).
					   WithMotor(OldOrangeConfig::rightLift1Motor).
					   WithPID(liftPID).
					   WithStartAngle(OldOrangeConfig::LIFT_START_POSITION).
					   WithMinAngle(OldOrangeConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OldOrangeConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OldOrangeConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::UpdateCarrier(pros::Controller& master)
{
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
	{
		if(carrier.IsDown())
			carrier.SetUp();
		else
			carrier.SetDown();
	}
	carrier.HoldPosition();

	/*
	if (master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
		carrier.SetPower(-127);
	else if (master.get_digital(E_CONTROLLER_DIGITAL_X))
		carrier.SetPower(127);
	else
		carrier.HoldPosition();
	}
	*/
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

	/*
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
	{
		if(claw.IsClosed())
			claw.SetOpen();	
		else
			claw.SetClosed();
	}
	claw.HoldPosition();

	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1))
		claw.SetOpen();	
	else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2))
		claw.SetClosed();
	claw.HoldPosition();
	*/
}

void Robot::UpdateDrive(pros::Controller& master)
{
	// Arcade drive mode
	double leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) 
						+ master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
	double rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)
						- master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

	// Tank drive mode
	/*
	double leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	double rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
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