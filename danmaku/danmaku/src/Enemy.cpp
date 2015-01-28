#include "Enemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

int Enemy::update() {
	if ((pos_x > 863.f || pos_x < 163.f || pos_y > 720.f) && id != 1)
		return 1;
	if (pos_y > 550.f && id == 1)
		return 1;

	if (currentTime > 60) {
		currentTime = 1;
		fireTime -= 60;
	}
	else
		currentTime++;

	move();

	if (/*(rand()%150 < 5 && id != 1) &&*/ fireTime < currentTime)
			shoot();
	if ((rand() % 150 < 7 && id == 1))
			shoot();

	return 0;
}

void Enemy::move() {
	pos_x += (float)cos(angle*(M_PI / 180))*speed_x;
	pos_y += (float)sin(angle*(M_PI / 180))*speed_y;
}

void Enemy::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);

	/*hitbox.setRadius(hitbox_r);
	hitbox.setPosition(pos_x, pos_y);
	hitbox.setFillColor(Color::Black);
	window->draw(hitbox);*/
}

void Enemy::shoot() {
	for (int i = 0; i < power; ++i)
		switch (id) {
		case 0:
			switch (power) {
			case 1:
				bullets->emplace_back(new Bullet(pos_x, pos_y + 5.f, -90.f/*0.f - (float)(rand() % 90 + 45.f)*/, ENEMY, texManager));
				break;
			case 2:
				bullets->emplace_back(new Bullet(pos_x + 10.f, pos_y + 10.f, -70.f, ENEMY, texManager));
				bullets->emplace_back(new Bullet(pos_x - 10.f, pos_y + 10.f, -110.f, ENEMY, texManager));
				break;
			case 3:
				bullets->emplace_back(new Bullet(pos_x + 10.f, pos_y + 10.f, -70.f, ENEMY, texManager));
				bullets->emplace_back(new Bullet(pos_x + 5.f, pos_y + 10.f, -90.f, ENEMY, texManager));
				bullets->emplace_back(new Bullet(pos_x - 5.f, pos_y + 10.f, -90.f, ENEMY, texManager));
				bullets->emplace_back(new Bullet(pos_x - 10.f, pos_y + 10.f, -110.f, ENEMY, texManager));
				break;
			}
			break;
		case 1:
			bullets->emplace_back(new Bullet(pos_x, pos_y + 5.f, -90.f, 2, texManager));
			break;
	}
	fireTime = currentTime + 35;
}

Enemy::Enemy(TextureManager* tM, vector<Bullet*>* b, int i, float x, float y, float a, float s) {
	texManager = tM;

	id = i; //0 - game, 1 - credits
	type = 'e';

	sprite.setTexture(tM->getTexture("enemy1"));
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);

		switch (id) {
	case 0:
		sprite.setColor(Color::Red);
		break;
	case 1:
		sprite.setColor(Color::White);
		break;
	}

	pos_x = x;
	pos_y = y;
	life = 3;

	power = rand() % 3 + 1;

	fireTime = 0;
	currentTime = 0;

	speed_x = 3.f;// s;
	speed_y = 3.f;// s;

	hitbox_r = 15.f;
	hitbox.setOrigin(hitbox_r, hitbox_r);
	hitbox_pos_x = sprite.getOrigin().x;
	hitbox_pos_y = sprite.getOrigin().y;

	if (pos_x < 538.f)
		angle = rand() % 10 + 40.f;//60.f; a;
	else
		angle = rand() % 10 + 150.f;//60.f; a;
	

	bullets = b;

	live = true;
}


Enemy::~Enemy() {}
