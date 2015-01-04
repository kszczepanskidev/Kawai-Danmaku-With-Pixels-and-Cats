#pragma once
#include "State.h"
#include "GameText.h"

enum texts{ COMMAND, ENTERED_IP };

class ConnectState : public State {
private:
	Font font;
	string temp;
	vector<GameText*> connectTexts;

	void initTexts();
	void connect();
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	ConnectState(Font);
	virtual ~ConnectState();
};

