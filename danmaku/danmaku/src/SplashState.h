#pragma once
#include "State.h"
class SplashState : public State {
public:
	void handleEvent(Event*);
	void update();
	void draw(RenderWindow* window, TextureManager*);

	SplashState();
	virtual ~SplashState();
};

