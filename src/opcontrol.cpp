#include "opcontrol.h"

void driveTask()
{
	Robot robot;
	robot.drive.DriveStraight(36.0);
}

void liftTask()
{
	Robot robot;
	robot.lift.Raise();
}

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
	// Create the robot and controller
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	//Robot robot;
	
	pros::screen::erase();

	//Task driveThread (driveTask);
	//Task liftThread (liftTask);

	PID::PIDBuilder pidBuilder;
	PID distancePID = pidBuilder.WithKp(11.3).WithKi(0.5).WithKd(0.5).WithIntegralLimit(40.0).Build();
    PID anglePID = pidBuilder.WithKp(3.0).WithKi(0.2).WithKd(0.05).WithIntegralLimit(40.0).Build();
    PID turnPID = pidBuilder.WithKp(5.3).WithKi(0.15).WithKd(0.10).WithIntegralLimit(40.0).Build();
	
	Position::PositionBuilder positionBuilder;
	Position position = positionBuilder.WithLeftDistance(OldOrangeConfig::DRIVE_LEFT_TRACKING_DISTANCE).
										WithRightDistance(OldOrangeConfig::DRIVE_RIGHT_TRACKING_DISTANCE).
										WithStrafeDistance(OldOrangeConfig::DRIVE_STRAFE_TRACKING_DISTANCE).
										Build();

	Drive::DriveBuilder driveBuilder;
	Drive drive = driveBuilder.WithLeftMotor(OldOrangeConfig::leftDrive1Motor).
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
	
	while(true)
	{
		//robot.RobotControl(master);
		//Menu::DrawPosition(robot);
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
}