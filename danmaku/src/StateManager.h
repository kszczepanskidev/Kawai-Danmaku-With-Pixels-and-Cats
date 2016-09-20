#pragma once
#include "Includes.h"
#include "TextureManager.h"

#include "State.h"
#include "MenuState.h"
#include "SPGameState.h"
#include "MPGameState.h"
#include "ConnectState.h"
#include "QuitState.h"
#include "SplashState.h"
#include "CreditsState.h"

enum states{ MAINMENU, SPGAME, MPGAME, CONNECT, QUIT, SPLASH, CREDITS };


class StateManager {
private:
	State* activeState;
	vector<State*> states;
public:
	void setActiveState(State*);
	State* getActiveState();

	void newGame();
	void newMPGame(int);

	State* getState(int);

	StateManager(Font, TextureManager*);
	virtual ~StateManager();
};

