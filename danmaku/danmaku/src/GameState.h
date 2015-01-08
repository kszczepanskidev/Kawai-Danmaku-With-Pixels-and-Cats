#pragma once
#include "State.h"
#include "Player.h"
#include "Enemy.h"

enum gameTexts{ SCORE, SCORE_V, LIFE, LIFE_V, POWER, POWER_V, SPECIAL, SPECIAL_V, GRAZE, GRAZE_V };


class GameState : public State {
private:;
	vector<GameText*> gameTexts;
	TextureManager* texManager;

	float pos_y1, pos_y2, pos_y3, pos_x;
	int bg1, bg2, bg3;
	float scrollSpeed;

	int gameTime;

	Player* player;

	vector<Enemy*> enemies;

	void initTexts();
	void updateTexts();
	void initSprites(TextureManager*);

	void scrollBG();

public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*);

	GameState(Font, TextureManager*);
	virtual ~GameState();
};

