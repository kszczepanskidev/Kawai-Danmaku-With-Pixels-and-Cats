#include "QuitState.h"

void QuitState::handleEvent(Event* event, StateManager* stManager) {}

void QuitState::update(StateManager*) {}

void QuitState::draw(RenderWindow* window) {
	sleep(seconds(0.15f));
	window->close();
}

QuitState::QuitState() {}


QuitState::~QuitState() {}
