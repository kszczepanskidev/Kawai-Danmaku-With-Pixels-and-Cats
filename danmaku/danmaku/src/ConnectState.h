#pragma once
#include "State.h"

class ConnectState : public State {
private:
	Font font;
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	ConnectState(Font);
	virtual ~ConnectState();
};

