#include "Player.h"

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyPressed)
		switch (event->key.code) {
		case Keyboard::W:
		case Keyboard::Up:
			speed_y = -5.f;
			break;
		case Keyboard::S:
		case Keyboard::Down:
			speed_y = 5.f;
			break;
		case Keyboard::A:
		case Keyboard::Left:
			speed_x = -5.f;
			break;
		case Keyboard::D:
		case Keyboard::Right:
			speed_x = 5.f;
			break;
	}
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::W:
		case Keyboard::Up:
			if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::S:
		case Keyboard::Down:
			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::A:
		case Keyboard::Left:
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
				speed_x = 5.f;
			else
				speed_x = 0.f;
			break;
		case Keyboard::D:
		case Keyboard::Right:
			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
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
	pos_y += speed_y;
	pos_x += speed_x;
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
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90, texManager));
		break;
	case 2:
		bullets.emplace_back(new Bullet(pos_x - 15, pos_y, 90, texManager));
		bullets.emplace_back(new Bullet(pos_x + 15, pos_y, 90, texManager));
		break;
	case 3:
		bullets.emplace_back(new Bullet(pos_x - 10, pos_y, 70, texManager));
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90, texManager));
		bullets.emplace_back(new Bullet(pos_x + 10, pos_y, 110, texManager));
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

Player::Player(TextureManager* tM) {
	pos_x = 535.5f;
	pos_y = 650.f;
	life = 3;

	power = 1;
	special = 0;

	graze = 0;
	score = 0;

	fireTime = 0;
	currentTime = 0;
	
	texManager = tM;

	sprite.setTexture(texManager->getTexture("player"));
}


Player::~Player() {}
