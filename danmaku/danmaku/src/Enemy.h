#pragma once
#include "Includes.h"
#include "Bullet.h"

class Enemy {
private:
	Sprite sprite;
	TextureManager* texManager;

	float pos_x, pos_y;
	float speed_x, speed_y;
	float angle;

	CircleShape hitbox;
	float hitbox_r;

	int life, power;

	int fireTime, currentTime;

	void shoot();
	void move();
public:
	vector<Bullet*> bullets;

	int update();
	void draw(RenderWindow*);

	float getPosX();
	float getPosY();


	Enemy(TextureManager*, float, float, float);
	virtual ~Enemy();
};

