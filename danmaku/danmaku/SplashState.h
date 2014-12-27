#pragma once
#include "State.h"
class SplashState : public State {
public:
	void onEvent(Event*);
	void onLoop();
	void onDraw();

	SplashState();
	virtual ~SplashState();
};

