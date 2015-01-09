#pragma once
#include "Includes.h"
#include "Bullet.h"

enum dir { UP, DOWN, LEFT, RIGHT };

class Player {
private:
	Sprite sprite;
	TextureManager* texManager;

	int id;

	float pos_x, pos_y;
	float speed_x, speed_y;

	CircleShape hitbox;
	float hitbox_r;

	int score, life, graze, power, special;

	int fireTime, currentTime;

	void shoot();
	void move();
public:
	vector<Bullet*> bullets;

	void handleEvent(Event*);
	void update();
	void draw(RenderWindow*);

	float getPosX();
	float getPosY();

	void setId(int);
	int getId();

	Player(TextureManager*, int);
	virtual ~Player();
};

