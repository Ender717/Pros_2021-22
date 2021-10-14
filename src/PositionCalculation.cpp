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

}

void PositionCalculation::UpdateTheta(float inertialValue)
{
   /*
   float leftChange = newLeftValue - oldLeftValue;
   float rightChange = newRightValue - oldRightValue;
   
   float odometryTheta = inertialValue;
   if (leftChange * rightChange >= 0) // If both sides are the same direction
   {
      if (std::abs(newLeftValue - oldLeftValue) >
         std::abs(newRightValue - oldRightValue)) // If left moved further
      {
         odometryTheta = (2 * 3.1415 * leftChange) /
            (rightChange + (2 * 3.1415 * ROBOT_WIDTH));
      }
      else if (std::abs(newLeftValue - oldLeftValue) <
         std::abs(newRightValue - oldRightValue)) // If right moved further
      {
         odometryTheta = (2 * 3.1415 * rightChange) /
            (leftChange + (2 * 3.1415 * ROBOT_WIDTH));
      }
      else // If they moved the same amount
      {
         odometryTheta = 0;
      }
      if (leftChange < 0) // If the movement was backward
         odometryTheta += 180.0;
   }
   else if (leftChange * rightChange < 0) // The sides are opposite directions
   {
      odometryTheta = (rightChange - leftChange) / ROBOT_WIDTH;
   }

   currentTheta = oldTheta + ((odometryTheta + inertialValue) / 2.0);
   */
   currentTheta = inertialValue;
}

void PositionCalculation::CalculatePosition()
{
   // Calculate the changes from this cycle
   float leftChange = newLeftValue - oldLeftValue;
   float rightChange = newRightValue - oldRightValue;
   float centerChange = newCenterValue - oldCenterValue;
   float thetaChange = currentTheta - oldTheta;

   // Add the approximate change from the left and right wheels
   currentX = oldX + (((rightChange + leftChange) / 2) * cos(currentTheta + (thetaChange / 2)));
   currentY = oldY + (((rightChange + leftChange) / 2) * sin(currentTheta + (thetaChange / 2)));

   float drift;
   
   if(abs(thetaChange) > 0.001)
   {
      float radius = ((leftChange + rightChange) / 2) / thetaChange;
      float hypotenuse = sqrt((radius * radius) + (TRACKING_RADIUS * TRACKING_RADIUS));
      float trackingAngle = atan(TRACKING_RADIUS / radius);
      drift = -(((leftChange + rightChange) / 2) * cos(trackingAngle));
   }
   else
      drift = centerChange;

   // Calculate the dimensions of the drift
   currentX += drift * std::cos(currentTheta - 1.5708 + (thetaChange / 2));
   currentY += drift * std::sin(currentTheta - 1.5708 + (thetaChange / 2));
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