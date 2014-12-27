#pragma once
#include "State.h"
class MenuState : public State {
public:
	void onEvent(Event*);
	void onLoop();
	void onDraw();

	MenuState();
	virtual ~MenuState();
};

