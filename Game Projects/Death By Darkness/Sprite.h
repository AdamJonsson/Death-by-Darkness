#pragma once
#include <string>
#include "SDL.h"
class Sprite
{
public:
	Sprite(SDL_Renderer *renderer, int width, int height, int xPos, int yPos, std::string filePath);

	void render();

	double w, h, x, y;
	double rotation = 0;
	int xPoint = 0, yPoint = 0;

	~Sprite();
private:
	SDL_Texture *image = NULL;
	SDL_Rect rect;
	SDL_Renderer *theRenderer = NULL;
	SDL_Point thePoint;

	void update();



};

