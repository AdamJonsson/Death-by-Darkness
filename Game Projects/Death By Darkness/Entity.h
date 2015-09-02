#pragma once
#include "Sprite.h"
class Entity
{
public:
	Entity(Sprite* sprite);

	void render();
	void update();

	double width, height;
	double x, y, gravity; 
	double rotation, rotationX, rotationY;

private:
	Sprite theSprite;
	~Entity();
};

