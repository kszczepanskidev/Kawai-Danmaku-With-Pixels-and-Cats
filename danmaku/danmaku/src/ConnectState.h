#pragma once
#include "State.h"
class ConnectState : public State {
public:
	void handleEvent(Event*);
	void update();
	void draw();

	ConnectState();
	virtual ~ConnectState();
};
