#pragma once
#include "State.h"
class MenuState : public State {
public:
	void handleEvent(Event*);
	void update();
	void draw();

	MenuState();
	virtual ~MenuState();
};

