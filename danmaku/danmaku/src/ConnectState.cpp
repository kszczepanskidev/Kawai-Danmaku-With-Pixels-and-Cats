#include "ConnectState.h"
#include "StateManager.h"

void ConnectState::handleEvent(Event* event, StateManager* stManager) {

	if (event->type == Event::TextEntered) {
		if (((event->text.unicode < 59 && event->text.unicode > 47) || event->text.unicode == 46) && temp.size() < 21) {
			temp += static_cast<char>(event->text.unicode);
			connectTexts[ENTERED_IP]->text.setString(temp);
		}
	}
	else if (event->type == Event::KeyReleased){
		switch (event->key.code) {
		case Keyboard::Return:
			stManager->setActiveState(stManager->getState(GAME));
			break;
		case Keyboard::Escape:
			stManager->setActiveState(stManager->getState(MAINMENU));
			break;

		case Keyboard::BackSpace:
			if (temp.size() > 0) {
				temp.pop_back();
				connectTexts[ENTERED_IP]->text.setString(temp);
			}
			break;
		}
	}
}

void ConnectState::update() {
	connectTexts[ENTERED_IP]->text.setOrigin(connectTexts[ENTERED_IP]->text.getLocalBounds().width / 2, 0);
}

void ConnectState::draw(RenderWindow* window, vector<Sprite>* sprites) {
	window->draw((*sprites)[CONNECT_BG]);


	for (auto t : connectTexts)
		window->draw(t->text);

}

void ConnectState::initTexts() {
	connectTexts.clear();

	connectTexts.emplace_back(new GameText("Enter IP", font, 498.f, 206.f));
	connectTexts.emplace_back(new GameText("192.168.0.1:65560", font, 653.f, 303.f));
	connectTexts.emplace_back(new GameText("and press ENTER.", font, 393.f, 392.f));

	connectTexts[ENTERED_IP]->text.setCharacterSize(28);
}

void ConnectState::connect() {

}

ConnectState::ConnectState(Font f) {
	font = f;

	initTexts();
}


ConnectState::~ConnectState() {}
