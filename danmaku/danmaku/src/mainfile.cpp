#include "Includes.h"
#include "Application.h"


int main() {
	Application* app = new Application();

	app->appMainLoop();

	PAUSE();
	return 0;
}