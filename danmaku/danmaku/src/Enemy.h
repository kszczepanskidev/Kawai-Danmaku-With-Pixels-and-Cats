#pragma once
#include "Includes.h"
#include "FlyingObject.h"
#include "Bullet.h"

class Enemy : public FlyingObject{
private:
	int life, power;
	float angle;

	void shoot();
	void move();

public:
	int update();
	void draw(RenderWindow*);


	Enemy(TextureManager*, float, float, float);
	virtual ~Enemy();
};

