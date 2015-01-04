#include "ConnectState.h"
#include "StateManager.h"

void ConnectState::handleEvent(Event* event, StateManager* stManager) {

	if (event->type == Event::TextEntered) {
		if ((event->text.unicode < 59 && event->text.unicode > 47) || event->text.unicode == 46) {
			temp += static_cast<char>(event->text.unicode);
			connectTexts[ENTERED_IP]->text.setString(temp);
		}
	}
	else if (event->type == Event::KeyReleased){
		switch (event->key.code) {
		case Keyboard::Return:
			stManager->setActiveState(stManager->getState(GAME));
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

}

void ConnectState::draw(RenderWindow* window, vector<Sprite>* sprites) {
	window->draw((*sprites)[CONNECT_BG]);

	for (auto t : connectTexts)
		window->draw(t->text);

}

void ConnectState::initTexts() {
	connectTexts.clear();

	connectTexts.emplace_back(new GameText("Enter IP:", font, 498.f, 229.f));
	connectTexts.emplace_back(new GameText("", font, 423.f, 324.f));
}

void ConnectState::connect() {

}

ConnectState::ConnectState(Font f) {
	font = f;

	initTexts();
}


ConnectState::~ConnectState() {}
