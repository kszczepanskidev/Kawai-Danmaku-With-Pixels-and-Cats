#pragma once
#include "Includes.h"
#include "StateManager.h"
#include "TextureManager.h"
#include "AnimationHandler.h"

#include "GameState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "ConnectState.h"

class Application {
private:
	StateManager* stManager;
	//Player* player;
	TextureManager* texManager;
	AnimationHandler* aniHandler;
	RenderWindow* window;
	View* camera;
public:
	void appMainLoop();
	void appDraw();
	void appEvent();

	Application();
	virtual ~Application();
};

