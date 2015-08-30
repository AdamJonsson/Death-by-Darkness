#pragma once
#include "Sprite.h"
#include "Mouse.h"
class Entity
{
public:
	Entity(Sprite* sprite);

	void render();
	void update();

	double w, h, x, y;
	double speedX = 0, speedY = 0;
	double rotation = 0;
	double gravity = 0;
	double bouncy = 0;
	int xPoint = 0, yPoint = 0;

	bool mouseGrab = false;
	int grabPointX, grabPointY;

	void setBoxcollision(int x, int y, int w, int h);
	bool boxCollision = false;
	int boxX, boxY, boxW, boxH;

	bool topCollision = false, bottomCollistion = false, leftCollision = false, rightCollision = false;

private:
	Sprite* theSprite;
	Mouse mouse;

	int lastX = 0;
	int lastY = 0;
	~Entity();
};

