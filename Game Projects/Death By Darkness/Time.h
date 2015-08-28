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

	~Time();

private: 
	int lastClock[1000];

};

