#pragma once
#include "Includes.h"
#include "StateManager.h"

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

	Application();
	virtual ~Application();
};

