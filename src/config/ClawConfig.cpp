// Included libraries
#include "config/ClawConfig.h"

namespace ClawConfig
{
    // Constants
    const float OPEN_POSITION = 5000.0;
    const float CLOSED_POSITION = 8000.0;

    // Ports
    extern const int CLAW_PORT = 15;

    // Motors
    pros::Motor clawMotor(CLAW_PORT, pros::E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_COUNTS);
}

#endif