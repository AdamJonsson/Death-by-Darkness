#include "Keyboard.h"
#include <Windows.h>


Keyboard::Keyboard()
{
}

void Keyboard::update() {

	if (GetAsyncKeyState(VK_ESCAPE)) esc = true;
	else esc = false;

	if (GetAsyncKeyState(VK_UP)) up = true;
	else up = false;

	if (GetAsyncKeyState(VK_DOWN)) down = true;
	else down = false;

	if (GetAsyncKeyState(VK_RIGHT)) right = true;
	else right = false;

	if (GetAsyncKeyState(VK_LEFT)) left = true;
	else left = false;

}

Keyboard::~Keyboard()
{
}
