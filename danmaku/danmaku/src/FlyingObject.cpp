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
	return hitbox_pos_x + hitbox_r;
}

float FlyingObject::getHitboxPosY() {
	return hitbox_pos_y + hitbox_r;
}

float FlyingObject::getHitboxR() {
	return hitbox_r;
}

void FlyingObject::setLive(bool l) {
	live = l;
}


void FlyingObject::setId(int i) {
	id = i;
}

int FlyingObject::getId() {
	return id;
}


FlyingObject::FlyingObject() {}


FlyingObject::~FlyingObject() {}