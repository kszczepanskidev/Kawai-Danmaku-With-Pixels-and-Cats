#pragma once
#include "Includes.h"

#include "State.h"
#include "GameState.h"
#include "MenuState.h"
//#include "SplashState.h"
#include "ConnectState.h"


class StateManager {
private:
	State* activeState;
	State* states[3];
public:
	void onEventStateChange(Event*);

	void setActiveState(State*);
	State* getActiveState();

	State* getState(int);

	StateManager(Font);
	virtual ~StateManager();
};

