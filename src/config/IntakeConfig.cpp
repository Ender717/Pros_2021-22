// Included libraries
#include "config/IntakeConfig.h"

namespace IntakeConfig
{
    // Ports
    const int INTAKE_PORT = 13;

    // Motors
    pros::Motor intakeMotor(INTAKE_PORT, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_COUNTS);
}