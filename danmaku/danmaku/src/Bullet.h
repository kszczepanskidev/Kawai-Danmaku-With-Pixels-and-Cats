#pragma once
#include "Includes.h"
#include "TextureManager.h"

enum source{ PLAYER, ENEMY, BOSS };

class Bullet {
private:
	Sprite sprite;
	CircleShape hitbox;

	float pos_x, pos_y, angle;
	float sY, sX;
	float hitbox_pos_x, hitbox_pos_y, hitbox_r;
	bool live;

public:
	int update();
	void draw(RenderWindow*);

	float getPosX();
	float getPosY();
	float getHitboxPosX();
	float getHitboxPosY();
	float getHitboxR();

	Bullet(float, float, float, int,TextureManager*);
	virtual ~Bullet();
};

