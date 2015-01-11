#pragma once
#include "State.h"

enum menuTexts{MENU_START, MENU_QUIT};

class MenuState : public State {
private:
	int currentMenu;
	void selectState(StateManager*);

	void initTexts();
	void initSprites(TextureManager*);

public:
	void handleEvent(Event*, StateManager*);
	void update(StateManager*);
	void draw(RenderWindow*);

	MenuState(Font, TextureManager*);
	virtual ~MenuState();
};

