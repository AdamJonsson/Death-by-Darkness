#pragma once
#include <string>
#include "SDL.h"
#include "Screen.h"
class Sprite
{
public:
	Sprite(Screen *screen, double width, double height, double xPos, double yPos, std::string filePath);

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

	int screenH, screenW;

	void update();

};

