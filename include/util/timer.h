#pragma once
#ifndef timer_h
#define timer_h

class timer
{
	int initialValue;
	int timerValue;
	bool paused;

public:

	timer();

	int currentTime();

	void zeroTimer();

	void stopTimer();

	void startTimer();
};

#endif
