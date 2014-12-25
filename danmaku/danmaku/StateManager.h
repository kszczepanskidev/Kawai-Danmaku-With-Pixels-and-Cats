#pragma once
#include "Includes.h"

enum states{MAINMENU, GAME, CONNECT, SPLASHIN, SPLASHOUT};

class StateManager {
private:
	State* activeState;

public:
	void setActiveState(State*);
	void onEventStateChange(Event*); 
	State* getActiveState();

	StateManager();
	virtual ~StateManager();
};

