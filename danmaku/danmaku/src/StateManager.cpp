#include "StateManager.h"

void StateManager::setActiveState(State* state) {
	activeState = state;
}

void StateManager::onEventStateChange(Event* event) {}

State* StateManager::getState(int state) {
	return states[state];
}

State* StateManager::getActiveState() {
	return activeState;
}


StateManager::StateManager(Font font) {
	states[MAINMENU] = new MenuState(font);
	states[GAME] = new GameState();
	states[CONNECT] = new ConnectState();
	//states[SPLASH] = new SplashState();

	setActiveState(states[MAINMENU]);
}


StateManager::~StateManager() {}
