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


StateManager::StateManager(Font font, TextureManager* texManager) {
	states.emplace_back(new MenuState(font, texManager));
	states.emplace_back(new GameState(font, texManager));
	states.emplace_back(new ConnectState(font, texManager));
	states.emplace_back(new QuitState());

	setActiveState(states[MAINMENU]);
}


StateManager::~StateManager() {}
