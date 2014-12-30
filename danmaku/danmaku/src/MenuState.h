#pragma once
#include "State.h"

class MenuState : public State {
private:
	Font font;
	int currentMenu;
	vector<Text> menuTexts;
public:
	void handleEvent(Event*);
	void update();
	void draw(RenderWindow*, TextureManager*);

	MenuState(Font);
	virtual ~MenuState();
};

