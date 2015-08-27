#pragma once
class Time
{
public:
	Time();

	/*
		<-----------------Beskrivning-------------------->
		Denna function retunerar sannt varje x milisekund.
		Channel är vilken kannal den ska vara i och används
		om denna function mer än en gång körs ifrån samma objekt.
		Max channels(1000), Max ms
	*/
	bool runEvery(int ms, int channel);

	//<--------------------Beskrivning-------------------->
	//Denna function returnerar sannt 60 gånger per sekund
	bool runSixtyTimesPerSek(int channel);

	~Time();

private: 
	int lastClock[1000];
	int updates[1000], updatesCap[1000];

};

