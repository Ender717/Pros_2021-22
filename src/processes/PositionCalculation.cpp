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
   float strafeValue = DriveConfig::strafeTrackingSensor.get_position() * DriveConfig::TRACKING_WHEEL_SIZE * DriveConfig::PI / -DriveConfig::COUNTS_PER_ROTATION;

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
   float forwardDistance, sidewaysDistance;
   if (thetaChange == 0)
   {
      sidewaysDistance = strafeDistance;
      forwardDistance = rightDistance;
   }
   else
   {
      sidewaysDistance = (2 * sin(currentTheta / 2)) * ((strafeDistance / thetaChange) + STRAFE_DISTANCE);
      forwardDistance = (2 * sin(currentTheta / 2)) * ((rightDistance / thetaChange) + RIGHT_DISTANCE);
   }

   // Calculate the average orientation
   float averageTheta = lastTheta + (thetaChange / 2);

   // Calculate the global offset
   float polarDistance = sqrt((sidewaysDistance * sidewaysDistance) + (forwardDistance * forwardDistance));
   float polarAngle = atan(forwardDistance / sidewaysDistance) - averageTheta;
   float xChange = polarDistance * cos(polarAngle);
   float yChange = polarDistance * sin(polarAngle);

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
   return currentTheta;
}