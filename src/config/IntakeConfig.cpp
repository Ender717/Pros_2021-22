// Included libraries
#include "config/IntakeConfig.h"

namespace IntakeConfig
{
    // Ports
    const int INTAKE_PORT = 8;

    // Motors
    pros::Motor intakeMotor(INTAKE_PORT, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_COUNTS);
}