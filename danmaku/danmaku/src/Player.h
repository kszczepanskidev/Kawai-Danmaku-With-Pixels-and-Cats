#pragma once
#include "Includes.h"

class Player {
private:
	int score;
	int life;
	int graze;
	int power;
	int special;
public:
	float pos_x, pos_y;
	void handleEvent(Event*);
	void update();
	void draw(RenderWindow*, Sprite);

	float getPosX();
	float getPosY();

	Player();
	virtual ~Player();
};

