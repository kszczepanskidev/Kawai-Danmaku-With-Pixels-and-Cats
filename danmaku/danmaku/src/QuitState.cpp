#include "QuitState.h"

void QuitState::handleEvent(Event* event, StateManager* stManager) {}

void QuitState::update() {}

void QuitState::draw(RenderWindow* window, vector<Sprite>* sprites) {
	sleep(seconds(0.15f));
	window->close();
}

QuitState::QuitState() {}


QuitState::~QuitState() {}
