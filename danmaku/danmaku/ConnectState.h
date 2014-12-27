#pragma once
#include "State.h"
class ConnectState : public State {
public:
	void onEvent(Event*);
	void onLoop();
	void onDraw();

	ConnectState();
	virtual ~ConnectState();
};

