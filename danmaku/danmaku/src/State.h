#pragma once
#include "Includes.h"
#include "TextureManager.h"

class State {
public:
	virtual void handleEvent(Event*) = 0;
	virtual void update() = 0;
	virtual void draw(RenderWindow*, TextureManager*) = 0;

	State();
	~State();
};

