#include <iostream>
#include <time.h>
#include <chrono>

bool running;
int up = 0;

int main() {
	auto lastTime = std::chrono::high_resolution_clock::now();
	long long timer = clock();
	const double ns = 1000000000.0 / 60.0;
	double delta = 0.0;
	int frames = 0;
	int updates = 0;
	while (running) {
		long long now = clock();
		delta += (now - lastTime) / ns;
		lastTime = now;
		while (delta >= 1) {
			update();
			updates++;
			delta--;
		}
		render();
		frames++;

		if (clock() - timer > 1000) {
			timer += 1000;
			updates = 0;
			frames = 0;
		}
	}
}

void update() {

}

void render() {
	std::cout << "Update number: " << up << std::endl;
	up++;
}