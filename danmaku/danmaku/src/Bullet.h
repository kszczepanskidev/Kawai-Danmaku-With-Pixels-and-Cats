#pragma once
#include "Includes.h"

class Bullet {
private:
	float pos_x, pos_y, angle;
	int type;
public:
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	float getPosX();
	float getPosY();

	Bullet(float, float);
	virtual ~Bullet();
};

