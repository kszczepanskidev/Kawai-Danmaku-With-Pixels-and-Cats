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

void MenuState::draw(RenderWindow* window) {
	Text temp;

	window->clear(Color(200, 200, 200, 255));
	float posx = 600.f, posy = 300.f;

	for (unsigned int i = 0; i < menuTexts.size(); ++i) {
		temp = menuTexts[i];
		temp.setPosition(Vector2f(posx, posy));

		if (i == currentMenu)
			temp.setColor(Color::Yellow);

		window->draw(temp);
		posy += 30.f;
	}
}

MenuState::MenuState(Font f) {
	font = f; 

	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(Color::White);
	text.setStyle(Text::Bold);

	text.setString("Start game");
	menuTexts.push_back(text);

	text.setString("Quit");
	menuTexts.push_back(text);

	currentMenu = 0;
}


MenuState::~MenuState() {}
