#include "MenuState.h"

Text text;

void MenuState::handleEvent(Event* event) {
		switch (event->key.code) {
		case Keyboard::Up:
			--currentMenu;
			if (currentMenu < 0) 
				currentMenu = menuTexts.size() - 1;
			break;
		case Keyboard::Down:
			++currentMenu;
			if (currentMenu == menuTexts.size())
				currentMenu = 0;
			break;
		}
}

void MenuState::update() {

}

void MenuState::draw(RenderWindow* window, TextureManager* texManager) {
	Text temp;
	Sprite bg;

	bg.setTexture(texManager->getTexture("menu_bg"));
	window->draw(bg);

	float posx = 137.f, posy = 281.f;

	for (unsigned int i = 0; i < menuTexts.size(); ++i) {
		temp = menuTexts[i];
		temp.setPosition(Vector2f(posx, posy));

		if (i == currentMenu)
			temp.setColor(Color::Yellow);

		window->draw(temp);
		posy += 80.f;
	}
}

MenuState::MenuState(Font f) {
	font = f; 

	text.setFont(font);
	text.setCharacterSize(32);
	text.setColor(Color::White);
	text.setStyle(Text::Bold);

	text.setString("Start game");
	menuTexts.push_back(text);

	text.setString("   Quit");
	menuTexts.push_back(text);

	currentMenu = 0;
}


MenuState::~MenuState() {}
