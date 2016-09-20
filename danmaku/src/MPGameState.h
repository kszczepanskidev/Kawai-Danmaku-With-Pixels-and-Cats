#pragma once
#include "State.h"
#include "FlyingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Bonus.h"

class MPGameState : public State {
private:;
		vector<GameText*> gameTexts;

		float pos_x;
		float pos_y[3];
		float scrollSpeed;

		vector<FlyingObject*> objects;
		vector<Bullet*> bullets;

		void initTexts();
		void updateTexts();
		void initSprites(TextureManager*);

		void scrollBG();

public:
	void handleEvent(Event*, StateManager*);
	void update(StateManager*);
	void draw(RenderWindow*);

	MPGameState(Font, TextureManager*, int);
	virtual ~MPGameState();
};

