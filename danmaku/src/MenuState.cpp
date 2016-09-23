#include "MenuState.h"
#include "StateManager.h"

enum textures{ BG, LOGO };

void MenuState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased) {
		switch (event->key.code) {
		case Keyboard::W:
		case Keyboard::Up:
			--currentMenu;
			if (currentMenu < 0)
				currentMenu = stateTexts.size() - 1;
			break;
		case Keyboard::S:
		case Keyboard::Down:
			++currentMenu;
			if (currentMenu == stateTexts.size())
				currentMenu = 0;
			break;
		case Keyboard::Escape:
			currentMenu = MENU_QUIT;
		case Keyboard::Return:
		case Keyboard::Space:
			selectState(stManager);
			break;
		}
	}
}

void MenuState::selectState(StateManager* stManager) {
	switch (currentMenu) {
	case MENU_START_SP:
		stManager->newGame();
		stManager->setActiveState(stManager->getState(SPGAME));
		break;
	case MENU_START_MP:
		//stManager->setActiveState(stManager->getState(CONNECT));
		break;
	case MENU_CREDITS:
		stManager->setActiveState(stManager->getState(CREDITS));
		break;
	case MENU_QUIT:
		stManager->setActiveState(stManager->getState(QUIT));
		break;
	}
}


void MenuState::update(StateManager* stManager) {

}

void MenuState::initTexts() {
	stateTexts.clear();

	stateTexts.emplace_back(new GameText("Singleplayer" , font, 332.f, 324.f));	//135
	stateTexts.emplace_back(new GameText("Multiplayer"	, font, 332.f, 404.f));	//148
	stateTexts.emplace_back(new GameText("Credits"		, font, 332.f, 484.f));	//215
	stateTexts.emplace_back(new GameText("Quit"			, font, 332.f, 564.f));	//265

	for (auto t : stateTexts)
		t->text.setOrigin(t->text.getLocalBounds().width/2, 0);
}

void MenuState::initSprites(TextureManager* texManager) {
	Sprite temp;

	sprites.clear();

	temp.setTexture(texManager->getTexture("menu_bg"));
	sprites.emplace_back(temp);

	temp.setTexture(texManager->getTexture("logo"));
	sprites.emplace_back(temp);
	sprites[LOGO].setPosition(627.f, 25.f);
	sprites[LOGO].setTextureRect(IntRect(0, 0, 595, 510));
}

void MenuState::draw(RenderWindow* window) {
	window->draw(sprites[BG]);
	window->draw(sprites[LOGO]);

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
