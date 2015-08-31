#pragma once
#include "Sprite.h"
class Entity
{
public:
	Entity(Sprite* sprite);

	void render();
	void update();

	double w, h, x, y;

private:
	Sprite theSprite;
	~Entity();
};

