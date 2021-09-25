#include "PositionCalculation.h"
#include "api.h"

PositionCalculation::PositionCalculation(float startX, float startY,
   float startTheta)
{
   oldLeftValue = 0.0;
   oldRightValue = 0.0;
   oldTheta = startTheta;
   newLeftValue = 0.0;
   newRightValue = 0.0;
   newTheta = startTheta;
   currentX = startX;
   currentY = startY;
   currentTheta = startTheta;
}

void PositionCalculation::UpdateValues(float leftValue, float rightValue,
   float angle)
{
   oldLeftValue = newLeftValue;
   oldRightValue = newRightValue;
   oldTheta = newTheta;
   newLeftValue = leftValue;
   newRightValue = rightValue;
   newTheta = angle;
}

void PositionCalcuation::CalculateTheta(float inertialValue)
{
   float leftChange = newLeftValue - oldLeftValue;
   float rightChange = newRightValue - oldRightValue;
   
   float odometryTheta;
   if (leftChange * rightChange > 0) // If both sides are the same direction
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

   }

   newTheta = (odometryTheta + inertialValue) / 2.0;
}