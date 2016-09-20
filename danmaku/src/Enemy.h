#pragma once
#include "Includes.h"
#include "FlyingObject.h"
#include "Bullet.h"

class Enemy : public FlyingObject{
private:
	float angle;

	void shoot();
	void move();

public:
	int update();
	void draw(RenderWindow*);


	Enemy(TextureManager*, vector<Bullet*>*, int, float, float, float, float);
	virtual ~Enemy();
};

