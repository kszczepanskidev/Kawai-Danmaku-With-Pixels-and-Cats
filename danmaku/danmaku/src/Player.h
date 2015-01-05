#pragma once
#include "Includes.h"
#include "Bullet.h"

class Player {
private:
	float pos_x, pos_y;
	int score, life, graze, power, special;
	bool shooting;

	int fireTime;
	const int FLIMIT = 10;
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

