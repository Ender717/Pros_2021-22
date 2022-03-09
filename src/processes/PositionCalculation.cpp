#include "main.h"
#include "processes/PositionCalculation.h"

// Constructor Definitions ----------------------------------------------------
PositionCalculation::PositionCalculation(float startX, float startY,
   float startTheta)
{
   currentX = startX;
   currentY = startY;
   currentTheta = startTheta;
   resetTheta = startTheta;
   lastTheta = startTheta;
   lastLeft = 0.0;
   lastRight = 0.0;
   lastStrafe = 0.0;
}

// Public Method Definitions --------------------------------------------------
void PositionCalculation::SetPosition(float x, float y, float theta)
{
   currentX = x;
   currentY = y;
   currentTheta = theta;
   resetTheta = theta;
}

void PositionCalculation::UpdatePosition(float leftValue, float rightValue, float strafeValue)
{
   // Calculate the distance moved by each wheel since the last cycle
   float leftDistance = leftValue - lastLeft;
   float rightDistance = rightValue - lastRight;
   float strafeDistance = strafeValue - lastStrafe;

   // Calculate absolute theta
   float totalLeft = leftValue;
   float totalRight = rightValue;
   currentTheta = ((totalRight - totalLeft) / (LEFT_DISTANCE + RIGHT_DISTANCE)) + resetTheta;

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
      forwardDistance = (2.0 * sin(thetaChange / 2.0)) * ((leftDistance / thetaChange) + LEFT_DISTANCE);
   }

   // Calculate the average orientation
   float averageTheta = lastTheta + (thetaChange / 2.0);

   // Calculate the global offset
   float xChange = sidewaysDistance * -sin(averageTheta) + forwardDistance * cos(averageTheta);
   float yChange = sidewaysDistance * cos(averageTheta) + forwardDistance * sin(averageTheta);

   // Calculate the new absolute position
   currentX += xChange;
   currentY += yChange;

   // Update the stored previous values
   lastLeft = leftValue;
   lastRight = rightValue;
   lastStrafe = strafeValue;
   lastTheta = currentTheta;
}

float PositionCalculation::GetX() const
{
   return currentX;
}

float PositionCalculation::GetY() const
{
   return currentY;
}

float PositionCalculation::GetTheta() const
{
   return currentTheta;
}