#include "GameState.h"
#include "StateManager.h"

enum textures{ BG, SCROLL1, SCROLL2, SCROLL3, CUSTOM1 };

void GameState::handleEvent(Event* event, StateManager* stManager) {
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::Return:
			stManager->setActiveState(stManager->getState(MAINMENU));
			break;
	default:
		objects[0]->handleEvent(event);
		break;
	}
	else
		objects[0]->handleEvent(event);
}

void GameState::update(StateManager* stManager) {
	scrollBG();
	updateTexts();

	for (unsigned int i = 0; i < objects.size(); ++i)
		if (objects[i]->update())
			objects.erase(objects.begin() + i);

	for (unsigned int i = 0; i < bullets.size(); ++i)
		if (bullets[i]->update())
			bullets.erase(bullets.begin() + i);

	checkCollision(&objects,&bullets);

	/*if (!objects[0]->getLive())
		stManager->setActiveState(stManager->getState(MAINMENU));*/
	
	if ((rand() % 100 == 3) && objects.size() < 11)
		objects.emplace_back(new Enemy(texManager, &bullets, float(rand() % 600 + 200), -50.f, 90.f));
}

void GameState::scrollBG() {
	pos_y1 += scrollSpeed;
	pos_y2 += scrollSpeed;
	pos_y3 += scrollSpeed;

	if (pos_y1 >= 1440.f) {
		pos_y1 = -720.f;
		pos_y2 = -1440.f;
		do
		bg1 = rand() % 3 + SCROLL1;
		while (bg1 == bg3);
		do
		bg2 = rand() % 3 + SCROLL1;
		while (bg2 == bg1);
	}

	if (pos_y3 >= 720.f) {
		pos_y3 = -1440.f;
		bg3 = SCROLL1 + SCROLL2 + SCROLL3 - bg1 - bg2;
	}
}

void GameState::initTexts() {
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

void GameState::updateTexts() {
	/* aligning value texts to right */
	gameTexts[SCORE_V]->text.setOrigin(gameTexts[SCORE_V]->text.getLocalBounds().width, 0);
	gameTexts[LIFE_V]->text.setOrigin(gameTexts[LIFE_V]->text.getLocalBounds().width, 0);
	gameTexts[POWER_V]->text.setOrigin(gameTexts[POWER_V]->text.getLocalBounds().width, 0);
	gameTexts[SPECIAL_V]->text.setOrigin(gameTexts[SPECIAL_V]->text.getLocalBounds().width, 0);
	gameTexts[GRAZE_V]->text.setOrigin(gameTexts[GRAZE_V]->text.getLocalBounds().width, 0);
}


void GameState::draw(RenderWindow* window) {
	sprites[bg1].setPosition(pos_x, pos_y1);
	sprites[bg2].setPosition(pos_x, pos_y2);
	sprites[bg3].setPosition(pos_x, pos_y3);

	window->draw(sprites[bg1]);
	window->draw(sprites[bg2]);
	window->draw(sprites[bg3]);

	window->draw(sprites[BG]);

	for (auto o : objects)
		o->draw(window);

	for (auto b : bullets)
		b->draw(window);

	window->draw(sprites[BG]);

	for (auto t : gameTexts)
		window->draw(t->text);
}

void GameState::initSprites(TextureManager* texManager) {
	Sprite temp;

	sprites.clear();

	temp.setTexture(texManager->getTexture("game_bg"));
	sprites.emplace_back(temp);


	temp.setTextureRect(IntRect(0, 0, 700, 720));

	temp.setTexture(texManager->getTexture("game_scroll1"));
	sprites.emplace_back(temp);

	temp.setTexture(texManager->getTexture("game_scroll2"));
	sprites.emplace_back(temp);

	temp.setTexture(texManager->getTexture("game_scroll3"));
	sprites.emplace_back(temp);


	temp.setTextureRect(IntRect(0, 0, 157, 280));
	temp.setPosition(932.f, 440.f);

	temp.setTexture(texManager->getTexture("game_custom1"));
	sprites.emplace_back(temp);
}


GameState::GameState(Font f, TextureManager* tM) {
	texManager = tM;

	gameTime = 0;

	font = f;

	scrollSpeed = 2.f;
	
	pos_x = 188.f;
	pos_y1 = 0.f;
	pos_y2 = -720.f;
	pos_y3 = -1440.f;

	bg1 = SCROLL1;
	bg2 = SCROLL2;
	bg3 = SCROLL3;

	initTexts();
	initSprites(texManager);

	objects.emplace_back(new Player(texManager, &bullets, 1));
}


GameState::~GameState() {}
