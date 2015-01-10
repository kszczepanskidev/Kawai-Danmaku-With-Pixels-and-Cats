#pragma once
#include "Includes.h"
#include "Bullet.h"
#include "TextureManager.h"

class FlyingObject {
protected:
	Sprite sprite;
	TextureManager* texManager;

	int id;

	float pos_x, pos_y;
	float speed_x, speed_y;

	CircleShape hitbox;
	float hitbox_r;

	int fireTime, currentTime;

	virtual void shoot();
	virtual void move();
public:
	vector<Bullet*> bullets;

	virtual void handleEvent(Event*);
	virtual int update();
	virtual void draw(RenderWindow*) = 0;

	float getPosX();
	float getPosY();

	void setId(int);
	int getId();

	FlyingObject();
	virtual ~FlyingObject();
};

