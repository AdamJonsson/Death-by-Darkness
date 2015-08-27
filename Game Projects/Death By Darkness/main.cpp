#include <iostream>
#include "Time.h"

bool running = true;
int fps = 0, ups = 0;

Time time;

void update() {

}

void render() {

}

int main() {


	while (running) {

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

}

