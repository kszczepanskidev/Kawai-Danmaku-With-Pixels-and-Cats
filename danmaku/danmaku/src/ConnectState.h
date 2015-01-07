#pragma once
#include "State.h"
#include "TextureManager.h"

enum connectTexts{ COMMAND, ENTERED_IP, PRESS};

class ConnectState : public State {
private:
	string temp;
	vector<GameText*> connectTexts;

	void initTexts();
	void initSprites(TextureManager*);
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*);

	ConnectState(Font, TextureManager*);
	virtual ~ConnectState();
};

