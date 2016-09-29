#pragma once
#include "Includes.h"
#include "StateManager.h"
#include "TextureManager.h"
#include "AnimationHandler.h"

#include "SPGameState.h"
#include "MenuState.h"
#include "ConnectState.h"
#include <memory>

class Application {
private:
	unique_ptr<StateManager> stManager;
	unique_ptr<TextureManager> texManager;
	unique_ptr<AnimationHandler> aniHandler;
	unique_ptr<RenderWindow> window;
	unique_ptr<View> camera;

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

