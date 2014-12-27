#pragma once
#include "Includes.h"
#include "State.h"
#include "GameState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "ConnectState.h"


class StateManager {
private:
	State* activeState;
	State* states[3];
public:
	void setActiveState(State*);
	void onEventStateChange(Event*); 
	State* getActiveState();
	State* getState(int);

	StateManager();
	virtual ~StateManager();
};

