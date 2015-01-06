#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

float sY = 10.f, sX = 10.f;

int Bullet::update() {
	if (pos_x > 863.f || pos_x < 163.f || pos_y > 745.f || pos_y < -25.f)
		return 1;

	pos_x -= cos(angle*(M_PI / 180))*sX;
	pos_y -= sin(angle*(M_PI / 180))*sY;

	return 0;
}

void Bullet::draw(RenderWindow* window, vector<Sprite>* sprites) {
	(*sprites)[BULLET].setPosition(pos_x, pos_y);
	window->draw((*sprites)[BULLET]);
}

float Bullet::getPosX() {
	return pos_x;
}

float Bullet::getPosY() {
	return pos_y;
}

Bullet::Bullet(float x, float y, float a) {
	pos_x = x;
	pos_y = y;

	angle = a;

	live = true;
}


Bullet::~Bullet() {}
