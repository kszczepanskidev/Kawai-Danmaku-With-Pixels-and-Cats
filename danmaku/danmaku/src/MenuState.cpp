#include "MenuState.h"
#include "StateManager.h"

void MenuState::handleEvent(Event* event, StateManager* stManager) {
		switch (event->key.code) {
		case Keyboard::Up:
			--currentMenu;
			if (currentMenu < 0) 
				currentMenu = menuOptions.size() - 1;
			break;
		case Keyboard::Down:
			++currentMenu;
			if (currentMenu == menuOptions.size())
				currentMenu = 0;
			break;
		case Keyboard::Return:
			selectState(stManager);
			break;
		}
}

void MenuState::selectState(StateManager* stManager) {
	switch (currentMenu) {
	case 0:
		stManager->setActiveState(stManager->getState(CONNECT));
		break;
	case 1:
		stManager->setActiveState(stManager->getState(QUIT));
		break;
	}
}


void MenuState::update() {

}

void MenuState::initOptions() {
	menuOptions.clear();

	menuOptions.emplace_back(new GameText("Start game ", font, 137.f, 281.f));
	menuOptions.emplace_back(new GameText("   Quit", font, 137.f, 361.f)); 
}

void MenuState::draw(RenderWindow* window, vector<Sprite>* sprites) {
	window->draw((*sprites)[MENU_BG]);

	for (unsigned int i = 0; i < menuOptions.size(); ++i) {
		if (i == currentMenu)
			menuOptions[i]->text.setColor(Color::Yellow);
		else
			menuOptions[i]->text.setColor(Color::White);

		window->draw(menuOptions[i]->text);
	}
}

MenuState::MenuState(Font f) {
	font = f; 

	initOptions();

	currentMenu = 0;
}


MenuState::~MenuState() {}
