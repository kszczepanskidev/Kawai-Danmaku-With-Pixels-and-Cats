#include "Collision.h"

#include <math.h>

//void checkCollision(vector<FlyingObject*>* objects) {
vector<FlyingObject*> checkCollision(vector<FlyingObject*> objects) {
	vector<Bullet*> bullets;

	double distance_x, distance_y;
	/* LOOP through all enemies */
	for (unsigned int i = 1; i < objects.size(); ++i) {
		/* PLAYER with ENEMIES*/
		distance_x = (objects[0]->getPosX() + objects[0]->getHitboxPosX()) - (objects[i]->getPosX() + objects[i]->getHitboxPosX());
		distance_y = (objects[0]->getPosY() + objects[0]->getHitboxPosY()) - (objects[i]->getPosY() + objects[i]->getHitboxPosY());

		if (sqrt(pow(distance_x, 2.0) + pow(distance_y, 2.0)) < (objects[0]->getHitboxR() + objects[i]->getHitboxR())) {
			objects[0]->setLive(false);
			objects.erase(objects.begin() + 1, objects.end());
			return objects;
		}
		/* PLAYER with enemy BULLETS*/
		bullets.clear();
		bullets = objects[i]->bullets;
		for (unsigned int j = 0; j < bullets.size(); ++j) {
			distance_x = (objects[0]->getPosX() + objects[0]->getHitboxPosX()) - (bullets[j]->getPosX() + bullets[j]->getHitboxPosX());
			distance_y = (objects[0]->getPosY() + objects[0]->getHitboxPosY()) - (bullets[j]->getPosY() + bullets[j]->getHitboxPosY());

			if (sqrt(pow(distance_x, 2) + pow(distance_y, 2)) < (objects[0]->getHitboxR() + bullets[j]->getHitboxR())) {
				objects[0]->setLive(false);
				objects.erase(objects.begin() + 1, objects.end());
				return objects;
			}
		}
		/* ENEMIES with player BULLETS*/
		bullets.clear();
		bullets = objects[0]->bullets;
		for (unsigned int j = 0; j < bullets.size(); ++j) {
			distance_x = (objects[i]->getPosX() + objects[i]->getHitboxPosX()) - (bullets[j]->getPosX() + bullets[j]->getHitboxPosX());
			distance_y = (objects[i]->getPosY() + objects[i]->getHitboxPosY()) - (bullets[j]->getPosY() + bullets[j]->getHitboxPosY());

			if ((sqrt(pow(distance_x, 2) + pow(distance_y, 2))) < ((objects[i]->getHitboxR() + bullets[j]->getHitboxR()))) {
				objects.erase(objects.begin() + i);
				break;
			}
		}
	}
	//objects = &temp;
	return objects;
}