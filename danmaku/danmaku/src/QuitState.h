#pragma once
#include "State.h"

class QuitState : public State {
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*);

	QuitState();
	virtual ~QuitState();
};

