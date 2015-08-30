#include "Chain.h"


Chain::Chain(Entity *entityHead, Entity *entityBody, int headConnectX, int headConnectY, int bodyConnectX, int bodyConnectY, int play)
	:body(entityBody), head(entityHead), bodyX(bodyConnectX), bodyY(bodyConnectY), headX(headConnectX), headY(headConnectY), freeMove(play)
{
}

void Chain::update() {
	lastX = body->x;
	lastY = body->y;
	if (body->x + bodyX < head->x + headX - freeMove / 2 && body->x + bodyX > head->x + headX + freeMove / 2) {
		if (body->y + bodyY < head->y + headY - freeMove / 2 && body->y + bodyY > head->y + headY + freeMove / 2) {
			
		}
	}
	body->x = head->x;
}

Chain::~Chain()
{
}
