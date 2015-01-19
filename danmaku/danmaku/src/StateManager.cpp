#include "StateManager.h"

Font font;
TextureManager* texManager;

void StateManager::setActiveState(State* state) {
	activeState = state;
}

State* StateManager::getState(int state) {
	return states[state];
}

State* StateManager::getActiveState() {
	return activeState;
}

void StateManager::newGame() {
	states[SPGAME] = new SPGameState(font, texManager);
}

void StateManager::newMPGame(int players_num) {
	states[MPGAME] = new MPGameState(font, texManager, players_num);
}


StateManager::StateManager(Font f, TextureManager* tM) {
	font = f;
	texManager = tM;

	states.emplace_back(new MenuState(font, texManager));
	states.emplace_back(new SPGameState(font, texManager));
	states.emplace_back(new MPGameState(font, texManager,0));
	states.emplace_back(new ConnectState(font, texManager));
	states.emplace_back(new QuitState());
	states.emplace_back(new SplashState(texManager));
	states.emplace_back(new CreditsState(font, texManager));

	setActiveState(states[MAINMENU]);
}


StateManager::~StateManager() {}
