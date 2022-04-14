// Included libraries
#include "RobotManager.hpp"

// Private method definitions --------------------------------------------------
void RobotManager::CreateBlueRobot()
{
    // Reset the robot
    if (robot != nullptr)
    {
        delete robot;
        robot = nullptr;
    }

    // Create the PID controllers
    PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(1.5)->WithKi(0.1)->WithKd(0.1)->WithIntegralLimit(90.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;
	
    // Create the position tracking
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(BlueConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
		WithRightDistance(BlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
		WithStrafeDistance(BlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
		Build();
	delete positionBuilder;
	positionBuilder = nullptr;

    // Create the carrier
	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	Carrier* carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(BlueConfig::CARRIER_1_PORT))->
		Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;

    // Create the claw
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	Claw* claw = clawBuilder->WithPiston(new pros::ADIDigitalOut(BlueConfig::CLAW_1_PORT))->
		Build();
	delete clawBuilder;
	clawBuilder = nullptr;

    // Create the drive
	Drive::DriveBuilder* driveBuilder = new Drive::DriveBuilder();
	Drive* drive = driveBuilder->WithLeftMotor(new pros::Motor(BlueConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
		WithLeftMotor(new pros::Motor(BlueConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(BlueConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(BlueConfig::LEFT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(BlueConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(BlueConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(BlueConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(BlueConfig::RIGHT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftTrackingSensor(new pros::Rotation(BlueConfig::LEFT_DRIVE_TRACKING_PORT))->
        WithRightTrackingSensor(new pros::Rotation(BlueConfig::RIGHT_DRIVE_TRACKING_PORT))->
        WithStrafeTrackingSensor(new pros::Rotation(BlueConfig::STRAFE_DRIVE_TRACKING_PORT))->
        WithDistancePID(distancePID)->
        WithAnglePID(anglePID)->
        WithTurnPID(turnPID)->
        WithPosition(position)->
        WithWheelSize(BlueConfig::DRIVE_TRACKING_WHEEL_SIZE)->
        Build();
	delete driveBuilder;
	driveBuilder = nullptr;

    // Create the intake
	Intake::IntakeBuilder* intakeBuilder = new Intake::IntakeBuilder();
	Intake* intake = intakeBuilder->WithMotor(new pros::Motor(BlueConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
            E_MOTOR_ENCODER_COUNTS))->
        Build();
	delete intakeBuilder;
	intakeBuilder = nullptr;

    // Create the lift
	Lift::LiftBuilder* liftBuilder = new Lift::LiftBuilder();
	Lift* lift = liftBuilder->WithMotor(new pros::Motor(BlueConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(BlueConfig::LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(BlueConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(BlueConfig::RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, 
            E_MOTOR_ENCODER_COUNTS))->
        WithPID(liftPID)->
        WithStartAngle(BlueConfig::LIFT_START_POSITION)->
        //WithMinAngle(BlueConfig::LIFT_BOTTOM_POSITION)->
        //WithMaxAngle(BlueConfig::LIFT_TOP_POSITION)->
        WithCountsPerDegree(BlueConfig::LIFT_COUNTS_PER_DEGREE)->
        Build();
	delete liftBuilder;
	liftBuilder = nullptr;

    // Create the robot
    Robot::RobotBuilder* robotBuilder = new Robot::RobotBuilder();
    robot = robotBuilder->WithCarrier(carrier)->
        WithClaw(claw)->
        WithDrive(drive)->
        WithIntake(intake)->
        WithLift(lift)->
        Build();
    delete robotBuilder;
    robotBuilder = nullptr;

    // Reset the pointers
    carrier = nullptr;
    claw = nullptr;
    drive = nullptr;
    intake = nullptr;
    lift = nullptr;
}

void RobotManager::CreateOrangeRobot()
{
    // Reset the robot
    if (robot != nullptr)
    {
        delete robot;
        robot = nullptr;
    }

    // Create the PID controllers
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(5.0)->WithKi(0.3)->WithKd(0.25)->WithIntegralLimit(70.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;
	
    // Create the postion tracking
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
        WithRightDistance(OrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
        WithStrafeDistance(OrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
        Build();
	delete positionBuilder;
	positionBuilder = nullptr;

    // Create the carrier
	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	Carrier* carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(OrangeConfig::CARRIER_1_PORT))->
		WithPiston(new pros::ADIDigitalOut(OrangeConfig::CARRIER_2_PORT))->
        Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;
	
    // Create the claw
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	Claw* claw = clawBuilder->WithPiston(new pros::ADIDigitalOut(OrangeConfig::CLAW_1_PORT))->
        WithPiston(new pros::ADIDigitalOut(OrangeConfig::CLAW_2_PORT))->
        Build();
	delete clawBuilder;
	clawBuilder = nullptr;

	Drive::DriveBuilder* driveBuilder = new Drive::DriveBuilder();
	Drive* drive = driveBuilder->WithLeftMotor(new pros::Motor(OrangeConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OrangeConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OrangeConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OrangeConfig::LEFT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OrangeConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OrangeConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OrangeConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OrangeConfig::RIGHT_DRIVE_4_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftTrackingSensor(new pros::Rotation(OrangeConfig::LEFT_DRIVE_TRACKING_PORT))->
        WithRightTrackingSensor(new pros::Rotation(OrangeConfig::RIGHT_DRIVE_TRACKING_PORT))->
        WithStrafeTrackingSensor(new pros::Rotation(OrangeConfig::STRAFE_DRIVE_TRACKING_PORT))->
        WithDistancePID(distancePID)->
        WithAnglePID(anglePID)->
        WithTurnPID(turnPID)->
        WithPosition(position)->
        WithWheelSize(OrangeConfig::DRIVE_TRACKING_WHEEL_SIZE)->
        Build();
	delete driveBuilder;
	driveBuilder = nullptr;
	
    // Create the intake
	Intake::IntakeBuilder* intakeBuilder = new Intake::IntakeBuilder();
	Intake* intake = intakeBuilder->WithMotor(new pros::Motor(OrangeConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
            E_MOTOR_ENCODER_COUNTS))->
        Build();
	delete intakeBuilder;
	intakeBuilder = nullptr;

    // Create the lift
	Lift::LiftBuilder* liftBuilder = new Lift::LiftBuilder();
	Lift* lift = liftBuilder->WithMotor(new pros::Motor(OrangeConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, true, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OrangeConfig::LEFT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, false, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OrangeConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, false, 
            E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OrangeConfig::RIGHT_LIFT_2_PORT, pros::E_MOTOR_GEARSET_36, true, 
            E_MOTOR_ENCODER_COUNTS))->
        WithPID(liftPID)->
        WithStartAngle(OrangeConfig::LIFT_START_POSITION)->
        WithMinAngle(OrangeConfig::LIFT_BOTTOM_POSITION)->
        WithMaxAngle(OrangeConfig::LIFT_TOP_POSITION)->
        WithCountsPerDegree(OrangeConfig::LIFT_COUNTS_PER_DEGREE)->
        Build();
	delete liftBuilder;
	liftBuilder = nullptr;

    // Create the robot
    Robot::RobotBuilder* robotBuilder = new Robot::RobotBuilder();
    robot = robotBuilder->WithCarrier(carrier)->
        WithClaw(claw)->
        WithDrive(drive)->
        WithIntake(intake)->
        WithLift(lift)->
        Build();
    delete robotBuilder;
    robotBuilder = nullptr;

    // Reset the pointers
    carrier = nullptr;
    claw = nullptr;
    drive = nullptr;
    intake = nullptr;
    lift = nullptr;
}

void RobotManager::CreateOldBlueRobot()
{
    // Reset the robot
    if (robot != nullptr)
    {
        delete robot;
        robot = nullptr;
    }

    // Create the PID controllers
	PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* carrierPID = pidBuilder->WithKp(5.3)->WithKi(0.5)->WithKd(0.25)->WithIntegralLimit(65.0)->Build();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.15)->WithIntegralLimit(70.0)->WithStartTarget(OldBlueConfig::LIFT_START_POSITION)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;

    // Create the position tracking
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OldBlueConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
        WithRightDistance(OldBlueConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
        WithStrafeDistance(OldBlueConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
        Build();
	delete positionBuilder;
	positionBuilder = nullptr;

    // Create the carrier
	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	Carrier* carrier = carrierBuilder->WithMotor(new pros::Motor(OldBlueConfig::CARRIER_1_PORT, pros::E_MOTOR_GEARSET_36, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OldBlueConfig::CARRIER_2_PORT, pros::E_MOTOR_GEARSET_36, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithPID(carrierPID)->
        WithDownPosition(OldBlueConfig::CARRIER_DOWN_POSITION)->
        WithUpPosition(OldBlueConfig::CARRIER_UP_POSITION)->
        Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;
	
    // Create the claw
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	Claw* claw = clawBuilder->WithMotor(new pros::Motor(OldBlueConfig::CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, false,
            E_MOTOR_ENCODER_COUNTS))->
        WithPID(clawPID)->
        WithOpenPosition(OldBlueConfig::CLAW_OPEN_POSITION)->
        WithClosedPosition(OldBlueConfig::CLAW_CLOSED_POSITION)->
        Build();
	delete clawBuilder;
	clawBuilder = nullptr;

    // Create the drive
	Drive::DriveBuilder* driveBuilder = new Drive::DriveBuilder();
	Drive* drive = driveBuilder->WithLeftMotor(new pros::Motor(OldBlueConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OldBlueConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OldBlueConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldBlueConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldBlueConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldBlueConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftTrackingSensor(new pros::Rotation(OldBlueConfig::LEFT_DRIVE_TRACKING_PORT))->
        WithRightTrackingSensor(new pros::Rotation(OldBlueConfig::RIGHT_DRIVE_TRACKING_PORT))->
        WithStrafeTrackingSensor(new pros::Rotation(OldBlueConfig::STRAFE_DRIVE_TRACKING_PORT))->
        WithDistancePID(distancePID)->
        WithAnglePID(anglePID)->
        WithTurnPID(turnPID)->
        WithPosition(position)->
        WithWheelSize(OldBlueConfig::DRIVE_TRACKING_WHEEL_SIZE)->
        Build();
	delete driveBuilder;
	driveBuilder = nullptr;
	
    // Create the intake
	Intake::IntakeBuilder* intakeBuilder = new Intake::IntakeBuilder();
	Intake* intake = intakeBuilder->WithMotor(new pros::Motor(OldBlueConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
            E_MOTOR_ENCODER_COUNTS))->
        Build();
	delete intakeBuilder;
	intakeBuilder = nullptr;

    // Create the lift
	Lift::LiftBuilder* liftBuilder = new Lift::LiftBuilder();
	Lift* lift = liftBuilder->WithMotor(new pros::Motor(OldBlueConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OldBlueConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithPID(liftPID)->
        WithStartAngle(OldBlueConfig::LIFT_START_POSITION)->
        WithMinAngle(OldBlueConfig::LIFT_BOTTOM_POSITION)->
        WithMaxAngle(OldBlueConfig::LIFT_TOP_POSITION)->
        WithCountsPerDegree(OldBlueConfig::LIFT_COUNTS_PER_DEGREE)->
        Build();
	delete liftBuilder;
	liftBuilder = nullptr;

    // Create the robot
    Robot::RobotBuilder* robotBuilder = new Robot::RobotBuilder();
    robot = robotBuilder->WithCarrier(carrier)->
        WithClaw(claw)->
        WithDrive(drive)->
        WithIntake(intake)->
        WithLift(lift)->
        Build();
    delete robotBuilder;
    robotBuilder = nullptr;

    // Reset the pointers
    carrier = nullptr;
    claw = nullptr;
    drive = nullptr;
    intake = nullptr;
    lift = nullptr;
}

void RobotManager::CreateOldOrangeRobot()
{
    // Reset the robot
    if (robot != nullptr)
    {
        delete robot;
        robot = nullptr;
    }

    // Create the PID controllers
    PID::PIDBuilder* pidBuilder = new PID::PIDBuilder();
	PID* clawPID = pidBuilder->WithKp(2.3)->WithKi(0.05)->WithKd(0.05)->WithIntegralLimit(65.0)->Build();
	PID* distancePID = pidBuilder->WithKp(11.3)->WithKi(0.5)->WithKd(0.5)->WithIntegralLimit(40.0)->Build();
    PID* anglePID = pidBuilder->WithKp(3.0)->WithKi(0.2)->WithKd(0.05)->WithIntegralLimit(40.0)->Build();
    PID* turnPID = pidBuilder->WithKp(5.3)->WithKi(0.15)->WithKd(0.10)->WithIntegralLimit(40.0)->Build();
	PID* liftPID = pidBuilder->WithKp(1.0)->WithKi(0.06)->WithKd(0.05)->WithIntegralLimit(70.0)->WithStartTarget(140.0)->Build();
	delete pidBuilder;
	pidBuilder = nullptr;

    // Create the position tracking
	Position::PositionBuilder* positionBuilder = new Position::PositionBuilder();
	Position* position = positionBuilder->WithLeftDistance(OldOrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE)->
        WithRightDistance(OldOrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE)->
        WithStrafeDistance(OldOrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE)->
        Build();
	delete positionBuilder;
	positionBuilder = nullptr;

    // Create the carrier
	Carrier::CarrierBuilder* carrierBuilder = new Carrier::CarrierBuilder();
	Carrier* carrier = carrierBuilder->WithPiston(new pros::ADIDigitalOut(OldOrangeConfig::CARRIER_1_PORT))->
        WithPiston(new pros::ADIDigitalOut(OldOrangeConfig::CARRIER_2_PORT))->
        Build();
	delete carrierBuilder;
	carrierBuilder = nullptr;

    // Create the claw
	Claw::ClawBuilder* clawBuilder = new Claw::ClawBuilder();
	Claw* claw = clawBuilder->WithMotor(new pros::Motor(OldOrangeConfig::CLAW_1_PORT, pros::E_MOTOR_GEARSET_36, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithPID(clawPID)->
        WithOpenPosition(OldOrangeConfig::CLAW_OPEN_POSITION)->
        WithClosedPosition(OldOrangeConfig::CLAW_CLOSED_POSITION)->
        Build();
	delete clawBuilder;
	clawBuilder = nullptr;

    // Create the drive
	Drive::DriveBuilder* driveBuilder = new Drive::DriveBuilder();
	Drive* drive = driveBuilder->WithLeftMotor(new pros::Motor(OldOrangeConfig::LEFT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OldOrangeConfig::LEFT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftMotor(new pros::Motor(OldOrangeConfig::LEFT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldOrangeConfig::RIGHT_DRIVE_1_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldOrangeConfig::RIGHT_DRIVE_2_PORT, pros::E_MOTOR_GEARSET_06, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithRightMotor(new pros::Motor(OldOrangeConfig::RIGHT_DRIVE_3_PORT, pros::E_MOTOR_GEARSET_06, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithLeftTrackingSensor(new pros::Rotation(OldOrangeConfig::LEFT_DRIVE_TRACKING_PORT))->
        WithRightTrackingSensor(new pros::Rotation(OldOrangeConfig::RIGHT_DRIVE_TRACKING_PORT))->
        WithStrafeTrackingSensor(new pros::Rotation(OldOrangeConfig::STRAFE_DRIVE_TRACKING_PORT))->
        WithDistancePID(distancePID)->
        WithAnglePID(anglePID)->
        WithTurnPID(turnPID)->
        WithPosition(position)->
        WithWheelSize(OldOrangeConfig::DRIVE_TRACKING_WHEEL_SIZE)->
        Build();
	delete driveBuilder;
	driveBuilder = nullptr;
	
    // Create the intake
	Intake::IntakeBuilder* intakeBuilder = new Intake::IntakeBuilder();
	Intake* intake = intakeBuilder->WithMotor(new pros::Motor(OldOrangeConfig::INTAKE_1_PORT, E_MOTOR_GEARSET_06, true, 
            E_MOTOR_ENCODER_COUNTS))->
        Build();
	delete intakeBuilder;
	intakeBuilder = nullptr;

    // Create the lift
	Lift::LiftBuilder* liftBuilder = new Lift::LiftBuilder();
	Lift* lift = liftBuilder->WithMotor(new pros::Motor(OldOrangeConfig::LEFT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
            false, E_MOTOR_ENCODER_COUNTS))->
        WithMotor(new pros::Motor(OldOrangeConfig::RIGHT_LIFT_1_PORT, pros::E_MOTOR_GEARSET_36, 
            true, E_MOTOR_ENCODER_COUNTS))->
        WithPID(liftPID)->
        WithStartAngle(OldOrangeConfig::LIFT_START_POSITION)->
        WithMinAngle(OldOrangeConfig::LIFT_BOTTOM_POSITION)->
        WithMaxAngle(OldOrangeConfig::LIFT_TOP_POSITION)->
        WithCountsPerDegree(OldOrangeConfig::LIFT_COUNTS_PER_DEGREE)->
        Build();
	delete liftBuilder;
	liftBuilder = nullptr;

    // Create the robot
    Robot::RobotBuilder* robotBuilder = new Robot::RobotBuilder();
    robot = robotBuilder->WithCarrier(carrier)->
        WithClaw(claw)->
        WithDrive(drive)->
        WithIntake(intake)->
        WithLift(lift)->
        Build();
    delete robotBuilder;
    robotBuilder = nullptr;

    // Reset the pointers
    carrier = nullptr;
    claw = nullptr;
    drive = nullptr;
    intake = nullptr;
    lift = nullptr;
}

// Public method definitions --------------------------------------------------
void RobotManager::Intialize()
{
    robot = nullptr;
}

void RobotManager::CreateRobot(RobotConfigs config)
{
    switch (config)
    {
        case RobotConfigs::BLUE:
            CreateBlueRobot();
            break;
        case RobotConfigs::ORANGE:
            CreateOrangeRobot();
            break;
        case RobotConfigs::OLD_BLUE:
            CreateOldBlueRobot();
            break;
        case RobotConfigs::OLD_ORANGE:
            CreateOldOrangeRobot();
            break;
    }
}

Robot* RobotManager::GetRobot()
{
    return robot;
}