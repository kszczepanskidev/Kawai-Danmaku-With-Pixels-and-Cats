#pragma once
#include "Includes.h"
#include "TextureManager.h"

class StateManager;

class State {
public:
	virtual void handleEvent(Event*, StateManager*) = 0;
	virtual void update() = 0;
	virtual void draw(RenderWindow*, vector<Sprite>*) = 0;

	State();
	~State();
};

