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

bool running = true;
int fps = 0, ups = 0;
double speedX = 10, speedY = 5;

Time time;
Screen *screen = new Screen;
Keyboard* keyboard = new Keyboard;
Sprite *redBoxSprite = new Sprite(screen->renderer, 100, 100, 200, 200, "Data/Sprites/redBox.png");
Entity *redBox = new Entity(redBoxSprite);


void update() {
	redBox->update();
}

void render() {
	screen->clearScreen();
	redBox->render();
	screen->printScreen();
}

int main(int argc, char* argv[]) {

	redBox->setBoxcollision(0, 0, screen->width, screen->height);
	redBox->gravity = 1;
	redBox->bouncy = 50;

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

