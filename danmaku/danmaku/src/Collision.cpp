#include "Collision.h"

#include <math.h>

void checkCollision(vector<FlyingObject*>* objects, vector<Bullet*>* bullets) {

	double distance_x, distance_y;
	/* LOOP through all enemies */
	for (unsigned int i = 0; i < objects->size(); ++i) {
		if ((*objects)[i]->getType() == 'p') {
			/* PLAYER with ENEMIES*/
			for (unsigned int j = 0; j < objects->size(); ++j) {
				if ((*objects)[i]->getType() == 'e') {
					distance_x = (*objects)[i]->getPosX() - (*objects)[j]->getPosX();
					distance_y = (*objects)[i]->getPosY() - (*objects)[j]->getPosY();

					if (sqrt(pow(distance_x, 2.0) + pow(distance_y, 2.0)) < ((*objects)[i]->getHitboxR() + (*objects)[j]->getHitboxR())) {
						//(*objects)[i]->setLive(false);
						(*objects)[i]->inreasePower(-1);
						(*objects)[j]->setLive(false);
						//objects->erase((*objects).begin() + j, (*objects).end());
						break;
					}
				}
			}
			/* PLAYER with enemy BULLETS*/
			for (unsigned int j = 0; j < bullets->size(); ++j) {
				if ((*bullets)[j]->getType() == ENEMY) {
					distance_x = (*objects)[i]->getPosX() - (*bullets)[j]->getPosX();
					distance_y = (*objects)[i]->getPosY() - (*bullets)[j]->getPosY();

					if (sqrt(pow(distance_x, 2) + pow(distance_y, 2)) < ((*objects)[i]->getHitboxR() + (*bullets)[j]->getHitboxR())) {
						//(*objects)[i]->setLive(false);
						(*objects)[i]->inreasePower(-1);
						objects->erase(objects->begin() + 1, objects->end());
						break;
					}
				}
			}
		}
		else if ((*objects)[i]->getType() == 'e') {
			/* ENEMIES with player BULLETS*/
			for (unsigned int j = 0; j < bullets->size(); ++j) {
				if ((*bullets)[j]->getType() == PLAYER) {
					distance_x = (*objects)[i]->getPosX() - (*bullets)[j]->getPosX();
					distance_y = (*objects)[i]->getPosY() - (*bullets)[j]->getPosY();

					if ((sqrt(pow(distance_x, 2) + pow(distance_y, 2))) < (((*objects)[i]->getHitboxR() + (*bullets)[j]->getHitboxR()))) {
						(*objects)[i]->setLive(false);
						break;
					}
				}
			}
		}
		else if ((*objects)[i]->getType() == 'b') {
			/* BONUS with PLAYER*/
			for (unsigned int j = 0; j < objects->size(); ++j) {
				if ((*objects)[j]->getType() == 'p') {
					distance_x = (*objects)[j]->getPosX() - (*objects)[i]->getPosX();
					distance_y = (*objects)[j]->getPosY() - (*objects)[i]->getPosY();

					if (sqrt(pow(distance_x, 2.0) + pow(distance_y, 2.0)) < ((*objects)[j]->getHitboxR() + (*objects)[i]->getHitboxR())) {
						(*objects)[j]->inreasePower(1);
						(*objects)[j]->increaseScore(5);
						objects->erase((*objects).begin() + i);
						break;
					}
				}
			}
		}
	}
}