#pragma once
#include "Includes.h"
#include "GameText.h"
#include "TextureManager.h"

class StateManager;

class State {
protected:
	vector<Sprite> sprites;
	void initSprites(TextureManager*);

	Font font;

	vector<GameText*> stateTexts;
	void initTexts();

public:
	virtual void handleEvent(Event*, StateManager*) = 0;
	virtual void update(StateManager*) = 0;
	virtual void draw(RenderWindow*) = 0;

	State();
	~State();
};

