#include "CreditsState.h"

#include "StateManager.h"

enum textures{ BG, LOGO };

void CreditsState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased && event->key.code == Keyboard::Return)
			stManager->setActiveState(stManager->getState(MAINMENU));
}

void CreditsState::update(StateManager* stManager) {
	for (auto o : objects)
		o->update();

	for (unsigned int i = 0; i < bullets.size(); ++i)
	if (bullets[i]->update())
		bullets.erase(bullets.begin() + i);

}

void CreditsState::initTexts() {
	stateTexts.clear();

	stateTexts.emplace_back(new GameText("Credits", font, 610.f, 60.f));

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
	window->clear(Color::Black);

	for (auto t: stateTexts)
		window->draw(t->text);

	for (auto o : objects)
		o->draw(window);

	for (auto b : bullets)
		b->draw(window);

	window->draw(sprites[BG]);
}



CreditsState::CreditsState(Font f, TextureManager* tM) {
	font = f;
	
	texManager = tM;

	initTexts();
	initSprites(texManager);

	objects.emplace_back(new Player(texManager, &bullets, 3, 100.f, 470.f));
	objects.emplace_back(new Enemy(texManager, &bullets, 1, 1180.f, 90.f, 0.f, 0.f));

	objects[PLAYER]->setShooting(true);
}


CreditsState::~CreditsState() {}
