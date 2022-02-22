// Included libraries
#include "config/ClawConfig.h"

namespace ClawConfig
{
    // Constants
    const float OPEN_POSITION = 515.0;
    const float CLOSED_POSITION = 5.0;
    const float GOAL_THRESHOLD = 100.0;

    // Ports
    const int CLAW_PORT = 5;
    const int GOAL_SENSOR_PORT = 9;

    // Motors
    pros::Motor clawMotor(CLAW_PORT, pros::E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);

    // Sensors
    pros::Optical goalSensor(GOAL_SENSOR_PORT);
}