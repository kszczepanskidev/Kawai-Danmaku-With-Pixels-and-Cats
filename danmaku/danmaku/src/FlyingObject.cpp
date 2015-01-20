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
	if (power > max_stat) {
		power = max_stat;
		increaseScore(69);
	}
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
	if (l < life) {
		if (!invisible) {
			deathTime = 90;
			invisible = true;

			if (l == 0)
				live = false;
			else
				life = l;
		}
	}
	else
		life = l;

	if (life > max_stat) {
		life = max_stat;
		score += 123;
	}
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

void FlyingObject::setInvisible(bool i) {
	invisible = i;
}
bool FlyingObject::getInvisible() {
	return invisible;
}

void FlyingObject::setDeathTime(int dT) {
	deathTime = dT;
}
int FlyingObject::getDeathTime() {
	return deathTime;
}


FlyingObject::FlyingObject() {}


FlyingObject::~FlyingObject() {}