#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

float sY = 7.5f, sX = 7.5f;

void Bullet::update() {
	pos_x -= cos(angle*(M_PI / 180))*sX;
	pos_y -= sin(angle*(M_PI / 180))*sY;
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

Bullet::Bullet(float x, float y) {
	pos_x = x;
	pos_y = y;

	angle = 90;
}


Bullet::~Bullet() {}
