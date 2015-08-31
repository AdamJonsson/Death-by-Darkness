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

	x += speedX;
	y += speedY;

	//Collition i collitionsrutan
	if (boxCollision) {
		if (x + w > boxW + boxX) {
			x = boxW + boxX - w - 1;
			rightCollision = true;
		}
		else rightCollision = false;
		if (x < boxX) {
			x = boxX + 1;
			leftCollision = true;
		}
		else leftCollision = false;
		if (y + h > boxH + boxY) {
			y = boxH  + boxY - h;
			bottomCollistion = true;
		}
		else bottomCollistion = false;
		if (y < boxY) {
			y = boxY + 1;
			topCollision = true;
		}
		else topCollision = false;
	}

	//Graviation
	if (gravity != 0 && !bottomCollistion) speedY += gravity;
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

void Entity::setOrigin(int originX, int originY) {
	x = originX - w / 2;
	y = originY - h / 2;
}

Entity::~Entity()
{
}
