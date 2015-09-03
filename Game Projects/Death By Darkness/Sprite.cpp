#include "Sprite.h"
#include "SDL_image.h"
#include "Screen.h"


Sprite::Sprite(Screen* screen, double width, double height, double xPos, double yPos, std::string filePath)
	:theRenderer(screen->renderer), screenH(screen->height), screenW(screen->width)
{
	image = IMG_LoadTexture(screen->renderer, filePath.c_str());
	x = xPos;
	y = yPos;
	h = height;
	w = width;
	xPoint = width / 2;
	yPoint = height / 2;
}

void Sprite::render() {
	update();
	if (rotation == 0) SDL_RenderCopy(theRenderer, image, NULL, &rect);
	else SDL_RenderCopyEx(theRenderer, image, NULL, &rect, rotation, &thePoint, SDL_FLIP_NONE);
}


void Sprite::update() {

	rect.x = x;
	rect.y = y;
	rect.h = h;	
	rect.w = w;
	
	if (rotation != 0) {
		thePoint.x = xPoint;
		thePoint.y = yPoint;
	}
}

Sprite::~Sprite()
{
}
