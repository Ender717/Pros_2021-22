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
}

void PositionCalculation::CalculatePosition()
{
   // Calculate the changes from this cycle
   float leftChange = newLeftValue - oldLeftValue;
   float rightChange = newRightValue - oldRightValue;
   float centerChange = newCenterValue - oldCenterValue;
   float thetaChange = currentTheta - oldTheta;

   if (leftChange * rightChange >= 0) // The motion is not a spin
   {
      if (leftChange != rightChange) // The motion is non-linear
      {
         // Calculate the inner and outer radius of the arc
         float innerRadius, outerRadius, centerX, centerY;
         if (std::abs(leftChange) > std::abs(rightChange))
         {
            innerRadius = std::abs(rightChange / thetaChange);
            outerRadius = std::abs(leftChange / thetaChange);
         }
         else
         {
            innerRadius = std::abs(leftChange / thetaChange);
            outerRadius = std::abs(rightChange / thetaChange);
         }

         // Calculate the center of the arc
         centerX = oldX - (((innerRadius + outerRadius) / 2) 
            * std::cos(oldTheta));
         centerY = oldY - (((innerRadius + outerRadius) / 2)
            * std::sin(oldTheta));

         // Calculate the new position
         currentX = centerX + (((innerRadius + outerRadius) / 2)
            * std::cos(currentTheta));
         currentY = centerY + (((innerRadius + outerRadius) / 2)
            * std::sin(currentTheta));

      }
      else // The motion is linear
      {
         // Calculate the new position
         currentX = oldX + (leftChange * std::cos(currentTheta));
         currentY = oldY + (leftChange * std::sin(currentTheta));
      }
   }
   else // The motion is a spin
   {
      // Calculate the small and large radius of the butterfly
      float largeRadius, smallRadius, originX, originY;
      if (std::abs(leftChange) > std::abs(rightChange))
      {
         largeRadius = std::abs(leftChange / thetaChange);
         smallRadius = std::abs(rightChange / thetaChange);
      }
      else
      {
         largeRadius = std::abs(rightChange / thetaChange);
         smallRadius = std::abs(leftChange / thetaChange);
      }

      // Calculate the origin of the butterfly
      originX = oldX + ((ROBOT_WIDTH - largeRadius) * std::cos(oldTheta);
      originY = oldY + ((ROBOT_WIDTH - largeRadius) * std::sin(oldTheta);

      // Calculate the new position
      currentX = originX + (largeRadius * std::cos(currentTheta));
      currentY = originY + (largeRadius * std::sin(currentTheta));
   }

   // Calculate the sideways drift
   float drift = centerChange - (TRACKING_RADIUS * (newTheta - oldTheta));

   // Calculate the dimensions of the drift
   float centerRadius = std::abs(centerChange / thetaChange);
   currentX += centerRadius * std::cos(thetaChange);
   currentY += centerRadius * std::sin(thetaChange);
}

// Public Method Definitions --------------------------------------------------
void PositionCalculation::UpdatePosition(float leftValue, float rightValue,
   float centerValue, float inertialValue)
{
   UpdateValues();
   UpdateTheta(inertialValue);
   CalculatePosition();
}

float getX()
{
   return currentX;
}

float getY()
{
   return currentY;
}

float getAngle()
{
   return currentTheta;
}