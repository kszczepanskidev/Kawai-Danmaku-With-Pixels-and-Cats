#include "Player.h"

float speedY = 5.f, speedX = 5.f;

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::Z:
			shooting = !shooting;
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
	
	if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && pos_y > 0.f)
		pos_y -= speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && pos_y < 670.f)
		pos_y += speedY;

	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && pos_x > 188.f)
		pos_x -= speedX;

	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && pos_x < 838.f)
		pos_x += speedX;

	if (Keyboard::isKeyPressed(Keyboard::Space) && fireTime < currentTime)
		shoot();

	for (unsigned int i = 0; i < bullets.size(); ++i)
		if (bullets[i]->update())
			bullets.erase(bullets.begin() + i);
}

void Player::draw(RenderWindow* window, vector<Sprite>* sprites) {
	(*sprites)[PLAYER].setPosition(pos_x, pos_y);
	window->draw((*sprites)[PLAYER]);

	for (auto b : bullets)
		b->draw(window, sprites);
}
void Player::shoot() {
	switch (power) {
	case 1:
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90));
		break;
	case 2:
		bullets.emplace_back(new Bullet(pos_x-15, pos_y, 90));
		bullets.emplace_back(new Bullet(pos_x+15, pos_y, 90));
		break;
	case 3:
		bullets.emplace_back(new Bullet(pos_x-10, pos_y, 70));
		bullets.emplace_back(new Bullet(pos_x, pos_y, 90));
		bullets.emplace_back(new Bullet(pos_x+10, pos_y, 110));
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
	currentTime = 0;
}


Player::~Player() {}
