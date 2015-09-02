#pragma once
#include "Entity.h"

class Projectile {
public:
	Projectile(Entity* entity);
	~Projectile();

protected:
	double angle;
	double x, y;
	double nx, ny;
	double distance;
	double speed, damage;
};

