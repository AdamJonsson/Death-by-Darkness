#include "Screen.h"
#include <windows.h>
using namespace std;

Screen::Screen()
{
	getDesktopResolution(width, height);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Death By Darkness", 0, 0, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	mainEvent = new SDL_Event();
}


void Screen::getDesktopResolution(int& horizontal, int& vertical){
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

void Screen::clearScreen() {
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void Screen::printScreen() {
	SDL_RenderPresent(renderer);
}

Screen::~Screen()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}
