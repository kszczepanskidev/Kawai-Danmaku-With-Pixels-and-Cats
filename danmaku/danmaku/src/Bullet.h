#pragma once
#include "Includes.h"
#include "TextureManager.h"

class Bullet {
private:
	Sprite sprite;

	float pos_x, pos_y, angle;
	int type;
	bool live;

public:
	int update();
	void draw(RenderWindow*);

	float getPosX();
	float getPosY();

	Bullet(float, float, float, TextureManager*);
	virtual ~Bullet();
};

