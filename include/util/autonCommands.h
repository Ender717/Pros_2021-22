#pragma once
#ifndef AUTONCOMMANDS_H
#define AUTONCOMMANDS_H

#include "main.h"
#include <vector>
//#include "misc/systems.h"
namespace AutonCommands
{
  
enum autonCommands
  {
    waitFor,
    maxTime,
    end,
    waitForTime,
    driveTo,
    driveThrough,
    turnToPoint,
    turnToAngle
  };

class AutonCommand : public systems::system
{
public:
  float leftSpeed = 0;  // left drive speed
  float rightSpeed = 0; // right drive speed
  float strafeSpeed = 0;
  int driveCommand = -1;

  float targetX = 0;
  float targetY = 0;
  float targetAngle = 0;

  float deltaX = 0;
  float deltaY = 0;
  float direction = 0;
  float distance = 0;

  float leftDriveSensorLastReset = 0;
  float rightDriveSensorLastReset = 0;
  float strafeDriveSensorLastReset = 0;

  float leftEncoderDiameter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DIAMETER;
  float rightEncoderDiameter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DIAMETER;
  float strafeEncoderDiameter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DIAMETER;

  float leftEncoderDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DISTANCE_FROM_CENTER;
  float rightEncoderDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DISTANCE_FROM_CENTER;
  float strafeEncoderDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_ENCODER_DISTANCE_FROM_CENTER;

  float leftEncoderTicksPerRotation = config::ROBOT_DRIVE_DEFAULT_ENCODER_TICKS_PER_ROTATION;
  float rightEncoderTicksPerRotation = config::ROBOT_DRIVE_DEFAULT_ENCODER_TICKS_PER_ROTATION;
  float strafeEncoderTicksPerRotation = config::ROBOT_DRIVE_DEFAULT_ENCODER_TICKS_PER_ROTATION;

  float leftWheelDiameter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DIAMETER;
  float rightWheelDiameter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DIAMETER;
  float strafeWheelDiameter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DIAMETER;

  float leftWheelDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DISTANCE_FROM_CENTER;
  float rightWheelDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DISTANCE_FROM_CENTER;
  float strafeWheelDistanceFromCenter = config::ROBOT_DRIVE_DEFAULT_WHEEL_DISTANCE_FROM_CENTER;

  float leftWheelPerRotation = config::ROBOT_DRIVE_DEFAULT_WHEEL_TICKS_PER_ROTATION;
  float rightWheelTicksPerRotation = config::ROBOT_DRIVE_DEFAULT_WHEEL_TICKS_PER_ROTATION;
  float strafeWheelTicksPerRotation = config::ROBOT_DRIVE_DEFAULT_WHEEL_TICKS_PER_ROTATION;

  float distanceThreshold = config::ROBOT_DRIVE_DEFAULT_DISTANCE_THRESHOLD;
  float angleThreshold = config::ROBOT_DRIVE_DEFAULT_ANGLE_THRESHOLD;

  float heading = 0;

  bool waitingForTimer = false;

  int addSystemCommands(int readPosition, std::vector<int> &commands);

  bool updateSystem();

  void executeSystemFunction();

  timer drivePIDTimer;
};
}
#endif