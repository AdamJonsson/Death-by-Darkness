#include "Sprite.h"
#include "SDL_image.h"


Sprite::Sprite(SDL_Renderer *renderer, int width, int height, int xPos, int yPos, std::string filePath)
	:x(xPos), y(yPos), width(width), height(height), theRenderer(renderer)
{
	image = IMG_LoadTexture(renderer, filePath.c_str());
}

void Sprite::render() {
	update();
	if (rotation == 0) SDL_RenderCopy(theRenderer, image, NULL, &rect);
	else SDL_RenderCopyEx(theRenderer, image, NULL, &rect, rotation, &thePoint, SDL_FLIP_NONE);
}

void Sprite::update() {
	rect.x = x;
	rect.y = y;
	rect.h = height;
	rect.w = width;
	if (rotation != 0) {
		thePoint.x = xPoint;
		thePoint.y = yPoint;
	}
}

Sprite::~Sprite()
{
}
