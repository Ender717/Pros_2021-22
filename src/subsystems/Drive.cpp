// Included libraries
#include "subsystems/Drive.h"

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
        //distancePID = new PID(5.5, 0.1, 0.3, -125.0, 125.0, 40.0, 0.0);
        //anglePID = new PID(0.5, 0.0, 0.0, -50.0, 50.0, 20.0, 0.0);
        //turnPID = new PID(4.3, 0.05, 0.20, -125.0, 125.0, 40.0, 0.0);
        DriveConfig::leftTrackingSensor.set_position(0.0);
        DriveConfig::rightTrackingSensor.set_position(0.0);
        DriveConfig::strafeTrackingSensor.set_position(0.0);
        DriveConfig::inertialSensor.set_rotation(0.0);
    }

    // Destructor definitions -------------------------------------------------
    Drive::~Drive()
    {
        delete distancePID;
        delete anglePID;
        delete turnPID;
        delete position;
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
        DriveConfig::inertialSensor.reset();
        while (DriveConfig::inertialSensor.is_calibrating())
        {
            pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Inertial is calibrating");
        }
        DriveConfig::inertialSensor.set_rotation(0.0);
    }

    // Public method definitions --------------------------------------------------
    void Drive::DriveStraight(float inches, PositionCalculation& position)
    {
        PID distancePID(5.5, 0.1, 0.3, -125.0, 125.0, 40.0, 0.0);
        DriveConfig::leftTrackingSensor.set_position(0.0);
        float distance = leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
        float controlValue = distancePID.GetControlValue(distance);

        while(abs(inches - distance) > 0.1 || controlValue > 1)
        {
            distance = leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
            controlValue = distancePID.GetControlValue(distance);
            SetLeftDrive(controlValue);
            SetRightDrive(controlValue);
        }
    }

    void Drive::SpinTurn(float degrees, PositionCalculation& position)
    {
        PID turnPID(4.3, 0.05, 0.20, -125.0, 125.0, 40.0, 0.0);
        position.UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                                DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                                DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
        float targetAngle = position.GetTheta() + degrees;
        float angle = position.GetTheta();
        float controlValue = turnPID.GetControlValue(angle);

        while(abs(targetAngle - angle) > 0.1 || controlValue > 1)
        {
            angle = position.GetTheta();
            controlValue = turnPID.GetControlValue(angle);
            SetLeftDrive(controlValue);
            SetRightDrive(-controlValue);
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
        float distance = CalculateDistance(position->GetX(), position->GetY(), targetX, targetY);
        float angle = CalculateAngle(position->GetX(), position->GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                distancePID->SetTargetValue(distance);
                anglePID->SetTargetValue(angle);
                SetLeftDrive(distancePID->GetControlValue(0.0) + anglePID->GetControlValue(position->GetAngle()));
                SetRightDrive(distancePID->GetControlValue(0.0) - anglePID->GetControlValue(position->GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                distancePID->SetTargetValue(-distance);
                anglePID->SetTargetValue(angle);
                SetLeftDrive(distancePID->GetControlValue(0.0) - anglePID->GetControlValue(position->GetAngle()));
                SetRightDrive(distancePID->GetControlValue(0.0) + anglePID->GetControlValue(position->GetAngle()));
            }
        }
    }

    void Drive::DriveThroughPoint(float targetX, float targetY, float power, bool reversed)
    {
        // Set up the control variables
        UpdatePosition();
        float distance = CalculateDistance(position->GetX(), position->GetY(), targetX, targetY);
        float angle = CalculateAngle(position->GetX(), position->GetY(), targetX, targetY);

        // Loop until the target is reached
        while(distance > 0.0)
        {
            // Control for forward motion
            if(!reversed)
            {
                anglePID->SetTargetValue(angle);
                SetLeftDrive(power + anglePID->GetControlValue(position->GetAngle()));
                SetRightDrive(power - anglePID->GetControlValue(position->GetAngle()));
            }
            // Control for backward motion
            else
            {
                angle = angle + 180.0;
                if(angle > 360.0)
                    angle = angle - 360.0;
                anglePID->SetTargetValue(angle);
                SetLeftDrive(-power + anglePID->GetControlValue(position->GetAngle()));
                SetRightDrive(-power - anglePID->GetControlValue(position->GetAngle()));
            }
        }
    }

    float Drive::GetX()
    {
        return position->GetX();
    }

    float Drive::GetY()
    {
        return position->GetY();
    }

    float Drive::GetTheta()
    {
        return position->GetTheta() / DriveConfig::DEGREES_TO_RADIANS;
    }

    void Drive::UpdatePosition()
    {
        position->UpdatePosition(DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION,
                                DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION,
                                DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION);
    }

    void Drive::SetPosition(float x, float y, float theta)
    {
        position->SetPosition(x, y, theta);
    }