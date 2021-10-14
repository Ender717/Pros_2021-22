#include "headers/utilities/timer.h"
#include "pros/rtos.hpp"

timer::timer()
{
	this->timerValue = 0;
	this->paused = false;
	this->initialValue = pros::c::millis();
}

int timer::currentTime()
{
	if (!(this->paused))
		return (pros::c::millis() - this->initialValue);
	else
		return (this->timerValue);
}

void timer::zeroTimer()
{
	this->timerValue = 0;
	this->initialValue = pros::c::millis();
}

void timer::stopTimer()
{
	if (!this->paused)
		this->timerValue = (pros::c::millis() - this->initialValue);

	this->paused = true;
}

void timer::startTimer()
{
	if (this->paused)
		this->initialValue = pros::c::millis() - this->timerValue;

	this->paused = false;
}
