#pragma once
#include "Includes.h"
#include "StateManager.h"
#include "TextureManager.h"
#include "AnimationHandler.h"

#include "GameState.h"
#include "MenuState.h"
#include "ConnectState.h"


class Application {
private:
	StateManager* stManager;
	TextureManager* texManager;
	AnimationHandler* aniHandler;
	RenderWindow* window;
	View* camera;

	Font font;

public:
	void appMainLoop();
	void appDraw();
	void appEvent();
	void appUpdate();

	void splashScreen();

	Application();
	virtual ~Application();
};

