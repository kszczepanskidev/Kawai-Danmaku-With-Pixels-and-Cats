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


StateManager::StateManager() {
	states[MAINMENU] = new MenuState();
	states[GAME] = new GameState();
	states[CONNECT] = new ConnectState();
	states[SPLASH] = new SplashState();

	setActiveState(states[MAINMENU]);
}


StateManager::~StateManager() {}
