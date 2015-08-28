#include "Time.h"
#include <time.h>

Time::Time()
{
	for (int x = 0; x < 1000; x++) {
		lastClock[x] = 0;
	}
}

bool Time::runEvery(int ms, int channel) {
	if (clock() > lastClock[channel] + ms) {
		lastClock[channel] = clock();
		return true;
	}
	else return false;
}


Time::~Time()
{
}
