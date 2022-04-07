// Defined library
#include "config/BlueConfig.hpp"

namespace BlueConfig
{
    // Constants
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_LEFT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_RIGHT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_STRAFE_TRACKING_DISTANCE = 1.50;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -8.5;
    const double LIFT_TOP_POSITION = 110.0;
    const double LIFT_START_POSITION = 90.0;
    const double LIFT_COUNTS_PER_DEGREE = 2.8125;

    // Motor ports
    const int LEFT_DRIVE_1_PORT = 12;
    const int LEFT_DRIVE_2_PORT = 11;
    const int LEFT_DRIVE_3_PORT = 13;
    const int LEFT_DRIVE_4_PORT = 14;
    const int RIGHT_DRIVE_1_PORT = 20;
    const int RIGHT_DRIVE_2_PORT = 17;
    const int RIGHT_DRIVE_3_PORT = 15;
    const int RIGHT_DRIVE_4_PORT = 16;
    const int INTAKE_1_PORT = 19;
    const int LEFT_LIFT_1_PORT = 5;
    const int LEFT_LIFT_2_PORT = 4;
    const int RIGHT_LIFT_1_PORT = 2;
    const int RIGHT_LIFT_2_PORT = 1;

    // Sensor ports
    const int LEFT_DRIVE_TRACKING_PORT = -1;
    const int RIGHT_DRIVE_TRACKING_PORT = -1;
    const int STRAFE_DRIVE_TRACKING_PORT = -1;

    // Piston ports
    const char CARRIER_1_PORT = 'A';
    const char CLAW_1_PORT = 'G';
}