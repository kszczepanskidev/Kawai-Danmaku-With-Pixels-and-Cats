#include "Bullet.h"

#define _USE_MATH_DEFINES
#include <math.h>

int Bullet::update() {
	if (pos_x > 883.f || pos_x < 183.f || pos_y > 725.f || pos_y < -5.f)
		return 1;

	pos_x -= (float)cos(angle*(M_PI / 180))*sX;
	pos_y -= (float)sin(angle*(M_PI / 180))*sY;

	return 0;
}

void Bullet::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);

	hitbox.setRadius(hitbox_r); 
	hitbox.setPosition(pos_x, pos_y);
	hitbox.setFillColor(Color::Blue);
	window->draw(hitbox);
}

float Bullet::getPosX() {
	return pos_x;
}

float Bullet::getPosY() {
	return pos_y;
}

float Bullet::getHitboxPosX() {
	return hitbox_pos_x;// +hitbox_r;
}

float Bullet::getHitboxPosY() {
	return hitbox_pos_y;// +hitbox_r;
}

float Bullet::getHitboxR() {
	return hitbox_r;
}

Bullet::Bullet(float x, float y, float a, int type, TextureManager* texManager) {
	sprite.setTexture(texManager->getTexture("bullet"));
	sprite.setOrigin(sprite.getLocalBounds().width/2.f, sprite.getLocalBounds().height/2.f);

	sX = 10.f;
	sY = 10.f;

	pos_x = x;
	pos_y = y;

	hitbox_r = 2.f;
	hitbox_pos_x = (sprite.getLocalBounds().width / 2.f) - hitbox_r;
	hitbox_pos_y = (sprite.getLocalBounds().height / 2.f) - hitbox_r;
	hitbox.setOrigin(hitbox_r, hitbox_r);

	angle = a;

	live = true;


	sprite.rotate(a - 90.f);

	switch (type) {
	case PLAYER:
		sprite.setColor(Color::Magenta);
		break;
	case ENEMY:
		sprite.setColor(Color(139,69,19,255));
		break;
	case BOSS:
		break;
	}
}


Bullet::~Bullet() {}
