#include "CreditsState.h"

#include "StateManager.h"

enum textures{ BG };

void CreditsState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased && event->key.code == Keyboard::Return)
			stManager->setActiveState(stManager->getState(MAINMENU));
}

void CreditsState::update(StateManager* stManager) {

}

void CreditsState::initTexts() {
	stateTexts.clear();

	stateTexts.emplace_back(new GameText("Credits", font, 610.f, 100.f));

	for (auto t : stateTexts)
		t->text.setOrigin(t->text.getLocalBounds().width / 2, 0);
}

void CreditsState::initSprites(TextureManager* texManager) {
	Sprite temp;

	sprites.clear();

	temp.setTexture(texManager->getTexture("credits_bg"));
	sprites.emplace_back(temp);
}

void CreditsState::draw(RenderWindow* window) {
	window->draw(sprites[BG]);

	for (auto t: stateTexts)
		window->draw(t->text);
}



CreditsState::CreditsState(Font f, TextureManager* tM) {
	font = f;
	
	texManager = tM;

	initTexts();
	initSprites(texManager);
}


CreditsState::~CreditsState() {}
