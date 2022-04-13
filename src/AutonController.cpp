// Library being defined
#include "AutonController.hpp"

// Constructor definitions ----------------------------------------------------
AutonController::AutonController(double x, double y, double theta)
{
    robot = new Robot();
    robot->drive->SetPosition(x, y, theta);
}
