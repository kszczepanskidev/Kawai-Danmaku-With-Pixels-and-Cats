#include "GameState.h"
#include "StateManager.h"

void GameState::handleEvent(Event* event, StateManager* stManager) {
	switch (event->key.code) {
	case Keyboard::Return:
		stManager->setActiveState(stManager->getState(MAINMENU));
		break;
	default:
		player->handleEvent(event);
		break;
	}
}

void GameState::update() {
	scrollBG();
	player->update();
	updateTexts();
}

void GameState::scrollBG() {
	int speed = 5;
	pos_y1 += speed;
	pos_y2 += speed;
	pos_y3 += speed;

	if (pos_y1 >= 1440.f) {
		pos_y1 = -720.f;
		pos_y2 = -1440.f;
		do
		bg1 = rand() % 3 + 3;
		while (bg1 == bg3);
		do
		bg2 = rand() % 3 + 3;
		while (bg2 == bg1);
	}

	if (pos_y3 >= 720.f) {
		pos_y3 = -1440.f;
		bg3 = 12 - bg1 - bg2;
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
	/* aligning text to right */
	gameTexts[SCORE_V]->text.setOrigin(gameTexts[SCORE_V]->text.getLocalBounds().width, 0);
	gameTexts[LIFE_V]->text.setOrigin(gameTexts[LIFE_V]->text.getLocalBounds().width, 0);
	gameTexts[POWER_V]->text.setOrigin(gameTexts[POWER_V]->text.getLocalBounds().width, 0);
	gameTexts[SPECIAL_V]->text.setOrigin(gameTexts[SPECIAL_V]->text.getLocalBounds().width, 0);
	gameTexts[GRAZE_V]->text.setOrigin(gameTexts[GRAZE_V]->text.getLocalBounds().width, 0);
}


void GameState::draw(RenderWindow* window, vector<Sprite>* sprites) {
	(*sprites)[bg1].setPosition(pos_x, pos_y1);
	(*sprites)[bg2].setPosition(pos_x, pos_y2);
	(*sprites)[bg3].setPosition(pos_x, pos_y3);

	window->draw((*sprites)[bg1]);
	window->draw((*sprites)[bg2]);
	window->draw((*sprites)[bg3]);

	window->draw((*sprites)[GAME_BG]);

	window->draw((*sprites)[GAME_CUSTOM1]);

	for (auto t : gameTexts) {
		window->draw(t->text);
	}

	window->draw(gameTexts[SCORE]->text);
	window->draw((*sprites)[GAME_CUSTOM1]);

	player->draw(window, sprites);
}


GameState::GameState(Font f) {
	gameTime = 0;

	font = f;
	
	pos_x = 188.f;
	pos_y1 = 0.f;
	pos_y2 = -720.f;
	pos_y3 = -1440.f;

	bg1 = SCROLL1;
	bg2 = SCROLL2;
	bg3 = SCROLL3;

	initTexts();

	player = new Player();
}


GameState::~GameState() {}
