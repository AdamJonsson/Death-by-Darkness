#include "Mouse.h"
#include <Windows.h>
#include <SDL.h>


Mouse::Mouse()
{
}

void Mouse::update() {
	SDL_GetMouseState(&x, &y);
	if (GetAsyncKeyState(VK_LBUTTON)) leftButton = true;
	else leftButton = false;
	if (GetAsyncKeyState(VK_RBUTTON)) rightButton = true;
	else rightButton = false;
}

Mouse::~Mouse()
{
}
