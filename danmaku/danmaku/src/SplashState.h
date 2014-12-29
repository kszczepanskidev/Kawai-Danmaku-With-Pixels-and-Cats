#pragma once
#include "State.h"
class SplashState : public State {
public:
	void handleEvent(Event*);
	void update();
	void draw(RenderWindow* window);

	SplashState();
	virtual ~SplashState();
};

