#pragma once
#include "State.h"
#include "TextureManager.h"

class SplashState : public State {
private:
	bool in;
	Uint8 light;
	Sprite sprite;

	StateManager* stManager;
public:
	virtual void handleEvent(Event*, unique_ptr<StateManager>);
	virtual void update(unique_ptr<StateManager>);
	virtual void draw(unique_ptr<RenderWindow>);

	SplashState(TextureManager*);
	virtual ~SplashState();
};

