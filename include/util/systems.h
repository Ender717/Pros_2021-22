#pragma once
#ifndef systems_h
#define systems_h

#include "include/util/timer.h"
#include "include/misc/config.h"
#include <vector>

namespace systems
{
class system
{

public:
  bool systemDone = true;
  bool systemCompleted;
  timer systemTimer = timer();
  int systemMaxTime = 0;
  int systemReadPos = 0;

  std::vector<int> systemCommands;

  virtual int addSystemCommands(int i, std::vector<int> &commands);
  virtual void executeSystemFunction();
  virtual bool updateSystem();
  void resetSystemCommads();
};
extern system *systemsArray[config::NUMBER_OF_SYSTEMS];
} // namespace systems

#endif
