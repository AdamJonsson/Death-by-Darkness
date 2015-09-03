#include "Weapon.h"
#include <cmath>

Weapon::Weapon(Sprite* sprite)
	:weaponSprite(*sprite)
{
	height = weaponSprite.h;
	width = weaponSprite.w;
	x = 500;
	y = 500;
}

void Weapon::update() {

	mouse.update();

	weaponSprite.x = x;
	weaponSprite.y = y;
	if (mouse.x - x != 0) {
		weaponSprite.rotation = 90 + atan((mouse.y - y - height / 2) / (mouse.x - x - width / 2)) * 180 / PI;
	}
}

void Weapon::render() {
	weaponSprite.render();
}

Weapon::~Weapon()
{
}
