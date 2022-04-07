// Defined library
#include "config/OldOrangeConfig.hpp"

namespace OldOrangeConfig
{
    // Constants
    const double CLAW_OPEN_POSITION = 515.0;
    const double CLAW_CLOSED_POSITION = 5.0;
    const double DRIVE_TRACKING_WHEEL_SIZE = 2.75;
    const double DRIVE_LEFT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_RIGHT_TRACKING_DISTANCE = 6.0313;
    const double DRIVE_STRAFE_TRACKING_DISTANCE = 1.50;
    const double DRIVE_COUNTS_PER_ROTATION = 36000.0;
    const double LIFT_BOTTOM_POSITION = -18.0;
    const double LIFT_TOP_POSITION = 110.0;
    const double LIFT_START_POSITION = 75.0;
    const double LIFT_COUNTS_PER_DEGREE = 25.0;

    // Motor ports
    const int CLAW_1_PORT = 7;
    const int LEFT_DRIVE_1_PORT = 11;
    const int LEFT_DRIVE_2_PORT = 12;
    const int LEFT_DRIVE_3_PORT = 13;
    const int RIGHT_DRIVE_1_PORT = 18;
    const int RIGHT_DRIVE_2_PORT = 19;
    const int RIGHT_DRIVE_3_PORT = 20;
    const int INTAKE_1_PORT = 8;
    const int LEFT_LIFT_1_PORT = 9;
    const int RIGHT_LIFT_1_PORT = 6;

    // Sensor ports
    const int LEFT_DRIVE_TRACKING_PORT = 14;
    const int RIGHT_DRIVE_TRACKING_PORT = 17;
    const int STRAFE_DRIVE_TRACKING_PORT = 16;

    // Piston ports
    const char CARRIER_1_PORT = 'A';
    const char CARRIER_2_PORT = 'B';
}