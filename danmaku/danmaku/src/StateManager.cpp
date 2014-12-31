#include "StateManager.h"

void StateManager::setActiveState(State* state) {
	activeState = state;
}

State* StateManager::getState(int state) {
	return states[state];
}

State* StateManager::getActiveState() {
	return activeState;
}


StateManager::StateManager(Font font) {
	states.emplace_back(new MenuState(font));
	states.emplace_back(new GameState(font));
	states.emplace_back(new ConnectState(font));
	states.emplace_back(new QuitState());

	setActiveState(states[GAME]);
}


StateManager::~StateManager() {}
