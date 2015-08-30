#pragma once
#include "Entity.h"
class Chain
{
public:
	Chain(Entity *entityHead, Entity *entityBody, int headConnectX, int headConnectY, int bodyConnectX, int bodyConnectY, int play);

	void update();

	~Chain();

private: 
	int lastX, lastY;
	int bodyX, bodyY;
	int headX, headY;
	int freeMove;

	Entity *body;
	Entity *head;
};

