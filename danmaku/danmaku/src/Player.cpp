#include "Player.h"

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyPressed)
		switch (event->key.code) {
		case Keyboard::W:
			speed_y = -5.f;
			break;
		case Keyboard::S:
			speed_y = 5.f;
			break;
		case Keyboard::A:
			speed_x = -5.f;
			break;
		case Keyboard::D:
			speed_x = 5.f;
			break;
	}
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::W:
			if (Keyboard::isKeyPressed(Keyboard::S))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::S:
			if (Keyboard::isKeyPressed(Keyboard::W))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::A:
			if (Keyboard::isKeyPressed(Keyboard::D))
				speed_x = 5.f;
			else
				speed_x = 0.f;
			break;
		case Keyboard::D:
			if (Keyboard::isKeyPressed(Keyboard::A))
				speed_x = -5.f;
			else
				speed_x = 0.f;
			break;

		case Keyboard::Equal:
			if (power < 3)power++;
			break;
		case Keyboard::Dash:
			if (power > 1)power--;
			break;
	}
}

void Player::update() {	
	if (currentTime > 60) {
		currentTime = 1;
		fireTime -= 60;
	}
	else
		currentTime++;

	move();

	if (Keyboard::isKeyPressed(Keyboard::Space) && fireTime < currentTime)
		shoot();

	for (unsigned int i = 0; i < bullets.size(); ++i)
		if (bullets[i]->update())
			bullets.erase(bullets.begin() + i);
}

void Player::move() {
		pos_y += speed_y*id;
		pos_x += speed_x*id;

		if (pos_y < 0.f) pos_y = 0.f;
		if (pos_y > 670.f) pos_y = 670.f;
		if (pos_x < 188.f) pos_x = 188.f;
		if (pos_x > 833.f) pos_x = 833.f;
}

void Player::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);

	for (auto b : bullets)
		b->draw(window);
}

void Player::shoot() {
	switch (power) {
	case 1:
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90, PLAYER, texManager));
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

	fireTime = currentTime + FLIMIT;
}


float Player::getPosX() {
	return pos_x;
}

float Player::getPosY() {
	return pos_y;
}

void Player::setId(int i) {
	id = i;
}
int Player::getId() {
	return id;
}

Player::Player(TextureManager* tM, int i) {
	id = i;

	//pos_x = 535.5f;
	pos_y = 650.f;
	life = 3;

	power = 1;
	special = 0;

	graze = 0;
	score = 0;

	fireTime = 0;
	currentTime = 0;
	
	texManager = tM;

	speed_x = 0.f;
	speed_y = 0.f;

	sprite.setTexture(texManager->getTexture("player"));
	switch (id) {
	case 1:
		sprite.setColor(Color::Blue);
		pos_x = 505.5f;
		break;
	case 2:
		sprite.setColor(Color::Red);
		pos_x = 565.5f;
		break;
	}
}


Player::~Player() {}
