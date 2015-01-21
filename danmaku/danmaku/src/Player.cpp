#include "Player.h"

const float sx = 6.5f;
const float sy = 6.5f;

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyPressed)
		switch (event->key.code) {
		case Keyboard::W:
			speed_y = -sy;//-5.f;
			break;
		case Keyboard::S:
			speed_y = sy;// 5.f;
			break;
		case Keyboard::A:
			speed_x = -sx;//-5.f;
			break;
		case Keyboard::D:
			speed_x = sx;// 5.f;
			break;
		case Keyboard::Space:
			shooting = true;
			break;
	}
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::W:
			if (Keyboard::isKeyPressed(Keyboard::S))
				speed_y = sy;// 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::S:
			if (Keyboard::isKeyPressed(Keyboard::W))
				speed_y = -sy;// -5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::A:
			if (Keyboard::isKeyPressed(Keyboard::D))
				speed_x = sx;// 5.f;
			else
				speed_x = 0.f;
			break;
		case Keyboard::D:
			if (Keyboard::isKeyPressed(Keyboard::A))
				speed_x = -sx;// -5.f;
			else
				speed_x = 0.f;
			break;

		case Keyboard::Equal:
			if (power < max_stat)power++;
			break;
		case Keyboard::Dash:
			if (power > 1)power--;
			break;
		case Keyboard::Space:
			shooting = false;
			break;
	}
}

int Player::update() {	
	if (currentTime > 60) {
		currentTime = 1;
		fireTime -= 60;
	}
	else
		currentTime++;

	move();

	if (/*Keyboard::isKeyPressed(Keyboard::Space)*/shooting && fireTime < currentTime)
		shoot();

	--deathTime;
	if (deathTime == 0)
		invisible = false;

	return 0;
}

void Player::move() {
		pos_y += speed_y;
		pos_x += speed_x;

		if (pos_y < 0.f && id != 3) pos_y = 0.f;
		if (pos_y > 690.f && id != 3) pos_y = 690.f;
		if (pos_x < 218.f && id != 3) pos_x = 218.f;
		if (pos_x > 803.f && id != 3) pos_x = 803.f;
}

void Player::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	if (invisible && id != 3)
		sprite.setColor(Color(0, 0, 0, 100));
	else if (id != 3)
		sprite.setColor(Color::Black);

	window->draw(sprite);

	/*hitbox.setRadius(hitbox_r);
	hitbox.setPosition(pos_x, pos_y);
	hitbox.setFillColor(Color::Red);
	window->draw(hitbox);*/
}

void Player::shoot() {
	if (id == 3) {
		bullets->emplace_back(new Bullet(pos_x - 3.5f, pos_y - 10.f, 90.f, 2, texManager));
		fireTime = currentTime + (rand()%20 + 30);
	}
	else {
		switch (power) {
		case 1:
			bullets->emplace_back(new Bullet(pos_x - 3.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			break;
		case 2:
			bullets->emplace_back(new Bullet(pos_x + 6.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x - 13.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			break;
		case 3:
			bullets->emplace_back(new Bullet(pos_x - 13.5f, pos_y - 10.f, 70.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x - 3.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x + 6.5f, pos_y - 10.f, 110.f, PLAYER, texManager));
			break;
		case 4:
			bullets->emplace_back(new Bullet(pos_x - 10.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x - 28.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x + 21.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x + 3.f, pos_y - 10.f, 90.f, PLAYER, texManager));
			break;
		case 5:
			bullets->emplace_back(new Bullet(pos_x - 13.5f, pos_y - 10.f, 72.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x - 8.5f, pos_y - 10.f, 81.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x - 3.5f, pos_y - 10.f, 90.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x + 1.5f, pos_y - 10.f, 99.f, PLAYER, texManager));
			bullets->emplace_back(new Bullet(pos_x + 6.5f, pos_y - 10.f, 108.f, PLAYER, texManager));
			break;
		}
		fireTime = currentTime + 20;//10;
	}
}

Player::Player(TextureManager* tM, vector<Bullet*>* b, int i, float x, float y) {
	texManager = tM;

	sprite.setTexture(texManager->getTexture("player"));
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setColor(Color::Black);
	
	id = i;
	type = 'p';

	pos_x = x;//535.5f;
	pos_y = y;// 650.f;
	life = 3;

	power = 1;
	special = 0;
	graze = 0;
	score = 0;

	fireTime = 0;
	currentTime = 0;	

	speed_x = 0.f;
	speed_y = 0.f;

	hitbox_r = 7.5f;
	hitbox.setOrigin(hitbox_r, hitbox_r);
	hitbox_pos_x = sprite.getOrigin().x - 3.5f;
	hitbox_pos_y = sprite.getOrigin().y;

	bullets = b;
	
	live = true;
	shooting = false;

	deathTime = 0;
	invisible = false;

	if (id == 3) sprite.setColor(Color::White);
}


Player::~Player() {}
