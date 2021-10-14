#include "headers/subsystems/systems.h"

namespace systems
{
int system::addSystemCommands(int i, std::vector<int> &commands)
{
  return 0;
}
void system::executeSystemFunction()
{
}
bool system::updateSystem()
{
  return 0;
}
void system::resetSystemCommads()
{
  systemCommands.clear();
  systemReadPos = 0;
}
system *systemsArray[config::NUMBER_OF_SYSTEMS] = {};
} // namespace systems
