// Included libraries
#include "Drive.h"

namespace Drive
{
    float CalculateAngle(float startX, float startY, float endX, float endY)
    {
        float angle;
        // Run the normal calculation if the values are not equal
        if(startX != endX && startY != endY)
        {
            angle = atan2f(fabs(endY - startY), fabs(endX - startX));

            // Place the angle in the correct quadrant
            if(endX < startX && endY > startY)
                angle = 180.0 - angle;
            else if (endX < startX && endY < startY)
                angle += 180.0;
            else if (endX > startX && endY < startY)
                angle = 360.0 - angle;
        }
        // Find the angle if both points lie on the same y-axis
        else if (startX == endX)
        {
            if(endY > startY)
                angle = 90.0;
            else
                angle = 270.0;
        }
        // Find the angle if both points lie on the same x-axis
        else
        {
            if(endX > startX)
                angle = 0.0;
            else
                angle = 180.0;
        }

        // return the result
        return angle;
    }

    float CalculateDistance(float startX, float startY, float endX, float endY)
    {
        return sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));
    }

    pros::Motor leftRearDriveMotor(Drive::LEFT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                   true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftMiddleDriveMotor(Drive::LEFT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06, 
                                     false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftFrontDriveMotor(Drive::LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightRearDriveMotor(Drive::RIGHT_REAR_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                    false, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightMiddleDriveMotor(Drive::RIGHT_MIDDLE_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                      true, E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightFrontDriveMotor(Drive::RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEARSET_06,
                                     false, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    pros::Rotation leftTrackingSensor(Drive::LEFT_TRACKING_PORT);
    pros::Rotation rightTrackingSensor(Drive::RIGHT_TRACKING_PORT);
    pros::Rotation strafeTrackingSensor(Drive::STRAFE_TRACKING_PORT);
    pros::Imu inertialSensor(INERTIAL_PORT);

    // Processes
    PositionCalculation positionTracking(0.0, 0.0, 0.0); // THIS IS SET IN AUTON
    PID distancePID(7.0, 0.0, 0.0, -125.0, 125.0, 0.0, 0.0);
    PID anglePID(0.0, 0.0, 0.0, -50.0, 50.0, 10.0, 0.0);
    PID turnPID(10.0, 10.0, 10.0, -125.0, 125.0, 50.0, 0.0);

    void Initialize()
    {
        inertialSensor.reset();
        while (inertialSensor.is_calibrating()) 
        {
            pros::screen::print(text_format_e_t::E_TEXT_LARGE, 100, 150, "Inertial sensor calibrating");
        }
        leftTrackingSensor.set_position(0.0);
	    rightTrackingSensor.set_position(0.0);
	    strafeTrackingSensor.set_position(0.0);
    }

    // Public method definitions --------------------------------------------------
    void DriveStraight(float inches, bool reversed)
    {
        // DO THIS
    }

    void SpinTurn(float degrees)
    {
        // Set the PID controller for the motion
        UpdatePosition();
        turnPID.SetTargetValue(positionTracking.GetAngle());

        // Run the control loop
        while(fabs(turnPID.GetControlValue(positionTracking.GetAngle())) > 0.0)
        {
            UpdatePosition();
            SetLeftDrive(turnPID.GetControlValue(positionTracking.GetAngle()));
            SetRightDrive(-turnPID.GetControlValue(positionTracking.GetAngle()));
        }
    }

    void SetLeftDrive(float power)
    {
        leftRearDriveMotor.move(power);
        leftMiddleDriveMotor.move(power);
        leftFrontDriveMotor.move(power);
    }

    void SetRightDrive(float power)
    {
        rightRearDriveMotor.move(power);
        rightMiddleDriveMotor.move(power);
        rightFrontDriveMotor.move(power);
    }

    void DriveToPoint(float targetX, float targetY, bool reversed)
    {
        // Set up the control variables
        UpdatePosition();
        float distance = CalculateDistance(positionTracking.GetX(), positionTracking.GetY(), targetX, targetY);
        float angle = CalculateAngle(positionTracking.GetX(), positionTracking.GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                distancePID.SetTargetValue(distance);
                anglePID.SetTargetValue(angle);
                SetLeftDrive(distancePID.GetControlValue(0.0) + anglePID.GetControlValue(positionTracking.GetAngle()));
                SetRightDrive(distancePID.GetControlValue(0.0) - anglePID.GetControlValue(positionTracking.GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                distancePID.SetTargetValue(-distance);
                anglePID.SetTargetValue(angle);
                SetLeftDrive(distancePID.GetControlValue(0.0) - anglePID.GetControlValue(positionTracking.GetAngle()));
                SetRightDrive(distancePID.GetControlValue(0.0) + anglePID.GetControlValue(positionTracking.GetAngle()));
            }
        }
    }

    void DriveThroughPoint(float targetX, float targetY, float power, bool reversed)
    {
        // Set up the control variables
        UpdatePosition();
        float distance = CalculateDistance(positionTracking.GetX(), positionTracking.GetY(), targetX, targetY);
        float angle = CalculateAngle(positionTracking.GetX(), positionTracking.GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                anglePID.SetTargetValue(angle);
                SetLeftDrive(power + anglePID.GetControlValue(positionTracking.GetAngle()));
                SetRightDrive(power - anglePID.GetControlValue(positionTracking.GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                anglePID.SetTargetValue(angle);
                SetLeftDrive(-power + anglePID.GetControlValue(positionTracking.GetAngle()));
                SetRightDrive(-power - anglePID.GetControlValue(positionTracking.GetAngle()));
            }
        }
    }

    float GetX()
    {
        return positionTracking.GetX();
    }

    float GetY()
    {
        return positionTracking.GetY();
    }

    float GetTheta()
    {
        return positionTracking.GetAngle() / DEGREES_TO_RADIANS;
    }

    void UpdatePosition()
    {
        positionTracking.UpdatePosition(leftTrackingSensor.get_position() * TRACKING_WHEEL_SIZE * PI / COUNTS_PER_ROTATION,
                                        rightTrackingSensor.get_position() * TRACKING_WHEEL_SIZE * PI / -COUNTS_PER_ROTATION,
                                        strafeTrackingSensor.get_position() * TRACKING_WHEEL_SIZE * PI / -COUNTS_PER_ROTATION, 
                                        inertialSensor.get_rotation() * DEGREES_TO_RADIANS * INERTIAL_TUNING);
    }

    void SetPosition(float x, float y, float theta)
    {
        positionTracking.SetPosition(x, y, theta);
    }
}