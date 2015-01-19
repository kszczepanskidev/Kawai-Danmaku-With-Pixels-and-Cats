#include "CreditsState.h"

#include "StateManager.h"

enum textures{ BG, SPLASHIN, KRYSZTAL, SCOFIELD, SHIHOIN, ARCHER, LOGO, DANCEFLOOR };
enum texts { CREDITS_TEXT, DEVELOPEDBY_TEXT, CODERS_TEXT, KRYSZTAL_TEXT, SCOFIELD_TEXT, ARTS_TEXT, ARCHER_TEXT, SHIHOIN_TEXT, MUSIC_TEXT, DANCEFLOOR_TEXT };

void CreditsState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased && event->key.code == Keyboard::Return)
	if (phase == 3) {
		stManager->setActiveState(stManager->getState(MAINMENU));
		phase = 0;
	}
	else
		++phase;
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
	
	stateTexts.emplace_back(new GameText("Credits", font, 640.f, 30.f));
	stateTexts[CREDITS_TEXT]->text.setCharacterSize(52);
	stateTexts.emplace_back(new GameText("Developer", font, 640.f, 120.f));
	stateTexts.emplace_back(new GameText("Coders", font, 640.f, 120.f));
	stateTexts.emplace_back(new GameText("Kamil 'krysztal' Szczepanski", font, 565.f, 195.f));
	stateTexts.emplace_back(new GameText("Hubert Kazmierczak", font, 405.f, 356.f));
	stateTexts.emplace_back(new GameText("Artists", font, 640.f, 120.f));
	stateTexts.emplace_back(new GameText("Anna 'Shihoin' Kochanska", font, 555.f, 225.f));
	stateTexts.emplace_back(new GameText("Rafal 'Archer' Krakowiak", font, 555.f, 410.f));

	for (auto t : stateTexts)
		t->text.setOrigin(t->text.getLocalBounds().width / 2, 0);
}

void CreditsState::initSprites(TextureManager* texManager) {
	Sprite temp;
	sprites.clear();

	temp.setTexture(texManager->getTexture("credits_bg"));
	sprites.emplace_back(temp);

	temp.setTexture(texManager->getTexture("splashin"));
	sprites.emplace_back(temp);
	sprites[SPLASHIN].setOrigin(sprites[SPLASHIN].getLocalBounds().width / 2.f, sprites[SPLASHIN].getLocalBounds().height / 2.f);
	sprites[SPLASHIN].setScale(0.5, 0.5);
	sprites[SPLASHIN].setPosition(640.f, 360.f);

	temp.setTexture(texManager->getTexture("krysztal_av"));
	sprites.emplace_back(temp);
	sprites[KRYSZTAL].setPosition(1030.f, 134.f);
	sprites[KRYSZTAL].setTextureRect(IntRect(0, 0, 154, 154));

	temp.setTexture(texManager->getTexture("scofield_av"));
	sprites.emplace_back(temp);
	sprites[SCOFIELD].setPosition(717.f, 297.f);
	sprites[SCOFIELD].setTextureRect(IntRect(0, 0, 154, 154));

	temp.setTexture(texManager->getTexture("shihoin_av"));
	sprites.emplace_back(temp);
	sprites[SHIHOIN].setPosition(976.f, 86.f);
	sprites[SHIHOIN].setTextureRect(IntRect(0, 0, 143, 231));

	temp.setTexture(texManager->getTexture("archer_av"));
	sprites.emplace_back(temp);
	sprites[ARCHER].setPosition(960.f, 332.f);
	sprites[ARCHER].setTextureRect(IntRect(0, 0, 184, 184));

	temp.setTexture(texManager->getTexture("logo"));
	sprites.emplace_back(temp);
	sprites[LOGO].setPosition(359.f, 83.f);
	sprites[LOGO].setTextureRect(IntRect(0, 0, 595, 510));
	sprites[LOGO].setScale(0.82, 0.82);
}

void CreditsState::draw(RenderWindow* window) {
	window->clear(Color::Black);

	window->draw(stateTexts[0]->text);

	for (auto o : objects)
		o->draw(window);

	for (auto b : bullets)
		b->draw(window);

	window->draw(sprites[BG]);

	switch (phase) {
	case 0:
		window->draw(sprites[SPLASHIN]);
		window->draw(stateTexts[1]->text);
		break;
	case 1:
		window->draw(stateTexts[CODERS_TEXT]->text);
		window->draw(stateTexts[KRYSZTAL_TEXT]->text);
		window->draw(sprites[KRYSZTAL]);
		window->draw(stateTexts[SCOFIELD_TEXT]->text);
		window->draw(sprites[SCOFIELD]);
		break;
	case 2:
		window->draw(stateTexts[ARTS_TEXT]->text);
		window->draw(stateTexts[SHIHOIN_TEXT]->text);
		window->draw(sprites[SHIHOIN]);
		window->draw(stateTexts[ARCHER_TEXT]->text);
		window->draw(sprites[ARCHER]);
		break;
	case 3:
		window->draw(sprites[LOGO]);
		break;
	}
}



CreditsState::CreditsState(Font f, TextureManager* tM) {
	font = f;
	
	texManager = tM;

	phase = 0;

	initTexts();
	initSprites(texManager);

	objects.emplace_back(new Player(texManager, &bullets, 3, 80.f, 470.f));
	objects.emplace_back(new Enemy(texManager, &bullets, 1, 1200.f, 90.f, 0.f, 0.f));

	objects[PLAYER]->setShooting(true);
}


CreditsState::~CreditsState() {}
