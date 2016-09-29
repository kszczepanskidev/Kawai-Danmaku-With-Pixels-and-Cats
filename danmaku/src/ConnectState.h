#pragma once
#include "State.h"
#include "TextureManager.h"

enum connectTexts{ COMMAND, ENTERED_IP, PRESS};

class ConnectState : public State {
private:
	string temp;
	vector<GameText*> connectTexts;

	void initTexts();
	void initSprites(unique_ptr<TextureManager>);
public:
	virtual void handleEvent(Event*, unique_ptr<StateManager>);
	virtual void update(unique_ptr<StateManager>);
	virtual void draw(unique_ptr<RenderWindow>);

	ConnectState(Font, TextureManager*);
	virtual ~ConnectState();
};

