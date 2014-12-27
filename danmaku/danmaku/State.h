#pragma once
#include "Includes.h"

class State {
public:
	virtual void onEvent(Event*) = 0;
	virtual void onLoop() = 0;
	virtual void onDraw() = 0;

	State();
	~State();
};

