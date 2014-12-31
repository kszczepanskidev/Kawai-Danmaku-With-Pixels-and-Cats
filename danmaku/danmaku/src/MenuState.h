#pragma once
#include "State.h"
#include "GameText.h"

enum options{MENU_START, MENU_QUIT};

class MenuState : public State {
private:
	Font font;
	int currentMenu;
	vector<GameText*> menuOptions;

	void initOptions();
	void selectState(StateManager*);
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	MenuState(Font);
	virtual ~MenuState();
};

