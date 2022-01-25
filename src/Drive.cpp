// Included libraries
#include "Drive.h"

// Private method definitions -------------------------------------------------
float Drive::CalculateAngle(float startX, float startY, float endX, float endY)
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

    // Constructor definitions ------------------------------------------------
    Drive::Drive()
    {

    }

    // Public method definitions ----------------------------------------------
    float Drive::CalculateDistance(float startX, float startY, float endX, float endY)
    {
        return sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));
    }

    void Drive::Initialize()
    {
        DriveConfig::leftTrackingSensor.set_position(0.0);
	    DriveConfig::rightTrackingSensor.set_position(0.0);
	    DriveConfig::strafeTrackingSensor.set_position(0.0);
    }

    // Public method definitions --------------------------------------------------
    void Drive::DriveStraight(float inches, bool reversed)
    {
        // DO THIS
    }

    void Drive::SpinTurn(float degrees)
    {
        // Set the PID controller for the motion
        PID turnPID(4.3, 0.05, 0.20, -125.0, 125.0, 40.0, 0.0);
	    DriveConfig::inertialSensor.set_rotation(0.0);
	    turnPID.SetTargetValue(degrees);
        float controlValue = turnPID.GetControlValue(DriveConfig::inertialSensor.get_rotation());

        // Run the control loop
        while(fabs(DriveConfig::inertialSensor.get_rotation() - degrees) > 0.01 || controlValue > 1.0)
        {
		    SetLeftDrive(controlValue);
		    SetRightDrive(-controlValue);
            controlValue = turnPID.GetControlValue(DriveConfig::inertialSensor.get_rotation());
		    pros::delay(2);
        }
    }

    void Drive::SetLeftDrive(float power)
    {
        DriveConfig::leftRearDriveMotor.move(power);
        DriveConfig::leftMiddleDriveMotor.move(power);
        DriveConfig::leftFrontDriveMotor.move(power);
    }

    void Drive::SetRightDrive(float power)
    {
        DriveConfig::rightRearDriveMotor.move(power);
        DriveConfig::rightMiddleDriveMotor.move(power);
        DriveConfig::rightFrontDriveMotor.move(power);
    }

    void Drive::DriveToPoint(float targetX, float targetY, bool reversed)
    {
        // Set up the control variables
        UpdatePosition();
        float distance = CalculateDistance(DriveConfig::positionTracking.GetX(), DriveConfig::positionTracking.GetY(), targetX, targetY);
        float angle = CalculateAngle(DriveConfig::positionTracking.GetX(), DriveConfig::positionTracking.GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                DriveConfig::distancePID.SetTargetValue(distance);
                DriveConfig::anglePID.SetTargetValue(angle);
                SetLeftDrive(DriveConfig::distancePID.GetControlValue(0.0) + DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
                SetRightDrive(DriveConfig::distancePID.GetControlValue(0.0) - DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                DriveConfig::distancePID.SetTargetValue(-distance);
                DriveConfig::anglePID.SetTargetValue(angle);
                SetLeftDrive(DriveConfig::distancePID.GetControlValue(0.0) - DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
                SetRightDrive(DriveConfig::distancePID.GetControlValue(0.0) + DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
            }
        }
    }

    void Drive::DriveThroughPoint(float targetX, float targetY, float power, bool reversed)
    {
        // Set up the control variables
        UpdatePosition();
        float distance = CalculateDistance(DriveConfig::positionTracking.GetX(), DriveConfig::positionTracking.GetY(), targetX, targetY);
        float angle = CalculateAngle(DriveConfig::positionTracking.GetX(), DriveConfig::positionTracking.GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                DriveConfig::anglePID.SetTargetValue(angle);
                SetLeftDrive(power + DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
                SetRightDrive(power - DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                DriveConfig::anglePID.SetTargetValue(angle);
                SetLeftDrive(-power + DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
                SetRightDrive(-power - DriveConfig::anglePID.GetControlValue(DriveConfig::positionTracking.GetAngle()));
            }
        }
    }

    float Drive::GetX()
    {
        return DriveConfig::positionTracking.GetX();
    }

    float Drive::GetY()
    {
        return DriveConfig::positionTracking.GetY();
    }

    float Drive::GetTheta()
    {
        return DriveConfig::positionTracking.GetAngle() / DriveConfig::DEGREES_TO_RADIANS;
    }

    void Drive::UpdatePosition()
    {
        DriveConfig::positionTracking.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                                                     DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                                                     DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION, 
                                                     DriveConfig::inertialSensor.get_rotation() * DriveConfig::DEGREES_TO_RADIANS * DriveConfig::INERTIAL_TUNING);
    }

    void Drive::SetPosition(float x, float y, float theta)
    {
        DriveConfig::positionTracking.SetPosition(x, y, theta);
    }