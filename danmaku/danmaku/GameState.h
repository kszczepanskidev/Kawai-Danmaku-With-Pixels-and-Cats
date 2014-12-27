#pragma once
#include "State.h"

class GameState : public State {
public:
	void onEvent(Event*);
	void onLoop();
	void onDraw();
	GameState();
	virtual ~GameState();
};

