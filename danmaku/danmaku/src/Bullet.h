#pragma once
#include "Includes.h"
#include "TextureManager.h"

enum source{ PLAYER, ENEMY, BOSS };

class Bullet {
private:
	Sprite sprite;

	float pos_x, pos_y, angle;
	float sY, sX;
	bool live;

public:
	int update();
	void draw(RenderWindow*);

	float getPosX();
	float getPosY();

	Bullet(float, float, float, int,TextureManager*);
	virtual ~Bullet();
};

