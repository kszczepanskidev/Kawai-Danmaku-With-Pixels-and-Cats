#pragma once
#include "Includes.h"
#include "FlyingObject.h"
#include "Bullet.h"

enum dir { UP, DOWN, LEFT, RIGHT };

class Player : public FlyingObject {
private:
	int score, life, graze, power, special;

	void shoot();
	void move();

public:
	void handleEvent(Event*);
	int update();
	void draw(RenderWindow*);

	Player(TextureManager*,vector<Bullet*>*, int, float, float);
	virtual ~Player();
};

