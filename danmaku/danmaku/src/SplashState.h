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
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*);

	SplashState(TextureManager*, StateManager*);
	virtual ~SplashState();
};

