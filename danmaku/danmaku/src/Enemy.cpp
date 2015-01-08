#include "Enemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

int Enemy::update() {
	if (pos_x > 863.f || pos_x < 163.f || pos_y > 720.f)
		return 1;

	if (currentTime > 60) {
		currentTime = 1;
		fireTime -= 60;
	}
	else
		currentTime++;

	move();

	if ((rand()%100 < 15) /*&& fireTime < currentTime*/)
		shoot();

	for (unsigned int i = 0; i < bullets.size(); ++i)
	if (bullets[i]->update())
		bullets.erase(bullets.begin() + i);

	return 0;
}

void Enemy::move() {
	pos_x += (float)cos(angle*(M_PI / 180))*speed_x;
	pos_y += (float)sin(angle*(M_PI / 180))*speed_y;
	//pos_x += speed_x;
	//pos_y += speed_y;
}

void Enemy::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);

	for (auto b : bullets)
		b->draw(window);
}

void Enemy::shoot() {
	switch (power) {
	case 1:
		bullets.emplace_back(new Bullet(pos_x, pos_y,0.f - (float)(rand()%90 + 45), PLAYER, texManager));
		break;
	case 2:
		bullets.emplace_back(new Bullet(pos_x - 15, pos_y, 90, PLAYER, texManager));
		bullets.emplace_back(new Bullet(pos_x + 15, pos_y, 90, PLAYER, texManager));
		break;
	case 3:
		bullets.emplace_back(new Bullet(pos_x - 10, pos_y, 70, PLAYER, texManager));
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90, PLAYER, texManager));
		bullets.emplace_back(new Bullet(pos_x + 10, pos_y, 110, PLAYER, texManager));
		break;
	}

	fireTime = currentTime + 5;
}


float Enemy::getPosX() {
	return pos_x;
}

float Enemy::getPosY() {
	return pos_y;
}

Enemy::Enemy(TextureManager* tM, float x, float y, float a) {
	texManager = tM;

	pos_x = x;
	pos_y = y;
	life = 3;

	power = 1;

	fireTime = 0;
	currentTime = 0;

	speed_x = 0.5f;
	speed_y = 5.f;

	angle = a;

	sprite.setTexture(tM->getTexture("enemy1"));
	sprite.setColor(Color::Red);
}


Enemy::~Enemy() {}
