#pragma once
#include "State.h"
#include "TextureManager.h"

class CreditsState : public State {
private:
	TextureManager* texManager;

	void initTexts();
	void initSprites(TextureManager*);

public:
	void handleEvent(Event*, StateManager*);
	void update(StateManager*);
	void draw(RenderWindow*);

	CreditsState(Font, TextureManager*);
	virtual ~CreditsState();
};

