#pragma once
#ifndef CONFIG_H
#define CONFIG_H

namespace config
{

    enum activeSystems
    {
        base
    };
    
    const int NUMBER_OF_SYSTEMS = 1;
    const int ROBOT_FUNCTION_DEFAULT_REFRESH_RATE = 5;

    const float ROBOT_DRIVE_DEFAULT_WHEEL_DIAMETER = 4;
    const float ROBOT_DRIVE_DEFAULT_WHEEL_DISTANCE_FROM_CENTER = 7;
    const float ROBOT_DRIVE_DEFAULT_WHEEL_TICKS_PER_ROTATION = 360;
    const float ROBOT_DRIVE_DEFAULT_ENCODER_DIAMETER = 2.783;
    const float ROBOT_DRIVE_DEFAULT_ENCODER_DISTANCE_FROM_CENTER = 3.625;
    const float ROBOT_DRIVE_DEFAULT_ENCODER_TICKS_PER_ROTATION = 360;
    const float ROBOT_DRIVE_DEFAULT_DISTANCE_THRESHOLD = .5;
    const float ROBOT_DRIVE_DEFAULT_ANGLE_THRESHOLD = 50;

    //lcdCode.cpp
    const int MAX_AUTONOMOUS_MODES = 16;

    //autonomous.cpp
    const bool DEFAULT_AUTONOMOUS_MODE = 1;
}

#endif