#pragma once
#include "Sprite.h"
class Entity
{
public:
	Entity(Sprite* sprite);

	void render();
	void update();

	double w, h, x, y;

	double gravity = 1;
	double speedX = 0, speedY = 0;

private:
	Sprite theSprite;
	~Entity();
};

