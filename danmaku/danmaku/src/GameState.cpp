#include "GameState.h"
#include "StateManager.h"

enum textures{ BG, CUSTOM1, CLOUDS };

bool distinct[CLOUDS_NUM];

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
		objects.emplace_back(new Enemy(texManager, &bullets, 0, float(rand() % 600 + 200), -50.f, 90.f, 7.f));
}

void GameState::scrollBG() {
	int temp;

	for (int i = 0; i < CLOUDS_NUM; ++i) {
		pos_y[i] += scrollSpeed;
		if (pos_y[i] > 720.f) {
			distinct[i] = false;
			do
			temp = rand() % 10;
			while (distinct[temp]);
			distinct[temp] = true;
			pos_y[i] = 0.f - temp * 175.f;
			sprites[i + CLOUDS].setTexture(texManager->getTexture(clouds_names[rand() % CLOUDS_NUM]));
		}
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
	window->clear(Color(169, 210, 216, 255));

	for (int i = 0; i < CLOUDS_NUM; ++i) {
		sprites[i + CLOUDS].setPosition(pos_x, pos_y[i]);
		window->draw(sprites[i + CLOUDS]);
	}

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

	temp.setTexture(texManager->getTexture("game_custom1"));
	sprites.emplace_back(temp);
	sprites[CUSTOM1].setTextureRect(IntRect(0, 0, 157, 280));
	sprites[CUSTOM1].setPosition(932.f, 440.f);

	temp.setTextureRect(IntRect(0, 0, 700, 175));

	for (int i = 0; i < CLOUDS_NUM; ++i) {
		clouds_names.emplace_back("cloud" + to_string(i));
		temp.setTexture(texManager->getTexture(clouds_names[i]));
		sprites.emplace_back(temp);
	}
}


GameState::GameState(Font f, TextureManager* tM) {
	texManager = tM;

	gameTime = 0;

	font = f;

	scrollSpeed = 2.f;
	
	pos_x = 188.f;
	for (int i = 0; i < CLOUDS_NUM; ++i)
		distinct[i] = false;

	int temp;

	for (int i = 0; i < CLOUDS_NUM; ++i) {
		do
		temp = rand() % 10;
		while (distinct[temp]);
		distinct[temp] = true;
		pos_y[i] = 0.f - temp * 175.f;
	}


	initTexts();
	initSprites(texManager);

	objects.emplace_back(new Player(texManager, &bullets, 1, 535.5f, 650.f));
}


GameState::~GameState() {}
