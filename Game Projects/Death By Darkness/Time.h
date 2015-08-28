#pragma once
class Time
{
public:
	Time();

	/*
		<-----------------Beskrivning-------------------->
		Denna function retunerar sannt varje x milisekund.
		Channel �r vilken kannal den ska vara i och anv�nds
		om denna function mer �n en g�ng k�rs ifr�n samma objekt.
		Max channels(1000), Max ms
	*/
	bool runEvery(int ms, int channel);

	~Time();

private: 
	int lastClock[1000];

};

