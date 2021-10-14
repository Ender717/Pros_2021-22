#include "util/autonCommands.h"
#include "misc/config.h"
#include "util/systems.h"
#include <cmath>
#include "misc/mathTools.h"
#include "pros/adi.hpp"
#include "util/timer.h"
#include "misc/globals.h"

namespace AutonCommands 
{

int AutonCommand::addSystemCommands(int readPosition, std::vector<int> &commands)
{  
  int numberOfCommands = 0;
  switch (commands[readPosition])
  {

  case waitFor:
    numberOfCommands = 0;
    systemCommands.push_back(commands[readPosition]);
    systemCommands.push_back(commands[readPosition] + 1);
    systemCommands.push_back(systems::systemsArray[commands[readPosition + 1]]->systemCommands.size());
    readPosition += 3;
    break;
  case maxTime:
    numberOfCommands = 2;
    break;
  case end:
    numberOfCommands = 2;
    break;
  case waitForTime:
    numberOfCommands = 2;
    break;
  case driveTo:
    numberOfCommands = 3;
    break;
  case driveThrough:
    numberOfCommands = 3;
    break;
  case turnToPoint:
    numberOfCommands = 3;
    break;
  case turnToAngle:
    numberOfCommands = 2;
    break;
  default:
    numberOfCommands = 0;
    readPosition++;
    break;
  }
  for (int i = 0; i < numberOfCommands; i++)
  {
    systemCommands.push_back(commands[readPosition]);
    readPosition++;
  }
  return readPosition;
}

bool AutonCommand::updateSystem()
{
  pros::lcd::print(0, "X =  %f", drivePositionTracker.getX());
  pros::lcd::print(1, "Y =  %f", drivePositionTracker.getY());
  pros::lcd::print(2, "A =  %d", drivePositionTracker.getAngle());
  //pros::lcd::print(3, "Left =  %f", drivePositionTracker.getCurrLeftEnc());
  pros::lcd::print(4, "deltaA =  %f", mathTools::direction360(direction, drivePositionTracker.getAngle()) * mathTools::distance360(direction, drivePositionTracker.getAngle()));
  //pros::lcd::print(5, "Strafe =  %f", drivePositionTracker.getCurrStrafeEnc());
  pros::lcd::print(6, "Strafe =  %f", leftSpeed);
  pros::lcd::print(7, "Strafe =  %f", rightSpeed);

  if (systemReadPos < systemCommands.size())
  {
    switch (systemCommands[systemReadPos])
    {
    case waitFor:
    {
      if ((systems::systemsArray[systemCommands[systemReadPos + 1]]->systemReadPos > systemCommands[systemReadPos] + 2) && systems::systemsArray[systemCommands[systemReadPos + 1]]->systemDone)
      {
        systemReadPos += 3;
      }
    }
    break;
    case maxTime:
      systemMaxTime = systemCommands[systemReadPos + 1];
      systemReadPos += 2;
      break;
    case end:
      systemDone = true;
      systemMaxTime = 0;
      systemReadPos++;
      break;
    case waitForTime:
      if (systemDone)
      {
        if (systemMaxTime == 0)
        {
          systemTimer.zeroTimer();
          systemTimer.startTimer();
          systemMaxTime = systemCommands[systemReadPos + 1];
        }
        else if (systemTimer.currentTime() >= systemMaxTime)
        {
          systemReadPos += 2;
        }
      }
      break;
    default:
      if (systemDone)
      {
        systemTimer.zeroTimer();
        drivePIDTimer.stopTimer();
        drivePIDTimer.zeroTimer();

        // driveTurnPID.resetPID();
        // driveDistancePID.resetPID();
        // turnPID.resetPID();

        // driveTurnPID.setTarget(0);
        // driveDistancePID.setTarget(0);
        // turnPID.setTarget(0);

        systemTimer.stopTimer();
        systemTimer.zeroTimer();

        systemMaxTime = 0;
        systemDone = false;

        switch (systemCommands[systemReadPos])
        {
        case driveTo:
          driveCommand = driveTo;
          systemReadPos++;
          targetX = systemCommands[systemReadPos];
          systemReadPos++;
          targetY = systemCommands[systemReadPos];
          systemReadPos++;
          break;

        case driveThrough:
          driveCommand = systemCommands[systemReadPos];
          systemReadPos++;
          targetX = systemCommands[systemReadPos];
          systemReadPos++;
          targetY = systemCommands[systemReadPos];
          systemReadPos++;
          break;

        case turnToPoint:
          driveCommand = systemCommands[systemReadPos];
          systemReadPos++;
          targetX = systemCommands[systemReadPos];
          systemReadPos++;
          targetY = systemCommands[systemReadPos];
          systemReadPos++;
          break;

        case turnToAngle:
          driveCommand = systemCommands[systemReadPos];
          systemReadPos++;
          targetAngle = systemCommands[systemReadPos];
          systemReadPos++;
          break;

        default:
          systemReadPos++;
          break;
        }
      }

      break;
    }
  }
  executeSystemFunction();
  if (systemReadPos >= systemCommands.size() && systemDone)
  {
    systemCompleted = true;
  }
  return systemCompleted;
}

void AutonCommand::executeSystemFunction()
{
  if (systemMaxTime != 0 && systemTimer.currentTime() >= systemMaxTime)
  {
    systemMaxTime = 0;
    systemDone = true;
  }
  if (!this->systemDone) // if the drive is not done
  {
    switch (driveCommand)
    {
    case driveTo:

      deltaX = targetX - drivePositionTracker.getX();
      deltaY = targetY - drivePositionTracker.getY();
      direction = atan(deltaY / deltaX);
      distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    //   leftSpeed = rightSpeed = driveDistancePID.setPID(-distance, avgDriveRot());
    //   leftSpeed += (fabs(leftSpeed) * driveTurnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                                                       mathTools::distance360(direction, drivePositionTracker.getCurrA()), avgDriveRot()));
    //   rightSpeed -= (fabs(rightSpeed) * driveTurnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                                                       mathTools::distance360(direction, drivePositionTracker.getCurrA()), avgDriveRot()));

      if (distance <= distanceThreshold)
      {
        drivePIDTimer.startTimer();
      }
      if (drivePIDTimer.currentTime() > 300)
      {
        leftSpeed = 0;
        rightSpeed = 0;
        this->systemDone = true;
      }
      break;

    case driveThrough:

    //   deltaX = targetX - drivePositionTracker.getCurrX();
    //   deltaY = targetY - drivePositionTracker.getCurrY();
    //   direction = atan(deltaY / deltaX);
    //   distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    //   leftSpeed = rightSpeed = 127;

    //   leftSpeed += (fabs(leftSpeed) * driveTurnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                                                       mathTools::distance360(direction, drivePositionTracker.getCurrA()), avgDriveRot()));
    //   rightSpeed -= (fabs(rightSpeed) * driveTurnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                                                       mathTools::distance360(direction, drivePositionTracker.getCurrA()), avgDriveRot()));

    //   if (distance <= distanceThreshold)
    //   {
    //     drivePIDTimer.startTimer();
    //   }
    //   if (drivePIDTimer.currentTime() > 300)
    //     this->systemDone = true;
      break;

    case turnToPoint:
    //   deltaX = targetX - drivePositionTracker.getCurrX();
    //   deltaY = targetY - drivePositionTracker.getCurrY();
    //   direction = atan(deltaY / deltaX);

    //   leftSpeed = turnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                              mathTools::distance360(direction, drivePositionTracker.getCurrA()), drivePositionTracker.getCurrA());
    //   rightSpeed = -leftSpeed;

    //   if (direction - drivePositionTracker.getCurrA() <= angleThreshold)
    //   {
    //     drivePIDTimer.startTimer();
    //   }
    //   if (drivePIDTimer.currentTime() > 300)
    //     this->systemDone = true;
      break;

    case turnToAngle:
    //   direction = targetAngle;

    //   leftSpeed = turnPID.setPID(mathTools::direction360(direction, drivePositionTracker.getCurrA()) * 
    //                              mathTools::distance360(direction, drivePositionTracker.getCurrA()), drivePositionTracker.getCurrA());
    //   rightSpeed = -leftSpeed;

    //   if (direction - drivePositionTracker.getCurrA() <= angleThreshold)
    //   {
    //     drivePIDTimer.startTimer();
    //   }
    //   if (drivePIDTimer.currentTime() > 300)
    //     this->systemDone = true;
      break;

    default:
      leftSpeed = 0;
      rightSpeed = 0;
    }
    //tankStraightDrive(leftSpeed, rightSpeed);
  }
  else
  {
    systemMaxTime = 0;
    //tankStraightDrive(0, 0);
  }
}

AutonCommand mainAutonCommand;
}