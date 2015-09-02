#include "Entity.h"


Entity::Entity(Sprite* sprite)
	:theSprite(*sprite)
{
	x = sprite->x;
	y = sprite->y;
	width = sprite->width;
	height = sprite->height;
}

void Entity::render() {
	theSprite.render();
}

void Entity::update() {
	theSprite.x = x;
	theSprite.y = y;
	theSprite.width = width;
	theSprite.height = height;
}

Entity::~Entity()
{
}
