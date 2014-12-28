#pragma once
#include "Includes.h"

class State {
public:
	virtual void handleEvent(Event*) = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	State();
	~State();
};

