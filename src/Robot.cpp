// Included libraries
#include "Robot.hpp"

// Constructor definitions ----------------------------------------------------
Robot::Robot()
{
	//CreateOldOrangeRobot();
	CreateOldBlueRobot();
	//CreateBlueRobot();
}

// Private method definitions -------------------------------------------------
void Robot::CreateBlueRobot()
{
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(1.0)->WithKi(0.1)->WithKd(0.1)->WithIntegralLimit(70.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;
	
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(BlueConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
										WithRightDistance(BlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
										WithStrafeDistance(BlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
										Build();
	delete positionBuilder;
	positionBuilder = nullptr;

	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(BlueConfig::CARRIER_1_PORT))->
							 Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;
	
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	claw = clawBuilder->WithPiston(new pros::ADIDigitalOut(BlueConfig::CLAW_1_PORT))->
					   Build();
	delete clawBuilder;
	clawBuilder = nullptr;

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(pros::Motor(BlueConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(BlueConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(BlueConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(BlueConfig::LEFT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(BlueConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(BlueConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(BlueConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(BlueConfig::RIGHT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                        		true, E_MOTOR_ENCODER_COUNTS)).
						 WithTrackingSensor(pros::Rotation(BlueConfig::LEFT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(BlueConfig::RIGHT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(BlueConfig::STRAFE_DRIVE_TRACKING_PORT)).
						 WithDistancePID(*distancePID).
						 WithAnglePID(*anglePID).
						 WithTurnPID(*turnPID).
						 WithPosition(*position).
						 WithWheelSize(BlueConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(pros::Motor(BlueConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
								E_MOTOR_ENCODER_COUNTS)).
						   Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(pros::Motor(BlueConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(BlueConfig::LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(BlueConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(BlueConfig::RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithPID(*liftPID).
					   WithStartAngle(BlueConfig::LIFT_START_POSITION).
					   //WithMinAngle(BlueConfig::LIFT_BOTTOM_POSITION).
					   //WithMaxAngle(BlueConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(BlueConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOrangeRobot()
{
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(5.0)->WithKi(0.3)->WithKd(0.25)->WithIntegralLimit(70.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;
	
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
										WithRightDistance(OrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
										WithStrafeDistance(OrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
										Build();
	delete positionBuilder;
	positionBuilder = nullptr;

	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(OrangeConfig::CARRIER_1_PORT))->
							 WithPiston(new pros::ADIDigitalOut(OrangeConfig::CARRIER_2_PORT))->
							 Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;
	
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	claw = clawBuilder->WithPiston(new pros::ADIDigitalOut(OrangeConfig::CLAW_1_PORT))->
					   WithPiston(new pros::ADIDigitalOut(OrangeConfig::CLAW_2_PORT))->
					   Build();
	delete clawBuilder;
	clawBuilder = nullptr;

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(pros::Motor(OrangeConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OrangeConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OrangeConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OrangeConfig::LEFT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OrangeConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OrangeConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OrangeConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OrangeConfig::RIGHT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
                        		true, E_MOTOR_ENCODER_COUNTS)).
						 WithTrackingSensor(pros::Rotation(OrangeConfig::LEFT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OrangeConfig::RIGHT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OrangeConfig::STRAFE_DRIVE_TRACKING_PORT)).
						 WithDistancePID(*distancePID).
						 WithAnglePID(*anglePID).
						 WithTurnPID(*turnPID).
						 WithPosition(*position).
						 WithWheelSize(OrangeConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(pros::Motor(OrangeConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
								E_MOTOR_ENCODER_COUNTS)).
						   Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(pros::Motor(OrangeConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(OrangeConfig::LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(OrangeConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(OrangeConfig::RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, 
								E_MOTOR_ENCODER_COUNTS)).
					   WithPID(*liftPID).
					   WithStartAngle(OrangeConfig::LIFT_START_POSITION).
					   WithMinAngle(OrangeConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OrangeConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OrangeConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOldBlueRobot()
{
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* carrierPID = pidBuilder->WithKp(5.3)->WithKi(0.5)->WithKd(0.25)->WithIntegralLimit(65.0)->Build();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.15)->WithIntegralLimit(70.0)->WithStartTarget(OldBlueConfig::LIFT_START_POSITION)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;

	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OldBlueConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
										WithRightDistance(OldBlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
										WithStrafeDistance(OldBlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
										Build();
	delete positionBuilder;
	positionBuilder = nullptr;

	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	carrier = carrierBuilder->WithMotor(new pros::Motor(OldBlueConfig::CARRIER_1_PORT, pros::E_MOTOR_GEARSET_36, 
									true, E_MOTOR_ENCODER_COUNTS))->
							 WithMotor(new pros::Motor(OldBlueConfig::CARRIER_2_PORT, pros::E_MOTOR_GEARSET_36, 
									false, E_MOTOR_ENCODER_COUNTS))->
							 WithPID(carrierPID)->
							 WithDownPosition(OldBlueConfig::CARRIER_DOWN_POSITION)->
							 WithUpPosition(OldBlueConfig::CARRIER_UP_POSITION)->
							 Build();
	
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	claw = clawBuilder->WithMotor(new pros::Motor(OldBlueConfig::CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, false,
								E_MOTOR_ENCODER_COUNTS))->
					   WithPID(clawPID)->
					   WithOpenPosition(OldBlueConfig::CLAW_OPEN_POSITION)->
					   WithClosedPosition(OldBlueConfig::CLAW_CLOSED_POSITION)->
					   Build();
	delete clawBuilder;
	clawBuilder = nullptr;

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(pros::Motor(OldBlueConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OldBlueConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OldBlueConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldBlueConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldBlueConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldBlueConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithTrackingSensor(pros::Rotation(OldBlueConfig::LEFT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OldBlueConfig::RIGHT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OldBlueConfig::STRAFE_DRIVE_TRACKING_PORT)).
						 WithDistancePID(*distancePID).
						 WithAnglePID(*anglePID).
						 WithTurnPID(*turnPID).
						 WithPosition(*position).
						 WithWheelSize(OldBlueConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(pros::Motor(OldBlueConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
									E_MOTOR_ENCODER_COUNTS))
						  .Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(pros::Motor(OldBlueConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
								false, E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(OldBlueConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
								true, E_MOTOR_ENCODER_COUNTS)).
					   WithPID(*liftPID).
					   WithStartAngle(OldBlueConfig::LIFT_START_POSITION).
					   WithMinAngle(OldBlueConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OldBlueConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OldBlueConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::CreateOldOrangeRobot()
{
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(1.0)->WithKi(0.06)->WithKd(0.05)->WithIntegralLimit(70.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;

	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OldOrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
										WithRightDistance(OldOrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
										WithStrafeDistance(OldOrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
										Build();
	delete positionBuilder;
	positionBuilder = nullptr;

	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(OldOrangeConfig::CARRIER_1_PORT))->
							 WithPiston(new pros::ADIDigitalOut(OldOrangeConfig::CARRIER_2_PORT))->
							 Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;

	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	claw = clawBuilder->WithMotor(new pros::Motor(OldOrangeConfig::CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, 
								false, E_MOTOR_ENCODER_COUNTS))->
					   WithPID(clawPID)->
					   WithOpenPosition(OldOrangeConfig::CLAW_OPEN_POSITION)->
					   WithClosedPosition(OldOrangeConfig::CLAW_CLOSED_POSITION)->
					   Build();
	delete clawBuilder;
	clawBuilder = nullptr;

	Drive::DriveBuilder driveBuilder;
	drive = driveBuilder.WithLeftMotor(pros::Motor(OldOrangeConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OldOrangeConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithLeftMotor(pros::Motor(OldOrangeConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldOrangeConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldOrangeConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
                                true, E_MOTOR_ENCODER_COUNTS)).
						 WithRightMotor(pros::Motor(OldOrangeConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
                                false, E_MOTOR_ENCODER_COUNTS)).
						 WithTrackingSensor(pros::Rotation(OldOrangeConfig::LEFT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OldOrangeConfig::RIGHT_DRIVE_TRACKING_PORT)).
						 WithTrackingSensor(pros::Rotation(OldOrangeConfig::STRAFE_DRIVE_TRACKING_PORT)).
						 WithDistancePID(*distancePID).
						 WithAnglePID(*anglePID).
						 WithTurnPID(*turnPID).
						 WithPosition(*position).
						 WithWheelSize(OldOrangeConfig::DRIVE_TRACKING_WHEEL_SIZE).
						 Build();
	
	Intake::IntakeBuilder intakeBuilder;
	intake = intakeBuilder.WithMotor(pros::Motor(OldOrangeConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
									E_MOTOR_ENCODER_COUNTS)).
						   Build();

	Lift::LiftBuilder liftBuilder;
	lift = liftBuilder.WithMotor(pros::Motor(OldOrangeConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
								false, E_MOTOR_ENCODER_COUNTS)).
					   WithMotor(pros::Motor(OldOrangeConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
								true, E_MOTOR_ENCODER_COUNTS)).
					   WithPID(*liftPID).
					   WithStartAngle(OldOrangeConfig::LIFT_START_POSITION).
					   WithMinAngle(OldOrangeConfig::LIFT_BOTTOM_POSITION).
					   WithMaxAngle(OldOrangeConfig::LIFT_TOP_POSITION).
					   WithCountsPerDegree(OldOrangeConfig::LIFT_COUNTS_PER_DEGREE).
					   Build();
}

void Robot::UpdateCarrier(pros::Controller& master)
{
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
		carrier->TogglePosition();
	carrier->HoldPosition();

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
		claw->TogglePosition();
	claw->HoldPosition();

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
	//double leftDrivePower = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	//double rightDrivePower = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

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
	carrier->Initialize();
	claw->Initialize();
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