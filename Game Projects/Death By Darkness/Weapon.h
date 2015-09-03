#pragma once
#include "Sprite.h"
#include "Mouse.h"

class Weapon
{
public:
	Weapon(Sprite *sprite);

	void update();
	void render();

	double x, y, width, height;
	Sprite weaponSprite;

	~Weapon();

private: 
	Mouse mouse;

	const double PI = 3.14;
};

