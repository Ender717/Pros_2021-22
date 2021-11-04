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
   float thetaChange = (leftChange - rightChange) / ROBOT_WIDTH;
   float odometryTheta = oldTheta + thetaChange;

   currentTheta = ((odometryTheta + inertialValue) / 2.0);
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

   // Calculate the expected vs actual drift
   float drift, expected;
   expected = TRACKING_RADIUS * thetaChange;
   drift = centerChange - expected;

   // Calculate the dimensions of the drift
   currentX += drift * cos(currentTheta - 1.5708 + (thetaChange / 2));
   currentY += drift * sin(currentTheta - 1.5708 + (thetaChange / 2));
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