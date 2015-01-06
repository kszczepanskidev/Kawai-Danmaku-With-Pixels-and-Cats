#pragma once
#include "Includes.h"
#include "Bullet.h"

enum dir{ UP, DOWN, LEFT, RIGHT };

class Player {
private:
	float pos_x, pos_y;
	int score, life, graze, power, special;
	bool shooting;

	int fireTime, currentTime;

	void shoot();
public:
	vector<Bullet*> bullets;

	void handleEvent(Event*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	float getPosX();
	float getPosY();

	Player();
	virtual ~Player();
};

