#pragma once

#ifndef autonController_h
#define autonController_h

#include "headers/utilities/timer.h"
#include <vector>
#include <cstdint>
#include "pros/rtos.hpp"
#include "headers/subsystems/systems.h"
#include "headers/subsystems/robotDrives.h"

namespace autonControllers
{
	class autonController
	{

	public:
		bool finished = true;
		uint32_t lastRun = pros::c::millis();

		std::vector<int> robotFunctionCommands = {};

		void resetAutonController();

		template <typename... Args>
		void addCommands(Args... args)
		{
			robotFunctionCommands = {args...};
			for (int i = 0; i < robotFunctionCommands.size();)
			{
				i = systems::systemsArray[robotFunctionCommands[i]]->addSystemCommands(i + 1, robotFunctionCommands);
			}
			runAutonController();
		}

		void runAutonController();
	};

	extern autonController autonRobotFunction;

} // namespace autonControllers

#endif
