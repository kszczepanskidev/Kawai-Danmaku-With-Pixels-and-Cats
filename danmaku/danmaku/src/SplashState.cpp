#include "SplashState.h"
#include "StateManager.h"

void SplashState::handleEvent(Event* event, StateManager* stManager) {}

void SplashState::update() {
	/*	fade in */
	if (in && light < 210)
		light += 2;

	/*	pause between in/out */
	if (in && light == 210) {
		sleep(seconds(0.05f));
		in = 0;
	}

	/*	fade out */
	if (!in && light > 0)
		light -= 3;

	if (!in && light == 0)
		stManager->setActiveState(stManager->getState(MAINMENU));

	sprite.setColor(Color(light, light, light));
}

void SplashState::draw(RenderWindow* window) {
	window->draw(sprite);
	sleep(seconds(0.01f));
}

SplashState::SplashState(TextureManager* texManager, StateManager* sM) {
	light = 10;
	in = 1;

	stManager = sM;
	sprite.setTexture(texManager->getTexture("splashin"));
}


SplashState::~SplashState() {}
