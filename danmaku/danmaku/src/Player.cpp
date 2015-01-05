#include "Player.h"

float speedY = 5.f, speedX = 5.f;

void Player::handleEvent(Event* event) {
	/*switch (event->key.code) {
	case Keyboard::W:
		break;
	case Keyboard::S:
		break;
	case Keyboard::A:
		break;
	case Keyboard::D:
		break;
	}*/
}

void Player::update() {
	if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)))
		pos_y -= speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
		pos_y += speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)))
		pos_x -= speedX;

	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)))
		pos_x += speedX;
}

void Player::draw(RenderWindow* window, Sprite sprite) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);
}

float Player::getPosX() {
	return pos_x;
}

float Player::getPosY() {
	return pos_y;
}

Player::Player() {
	pos_x = 535.5f;
	pos_y = 650.f;
	life = 3;

	power = 1;
	special = 0;

	graze = 0;
	score = 0;
}


Player::~Player() {}
