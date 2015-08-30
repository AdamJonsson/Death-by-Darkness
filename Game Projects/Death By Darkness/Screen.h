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
		Tar bort allt i skärmen för att 
		sedan kunna rendera på nytt.
	*/
	void clearScreen();

	/*
		##Beskrivning##
		Renderar ut nya saker på skärmen
	*/
	void printScreen();

	~Screen();

private: 
	// Här får du skärmens storlek i pixlar
	void getDesktopResolution(int& horizontal, int& vertical);

};

