#include "Entity.h"
#include <cmath>


Entity::Entity(Sprite* sprite)
	:theSprite(sprite)
{
	x = sprite->x;
	y = sprite->y;
	w = sprite->w;
	h = sprite->h;
	lastX = x;
	lastY = y;
}

void Entity::render() {
	theSprite->render();
}

void Entity::update() {

	lastX = x;
	lastY = y;

	//The grabing code
	mouse.update();
	if (mouse.leftButton && mouse.x > x && mouse.y > y && mouse.x < x + w && mouse.y < y + h && !mouseGrab) {
		grabPointX = mouse.x - x;
		grabPointY = mouse.y - y;
		mouseGrab = true;
	}
	if (!mouse.leftButton) mouseGrab = false;

	if (mouseGrab) {
		speedX = 0;
		speedY = 0;
		x = mouse.x - grabPointX;
		y = mouse.y - grabPointY;
	}
	
	x += speedX;
	y += speedY;

	speedX = x - lastX;
	speedY = y - lastY;

	//Collition i collitionsrutan
	if (boxCollision) {
		if (x + w > boxW) {
			x = boxW - w;
			rightCollision = true;
		}
		else rightCollision = false;
		if (x < boxX) {
			x = boxX;
			leftCollision = true;
		}
		else leftCollision = false;
		if (y + h > boxH) {
			y = boxH - h;
			bottomCollistion = true;
		}
		else bottomCollistion = false;
		if (y < boxY) {
			y = boxY;
			topCollision = true;
		}
		else topCollision = false;
	}

	//Graviation
	if (gravity != 0) speedY += gravity;
	else speedY = 0;
	if (gravity != 0) speedX /= (abs(gravity) / 20) + 1;
	else speedX = 0;
	

	//Collition
	if (topCollision || bottomCollistion) {
		if (bouncy != 0) {
			speedY = (speedY * -1) * (bouncy / 100);
		}
		else speedY = 0;
	}
	if (leftCollision || rightCollision) {
		if (bouncy != 0) {
			speedX = (speedX * -1) * (bouncy / 100);
		}
		else speedX = 0;
	}

	theSprite->x = x;
	theSprite->y = y;
	theSprite->w = w;
	theSprite->h = h;
}

void Entity::setBoxcollision(int x, int y, int w, int h) {
	boxX = x;
	boxY = y;
	boxW = w;
	boxH = h;
	boxCollision = true;
}

Entity::~Entity()
{
}
