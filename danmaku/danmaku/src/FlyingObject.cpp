#include "FlyingObject.h"

void FlyingObject::move() {}
void FlyingObject::shoot() {}

void FlyingObject::handleEvent(Event*) {}
int FlyingObject::update() { return 0; }
void FlyingObject::draw(RenderWindow*) {}

float FlyingObject::getPosX() {
	return pos_x;
}

float FlyingObject::getPosY() {
	return pos_y;
}

float FlyingObject::getHitboxPosX() {
	return hitbox_pos_x;
}

float FlyingObject::getHitboxPosY() {
	return hitbox_pos_y;
}

float FlyingObject::getHitboxR() {
	return hitbox_r;
}

bool FlyingObject::getLive() {
	return live;
}

void FlyingObject::setLive(bool l) {
	live = l;
}

bool FlyingObject::getShooting() {
	return live;
}

void FlyingObject::setShooting(bool s) {
	shooting = s;
}

void FlyingObject::inreasePower(int v) {
	power += v;
	if (power > 3)
		power = 3;
	if (power < 1)
		power = 1;
}
int FlyingObject::getPower() {
	return power;
}

void FlyingObject::increaseScore(int s) {
	score += s;
}
int FlyingObject::getScore() {
	return score;
}

void FlyingObject::setLife(int l) {
	life = l;
}
int FlyingObject::getLife() {
	return life;
}

void FlyingObject::setGraze(int g) {
	graze = g;
}
int FlyingObject::getGraze() {
	return graze;
}

void FlyingObject::setSpecial(int s) {
	special = s;
}
int FlyingObject::getSpecial() {
	return special;
}

void FlyingObject::setId(int i) {
	id = i;
}

int FlyingObject::getId() {
	return id;
}

char FlyingObject::getType() {
	return type;
}


FlyingObject::FlyingObject() {}


FlyingObject::~FlyingObject() {}