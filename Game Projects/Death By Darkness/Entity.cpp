#include "Entity.h"


Entity::Entity(Sprite* sprite)
	:theSprite(*sprite)
{
	x = sprite->x;
	y = sprite->y;
	w = sprite->w;
	h = sprite->h;
}

void Entity::render() {
	theSprite.render();
}

void Entity::update() {

	speedY += gravity / 10;
	speedX /= (gravity / 5) + 1;

	x += speedX;
	y += speedY;

	theSprite.x = x;
	theSprite.y = y;
	theSprite.w = w;
	theSprite.h = h;
}

Entity::~Entity()
{
}
