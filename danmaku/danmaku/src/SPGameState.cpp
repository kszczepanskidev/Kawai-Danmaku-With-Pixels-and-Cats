#include "SPGameState.h"
#include "StateManager.h"

enum textures{ BG, CUSTOM1, SCROLLS };
enum gameTexts{ SCORE, SCORE_V, LIFE, LIFE_V, SPECIAL, SPECIAL_V, POWER, POWER_V, GRAZE, GRAZE_V };

void SPGameState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::Escape:
			stManager->setActiveState(stManager->getState(MAINMENU));
			break;
	default:
		objects[0]->handleEvent(event);
		break;
	}
	else
		objects[0]->handleEvent(event);
}

void SPGameState::update(StateManager* stManager) {
	scrollBG();
	updateTexts();

	for (unsigned int i = 0; i < objects.size(); ++i)
		if (objects[i]->update())
			objects.erase(objects.begin() + i);

	for (unsigned int i = 0; i < bullets.size(); ++i)
		if (bullets[i]->update())
			bullets.erase(bullets.begin() + i);

	checkCollision(&objects,&bullets);

	for (unsigned int j = 1; j < objects.size(); ++j)
	if (!objects[j]->getLive()) {
		if (rand() % 50 < 10)
			objects.emplace_back(new Bonus(texManager, objects[j]->getPosX(), objects[j]->getPosY()));
		objects.erase(objects.begin() + j);
		objects[0]->increaseScore(10);
	}

	if (!objects[0]->getLive())
		stManager->setActiveState(stManager->getState(MAINMENU));
	
	if ((rand() % 100 < 2) && objects.size() < 11)
		objects.emplace_back(new Enemy(texManager, &bullets, 0, float(rand() % 600 + 200), -25.f, 90.f, 4.f));
}

void SPGameState::scrollBG() {
	for (int i = 0; i < 3; ++i) {
		pos_y[i] += scrollSpeed;
		if (pos_y[i] > 720.f) {
			pos_y[i] = -1440.f;
			sprites[i + SCROLLS].setTexture(texManager->getTexture("game_scroll" + to_string(rand()%3+1)));
		}
	}
}

void SPGameState::initTexts() {
	gameTexts.clear();

	gameTexts.emplace_back(new GameText("Score:", font, 920.f, 8.f));
	gameTexts.emplace_back(new GameText("0", font, 1250.f, 51.f));

	gameTexts.emplace_back(new GameText("Life:", font, 920.f, 108.f));
	gameTexts.emplace_back(new GameText("+ + +", font, 1250.f, 150.f));

	gameTexts.emplace_back(new GameText("Special:", font, 920.f, 206.f));
	gameTexts.emplace_back(new GameText("* * * * *", font, 1250.f, 255.f));

	gameTexts.emplace_back(new GameText("Power:", font, 920.f, 311.f));
	gameTexts.emplace_back(new GameText("# # # #", font, 1250.f, 353.f));

	gameTexts.emplace_back(new GameText("Graze:", font, 920.f, 410.f));
	gameTexts.emplace_back(new GameText("0", font, 1250.f, 452.f));
}

void SPGameState::updateTexts() {
	String temp;

	gameTexts[SCORE_V]->text.setString(to_string(objects[0]->getScore()));

	for (int i = 0; i < objects[0]->getLife(); ++i)
		temp += "+ ";
	gameTexts[LIFE_V]->text.setString(temp);
	temp.clear();

	for (int i = 0; i < objects[0]->getSpecial(); ++i)
		temp += "* ";
	gameTexts[SPECIAL_V]->text.setString(temp);
	temp.clear();

	for (int i = 0; i < objects[0]->getPower(); ++i)
		temp += "# ";
	gameTexts[POWER_V]->text.setString(temp);
	temp.clear();
	
	gameTexts[GRAZE_V]->text.setString(to_string(objects[0]->getGraze()));

	/* aligning value texts to right */
	gameTexts[SCORE_V]->text.setOrigin(gameTexts[SCORE_V]->text.getLocalBounds().width, 0);
	gameTexts[LIFE_V]->text.setOrigin(gameTexts[LIFE_V]->text.getLocalBounds().width, 0);
	gameTexts[POWER_V]->text.setOrigin(gameTexts[POWER_V]->text.getLocalBounds().width, 0);
	gameTexts[SPECIAL_V]->text.setOrigin(gameTexts[SPECIAL_V]->text.getLocalBounds().width, 0);
	gameTexts[GRAZE_V]->text.setOrigin(gameTexts[GRAZE_V]->text.getLocalBounds().width, 0);
}


void SPGameState::draw(RenderWindow* window) {
	window->clear(Color(144, 179, 184, 255));
	//window->clear(Color(169, 210, 216, 255));

	for (int i = 0; i < 3; ++i) {
		sprites[i + SCROLLS].setPosition(pos_x, pos_y[i]);
		window->draw(sprites[i + SCROLLS]);
	}

	for (auto o : objects)
		o->draw(window);

	for (auto b : bullets)
		b->draw(window);

	window->draw(sprites[BG]);

	for (auto t : gameTexts)
		window->draw(t->text);
}

void SPGameState::initSprites(TextureManager* texManager) {
	Sprite temp;

	sprites.clear();

	temp.setTexture(texManager->getTexture("game_bg"));
	sprites.emplace_back(temp);

	temp.setTexture(texManager->getTexture("game_custom1"));
	sprites.emplace_back(temp);
	sprites[CUSTOM1].setTextureRect(IntRect(0, 0, 157, 280));
	sprites[CUSTOM1].setPosition(932.f, 440.f);

	temp.setTextureRect(IntRect(0, 0, 700, 720));

	for (int i = 0; i < 3; ++i) {
		temp.setTexture(texManager->getTexture("game_scroll" + to_string(i+1)));
		sprites.emplace_back(temp);
	}
}


SPGameState::SPGameState(Font f, TextureManager* tM) {
	texManager = tM;

	gameTime = 0;

	font = f;

	scrollSpeed = 2.f;
	
	pos_x = 188.f;

	for (int i = 0; i < 3; ++i)
		pos_y[i] = 0.f - i*720.f;

	initTexts();
	initSprites(texManager);

	objects.emplace_back(new Player(texManager, &bullets, 1, 535.5f, 650.f));
}


SPGameState::~SPGameState() {}