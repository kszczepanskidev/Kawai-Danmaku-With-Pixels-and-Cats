#pragma once
#include "State.h"

class GameState : public State {
public:
	void handleEvent(Event*);
	void update();
	void draw();

	GameState();
	virtual ~GameState();
};

