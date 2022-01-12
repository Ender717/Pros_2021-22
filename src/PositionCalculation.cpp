#include "main.h"
#include "PositionCalculation.h"

// Constructor Definitions ----------------------------------------------------
PositionCalculation::PositionCalculation(float startX, float startY,
   float startTheta)
{
   oldLeftValue = 0.0;
   oldRightValue = 0.0;
   oldCenterValue = 0.0;
   newLeftValue = 0.0;
   newRightValue = 0.0;
   newCenterValue = 0.0;
   oldX = startX;
   oldY = startY;
   oldTheta = startTheta;
   currentX = startX;
   currentY = startY;
   currentTheta = startTheta;
   leftChange = newLeftValue - oldLeftValue;
   rightChange = newRightValue - oldRightValue;
   centerChange = newCenterValue - oldCenterValue;
   thetaChange = currentTheta - oldTheta;
}

// Private Method Definitions -------------------------------------------------
void PositionCalculation::UpdateValues(float leftValue, float rightValue,
   float centerValue)
{
   oldLeftValue = newLeftValue;
   oldRightValue = newRightValue;
   oldCenterValue = newCenterValue;
   oldX = currentX;
   oldY = currentY;
   oldTheta = currentTheta;
   newLeftValue = leftValue;
   newRightValue = rightValue;
   newCenterValue = centerValue;
   leftChange = newLeftValue - oldLeftValue;
   rightChange = newRightValue - oldRightValue;
   centerChange = newCenterValue - oldCenterValue;
}

void PositionCalculation::UpdateTheta(float inertialValue)
{
   // Calculate the change in theta using odometry and average the result with
   // the change from the inertial sensor
   thetaChange = (leftChange - rightChange) / (LEFT_DISTANCE + RIGHT_DISTANCE);
   currentTheta = ((oldTheta + thetaChange + inertialValue) / 2.0);
   thetaChange = currentTheta - oldTheta;
}

void PositionCalculation::CalculatePosition()
{
   float distance, drift;

   // Calculate the distance travelled and drifted for a constant angle
   if (thetaChange == 0)
   {
      distance = (leftChange + rightChange) / 2;
      drift = centerChange;
   }

   // Calculate the distance travelled and drifted for a non-constant angle
   else
   {
      distance = 2 * sin(thetaChange / 2) * ((rightChange / thetaChange) + RIGHT_DISTANCE);
      drift = 2 * sin(thetaChange / 2) * ((centerChange / thetaChange) + CENTER_DISTANCE);
   }

   // Calculate the coordinate change
   currentX = oldX + distance * sin(oldTheta + (thetaChange / 2)) 
      + drift * cos(oldTheta + (thetaChange / 2));
   currentY = oldY + distance * cos(oldTheta + (thetaChange / 2)) 
      + drift * -sin(oldTheta + (thetaChange / 2));
}

// Public Method Definitions --------------------------------------------------
void PositionCalculation::UpdatePosition(float leftValue, float rightValue,
   float centerValue, float inertialValue)
{
   UpdateValues(leftValue, rightValue, centerValue);
   UpdateTheta(inertialValue);
   CalculatePosition();
}

float PositionCalculation::getX()
{
   return currentX;
}

float PositionCalculation::getY()
{
   return currentY;
}

float PositionCalculation::getAngle()
{
   return currentTheta;
}