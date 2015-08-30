#pragma once
#include "SDL.h"
class Screen
{
public:
	Screen();

	SDL_Window* window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event *mainEvent = NULL;

	int width = 0, height = 0;

	/*
		##Beskrivning##
		Tar bort allt i sk�rmen f�r att 
		sedan kunna rendera p� nytt.
	*/
	void clearScreen();

	/*
		##Beskrivning##
		Renderar ut nya saker p� sk�rmen
	*/
	void printScreen();

	~Screen();

private: 
	// H�r f�r du sk�rmens storlek i pixlar
	void getDesktopResolution(int& horizontal, int& vertical);

};

