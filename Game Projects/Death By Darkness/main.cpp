#include <iostream>
#include "Time.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Entity.h"
#include "Screen.h"
#include "Sprite.h"
#include <stdlib.h>
#include <SDL.h>
#undef main
using namespace std;

bool running = true;
int fps = 0, ups = 0;
double speedX = 10, speedY = 5;

Time time;
Screen *screen = new Screen;
Keyboard* keyboard = new Keyboard;
Sprite* redBallS = new Sprite(screen->renderer, 100, 100, screen->width / 2, screen->height / 2, "Data/Sprites/redBall.png");
Entity* redBallE = new Entity(redBallS);


void update() {
	redBallE->update();
}

void render() {
	screen->clearScreen();
	redBallE->render();
	screen->printScreen();
}

int main(int argc, char* argv[]) {


	while (running) {

		keyboard->update();
		if (keyboard->esc) return 0;

		//Skriver ut ups och fps
		if (time.runEvery(999, 1)) {
			std::cout << "UPS: " << ups << std::endl << "FPS: " << fps << std::endl << std::endl;
			std::cout << std::endl << "Screen: " << screen->width  << "px, " << screen->height << "px" << std::endl;
			fps = 0;
			ups = 0;
		}

		//Updaterar spelet
		update();
		ups++;

		//Renderar spelet
		render();
		fps++;

	}

	return 0;

}

