#pragma once
#include "Includes.h"
#include "StateManager.h"

#include "GameState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "ConnectState.h"

class Application {
private:
	StateManager* stManager;
	//Player* player;
	//TextureManager* texManager;
	//AnimationManager* aniManager;
	RenderWindow* window;
	View* camera;
public:
	void appMainLoop();
	void appDraw();
	void appEvent();

	Application();
	virtual ~Application();
};

