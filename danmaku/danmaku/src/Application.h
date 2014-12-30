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
//private:
public:
	StateManager* stManager;
	//Player* player;
	TextureManager* texManager;
	AnimationHandler* aniHandler;
	RenderWindow* window;
	View* camera;

	vector<Sprite> sprites;

	Font font;

public:
	void appMainLoop();
	void appDraw();
	void appEvent();
	void splashScreen(Sprite);
	void initSprites();



	Application();
	virtual ~Application();
};

