#pragma once
#include "State.h"

class ConnectState : public State {
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	ConnectState();
	virtual ~ConnectState();
};

