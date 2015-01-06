#pragma once
#include "Includes.h"

class Bullet {
private:
	float pos_x, pos_y, angle;
	int type;
	bool live;
public:
	int update();
	void draw(RenderWindow*, vector<Sprite>*);

	float getPosX();
	float getPosY();

	Bullet(float, float,float);
	virtual ~Bullet();
};

