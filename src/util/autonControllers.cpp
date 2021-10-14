#include "headers/utilities/autonControllers.h"
#include "headers/subsystems/systems.h"
#include "headers/misc/config.h"
namespace autonControllers
{
// template <typename... Args>
// void autonController::addCommands(Args... args)
// {
// 	robotFunctionCommands = {args...};
// 	for (int i = 0; i < robotFunctionCommands.size(); i++)
// 	{
// 		i = systems::systemsArray[robotFunctionCommands[i]]->addSystemCommands(i + 1, robotFunctionCommands);
// 	}
// 	runAutonController();
// }

void autonController::resetAutonController()
{
	finished = true;
	this->robotFunctionCommands.clear();
	for (int i = 0; i < config::NUMBER_OF_SYSTEMS; i++)
	{
		if (systems::systemsArray[i] != nullptr)
		{
			systems::systemsArray[i]->resetSystemCommads();
		}
	}
}

void autonController::runAutonController()
{
	do
	{
		finished = true;
		for (int i = 0; i < config::NUMBER_OF_SYSTEMS; i++)
		{
			if (systems::systemsArray[i] != nullptr)
			{
				if (!systems::systemsArray[i]->updateSystem())
					finished = false;
			}
		}
		pros::c::task_delay_until(&lastRun, config::ROBOT_FUNCTION_DEFAULT_REFRESH_RATE);
		lastRun = pros::c::millis();
	} while (!finished);
}

autonControllers::autonController autonRobotFunction;
}