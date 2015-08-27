#include "Time.h"
#include <time.h>

Time::Time()
{
	for (int x = 0; x < 1000; x++) {
		lastClock[x] = 0;
		updates[x] = 0;
		updatesCap[x] = 0;
	}
}

bool Time::runEvery(int ms, int channel) {
	if (clock() > lastClock[channel] + ms) {
		lastClock[channel] = clock();
		return true;
	}
	else return false;
}

bool Time::runSixtyTimesPerSek(int channel) {

	if (clock() > lastClock[channel] + 16) {

		updates[channel]++;
		lastClock[channel] = clock();

		if (updates[channel] >= 3) {
			updatesCap[channel]++;
			if (updatesCap[channel] >= 2) {
				updates[channel] = 0;
				updatesCap[channel] = 0;
			}
			return false;
		}
		return true;

	}

	return false;

}

Time::~Time()
{
}
