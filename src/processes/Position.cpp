#include "processes/Position.hpp"

// Constructor Definitions ----------------------------------------------------
Position::Position()
{
   currentX = 0.0;
   currentY = 0.0;
   currentTheta = 0.0;
   resetTheta = 0.0;
   lastTheta = 0.0;
   lastLeft = 0.0;
   lastRight = 0.0;
   lastStrafe = 0.0;
}

// Public Method Definitions --------------------------------------------------
void Position::SetPosition(double x, double y, double theta)
{
   currentX = x;
   currentY = y;
   currentTheta = theta;
   resetTheta = theta;
}

void Position::UpdatePosition(double leftValue, double rightValue, double strafeValue)
{
   // Calculate the distance moved by each wheel since the last cycle
   double leftDistance = leftValue - lastLeft;
   double rightDistance = rightValue - lastRight;
   double strafeDistance = strafeValue - lastStrafe;

   // Calculate absolute theta
   double totalLeft = leftValue;
   double totalRight = rightValue;
   currentTheta = ((totalRight - totalLeft) / (leftTrackingDistance + rightTrackingDistance)) + resetTheta;

   // Calculate the change in theta
   double thetaChange = currentTheta - lastTheta;
   
   // Cap current theta
   if (currentTheta > 3.1415)
      currentTheta -= 7.2830;
   else if (currentTheta < -3.1415)
      currentTheta += 7.2830;

   // Calculate the local offset
   double forwardDistance = 0.0;
   double sidewaysDistance = 0.0;
   if (thetaChange == 0.0)
   {
      sidewaysDistance = strafeDistance;
      forwardDistance = rightDistance;
   }
   else
   {
      sidewaysDistance = (2.0 * sin(thetaChange / 2.0)) * ((strafeDistance / thetaChange) + strafeTrackingDistance);
      forwardDistance = (2.0 * sin(thetaChange / 2.0)) * ((leftDistance / thetaChange) + leftTrackingDistance);
   }

   // Calculate the average orientation
   double averageTheta = lastTheta + (thetaChange / 2.0);

   // Calculate the global offset
   double xChange = sidewaysDistance * -sin(averageTheta) + forwardDistance * cos(averageTheta);
   double yChange = sidewaysDistance * cos(averageTheta) + forwardDistance * sin(averageTheta);

   // Calculate the new absolute position
   currentX += xChange;
   currentY += yChange;

   // Update the stored previous values
   lastLeft = leftValue;
   lastRight = rightValue;
   lastStrafe = strafeValue;
   lastTheta = currentTheta;
}

double Position::GetX() const
{
   return currentX;
}

double Position::GetY() const
{
   return currentY;
}

double Position::GetTheta() const
{
   return currentTheta;
}