#pragma once
#include "State.h"

class GameState : public State {
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	GameState();
	virtual ~GameState();
};

