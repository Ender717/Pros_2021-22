// Defined library
#include "config/OrangeConfig.hpp"

namespace OrangeConfig
{
    // Constants
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_LEFT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_RIGHT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_STRAFE_TRACKING_DISTANCE = 1.50;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -8.5;
    const double LIFT_TOP_POSITION = 140.0;
    const double LIFT_START_POSITION = 130.0;
    const double LIFT_COUNTS_PER_DEGREE = 12.5;

    // Motor ports
    const int LEFT_DRIVE_1_PORT = 14;
    const int LEFT_DRIVE_2_PORT = 13;
    const int LEFT_DRIVE_3_PORT = 12;
    const int LEFT_DRIVE_4_PORT = 11;
    const int RIGHT_DRIVE_1_PORT = 6;
    const int RIGHT_DRIVE_2_PORT = 3;
    const int RIGHT_DRIVE_3_PORT = 2;
    const int RIGHT_DRIVE_4_PORT = 1;
    const int INTAKE_1_PORT = -1;
    const int LEFT_LIFT_1_PORT = 15;
    const int LEFT_LIFT_2_PORT = 16;
    const int RIGHT_LIFT_1_PORT = 7;
    const int RIGHT_LIFT_2_PORT = 8;

    // Sensor ports
    const int LEFT_DRIVE_TRACKING_PORT = -1;
    const int RIGHT_DRIVE_TRACKING_PORT = -1;
    const int STRAFE_DRIVE_TRACKING_PORT = -1;

    // Piston ports
    const char CARRIER_1_PORT = 'A';
    const char CARRIER_2_PORT = 'X';
    const char CLAW_1_PORT = 'X';
    const char CLAW_2_PORT = 'X';
}