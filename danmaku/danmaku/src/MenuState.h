#pragma once
#include "State.h"
#include "MenuOption.h"


class MenuState : public State {
private:
	Font font;
	int currentMenu;
	vector<MenuOption*> menuOptions;
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void initOptions();
	void draw(RenderWindow*, vector<Sprite>*);
	void selectState(StateManager*);

	MenuState(Font);
	virtual ~MenuState();
};

