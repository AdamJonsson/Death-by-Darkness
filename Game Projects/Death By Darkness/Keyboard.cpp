#include "Keyboard.h"
#include <Windows.h>


Keyboard::Keyboard()
{
}

void Keyboard::update() {

	if (GetAsyncKeyState(VK_ESCAPE)) esc = true;
	else esc = false;

	if (GetAsyncKeyState(VK_SPACE)) space = true;
	else space = false;
}

Keyboard::~Keyboard()
{
}
