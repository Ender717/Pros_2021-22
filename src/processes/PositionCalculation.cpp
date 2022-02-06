#include "main.h"
#include "processes/PositionCalculation.h"

// Constructor Definitions ----------------------------------------------------
PositionCalculation::PositionCalculation(float startX, float startY,
   float startTheta)
{
   currentX = startX;
   currentY = startY;
   currentTheta = startTheta;
   lastLeft = 0.0;
   lastRight = 0.0;
   lastStrafe = 0.0;
   lastTheta = 0.0;
}

// Public Method Definitions --------------------------------------------------
void PositionCalculation::SetPosition(float x, float y, float theta)
{
   currentX = x;
   currentY = y;
   currentTheta = theta;
}

void PositionCalculation::UpdatePosition()
{
   // Calculate the number of inches moved by each wheel
   float leftValue = DriveConfig::leftTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;
   float rightValue = DriveConfig::rightTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION;
   float strafeValue = DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / DriveConfig::COUNTS_PER_ROTATION;

   // Calculate the distance moved by each wheel since the last cycle
   float leftDistance = leftValue - lastLeft;
   float rightDistance = rightValue - lastRight;
   float strafeDistance = strafeValue - lastStrafe;

   // Calculate absolute theta
   float totalLeft = leftValue;
   float totalRight = rightValue;
   currentTheta = (totalLeft - totalRight) / (LEFT_DISTANCE + RIGHT_DISTANCE);

   // Calculate the change in theta
   float thetaChange = currentTheta - lastTheta;

   // Calculate the local offset
   float forwardDistance = 0.0;
   float sidewaysDistance = 0.0;
   if (thetaChange == 0.0)
   {
      sidewaysDistance = strafeDistance;
      forwardDistance = rightDistance;
   }
   else
   {
      sidewaysDistance = (2.0 * sin(thetaChange / 2.0)) * ((strafeDistance / thetaChange) + STRAFE_DISTANCE);
      forwardDistance = (2.0 * sin(thetaChange / 2.0)) * ((rightDistance / thetaChange) + RIGHT_DISTANCE);
   }

   // Calculate the average orientation
   float averageTheta = lastTheta + (thetaChange / 2.0);

   // Calculate the global offset
   float xChange = sidewaysDistance * cos(averageTheta) + forwardDistance * sin(averageTheta);
   float yChange = sidewaysDistance * -sin(averageTheta) + forwardDistance * cos(averageTheta);

   // Calculate the new absolute position
   currentX += xChange;
   currentY += yChange;

   // Update the stored previous values
   lastLeft = leftValue;
   lastRight = rightValue;
   lastStrafe = strafeValue;
   lastTheta = currentTheta;
}

float PositionCalculation::GetX()
{
   return currentX;
}

float PositionCalculation::GetY()
{
   return currentY;
}

float PositionCalculation::GetTheta()
{
   return currentTheta / DriveConfig::DEGREES_TO_RADIANS;
}