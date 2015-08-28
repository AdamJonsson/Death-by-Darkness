#include <iostream>
#include "Time.h"
#include "Keyboard.h"
#include <SDL.h>
#undef main

//test
bool running = true;
int fps = 0, ups = 0;

Time time;

void update() {

}

void render() {

}

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("Death By Darkness", 0, 0, 100, 100, SDL_WINDOW_SHOWN);

	while (running) {

		Keyboard* keyboard = new Keyboard();

		keyboard->update();
		if (keyboard->esc) return 0;

		//Skriver ut ups och fps
		if (time.runEvery(999, 1)) {
			std::cout << "UPS: " << ups << std::endl << "FPS: " << fps << std::endl << std::endl;
			fps = 0;
			ups = 0;
		}

		//Updaterar spelet
		if (time.runEvery(16, 0)) {
			ups++;
		}

		//Renderar spelet
		render();
		fps++;

	}

	return 0;

}

