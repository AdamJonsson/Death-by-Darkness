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
Mouse mouse;

Sprite *redBoxSprite = new Sprite(screen->renderer, 100, 100, 200, 200, "Data/Sprites/redBox.png");
Sprite *redBoxSprite2 = new Sprite(screen->renderer, 50, 50, 100, 100, "Data/Sprites/redBox.png");
Sprite *redBoxSprite3 = new Sprite(screen->renderer, 50, 50, 100, 100, "Data/Sprites/redBox.png");
Sprite *redBoxSprite4 = new Sprite(screen->renderer, 50, 50, 100, 100, "Data/Sprites/redBox.png");
Sprite *redBoxSprite5 = new Sprite(screen->renderer, 50, 50, 100, 100, "Data/Sprites/redBox.png");
Sprite *redBoxSprite6 = new Sprite(screen->renderer, 50, 50, 100, 100, "Data/Sprites/redBox.png");
Entity *redBox = new Entity(redBoxSprite);
Entity *redBox2 = new Entity(redBoxSprite2);
Entity *redBox3 = new Entity(redBoxSprite3);
Entity *redBox4 = new Entity(redBoxSprite4);
Entity *redBox5 = new Entity(redBoxSprite5);
Entity *redBox6 = new Entity(redBoxSprite6);



void update() {

	mouse.update();

	redBox->update();
	redBox2->update();
	redBox3->update();
	redBox4->update();
	redBox5->update();
	redBox6->update();


	redBox2->setOrigin(mouse.x, mouse.y);

	redBox3->setBoxcollision(redBox2->x - redBox2->w / 2, redBox2->y - redBox2->h / 2, redBox2->w * 2, redBox2->h * 2);
	redBox4->setBoxcollision(redBox3->x - redBox3->w / 2, redBox3->y - redBox3->h / 2, redBox3->w * 2, redBox3->h * 2);
	redBox5->setBoxcollision(redBox4->x - redBox4->w / 2, redBox4->y - redBox4->h / 2, redBox4->w * 2, redBox4->h * 2);
	redBox6->setBoxcollision(redBox5->x - redBox5->w / 2, redBox5->y - redBox5->h / 2, redBox5->w * 2, redBox5->h * 2);

	if (keyboard->left) redBox->speedX -= 5;
	if (keyboard->right) redBox->speedX += 5;
	if (keyboard->up) redBox->speedY -= 5;
	if (keyboard->down) redBox->speedY += 5;
}

void render() {
	screen->clearScreen();
	redBox->render();
	redBox2->render();
	redBox3->render();
	redBox4->render();
	redBox5->render();
	redBox6->render();
	screen->printScreen();
}

int main(int argc, char* argv[]) {

	redBox->setBoxcollision(0, 0, screen->width, screen->height);
	redBox->gravity = 0.3;
	redBox->bouncy = 80;
	redBox3->gravity = 1;
	redBox4->gravity = 1;
	redBox5->gravity = 1;
	redBox6->gravity = 1;
	redBox3->bouncy = 50;
	redBox4->bouncy = 50;
	redBox5->bouncy = 50;
	redBox6->bouncy = 50;

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

