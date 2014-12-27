#include "Application.h"


void Application::appMainLoop() {
	int i = 0;
	while (1) {
		appEvent();
		appDraw();
		++i;
		if (i == 5) stManager->setActiveState(stManager->getState(GAME));
		if (i == 10) break;
	}
}

void Application::appDraw() {
	stManager->getActiveState()->onDraw();
}

void Application::appEvent() {}


Application::Application() {
	stManager = new StateManager();
}


Application::~Application() {}
