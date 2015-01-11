#include "MenuState.h"
#include "StateManager.h"

enum textures{ BG, LOGO };

void MenuState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased) {
		switch (event->key.code) {
		case Keyboard::Up:
			--currentMenu;
			if (currentMenu < 0)
				currentMenu = stateTexts.size() - 1;
			break;
		case Keyboard::Down:
			++currentMenu;
			if (currentMenu == stateTexts.size())
				currentMenu = 0;
			break;
		case Keyboard::Return:
			selectState(stManager);
			break;
		}
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


void MenuState::update(StateManager* stManager) {

}

void MenuState::initTexts() {
	stateTexts.clear();

	stateTexts.emplace_back(new GameText("Start game ", font, 137.f, 281.f));
	stateTexts.emplace_back(new GameText("   Quit", font, 137.f, 361.f));
}

void MenuState::initSprites(TextureManager* texManager) {
	Sprite temp;

	sprites.clear();

	temp.setTexture(texManager->getTexture("menu_bg"));
	sprites.emplace_back(temp);
}

void MenuState::draw(RenderWindow* window) {
	window->draw(sprites[BG]);

	for (unsigned int i = 0; i < stateTexts.size(); ++i) {
		if (i == currentMenu)
			stateTexts[i]->text.setColor(Color::Yellow);
		else
			stateTexts[i]->text.setColor(Color::White);

		window->draw(stateTexts[i]->text);
	}
}

MenuState::MenuState(Font f, TextureManager* texManager) {
	font = f; 

	initTexts();
	initSprites(texManager);

	currentMenu = 0;
}


MenuState::~MenuState() {}
