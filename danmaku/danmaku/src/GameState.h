#pragma once
#include "State.h"
#include "FlyingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

enum gameTexts{ SCORE, SCORE_V, LIFE, LIFE_V, POWER, POWER_V, SPECIAL, SPECIAL_V, GRAZE, GRAZE_V };

#define CLOUDS_NUM 10

class GameState : public State {
private:;
	vector<GameText*> gameTexts;

	TextureManager* texManager;

	float /*pos_y1, pos_y2, pos_y3,*/ pos_x;
	//int bg1, bg2, bg3;
	float scrollSpeed;

	vector<String> clouds_names;
	float pos_y[CLOUDS_NUM];

	int gameTime;

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

	GameState(Font, TextureManager*);
	virtual ~GameState();
};

