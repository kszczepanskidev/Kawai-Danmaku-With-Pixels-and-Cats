#include "Player.h"

float speedY = 5.f, speedX = 5.f;

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::Z:
			shooting = !shooting;
			break;
		}
}

void Player::update() {
	
	if (fireTime == FLIMIT + 1)
		fireTime = 0;
	else
		++fireTime;

	if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)))
		pos_y -= speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
		pos_y += speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)))
		pos_x -= speedX;

	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)))
		pos_x += speedX;

	if ((Keyboard::isKeyPressed(Keyboard::Space) || shooting) && fireTime == FLIMIT)
		bullets.emplace_back(new Bullet(pos_x, pos_y));

	for (auto b : bullets)
		b->update();
}

void Player::draw(RenderWindow* window, vector<Sprite>* sprites) {
	(*sprites)[PLAYER].setPosition(pos_x, pos_y);
	window->draw((*sprites)[PLAYER]);

	for (auto b : bullets)
		b->draw(window, sprites);
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

	shooting = false;

	fireTime = 0;
}


Player::~Player() {}
