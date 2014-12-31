#include <ctime>

#include "Includes.h"
#include "Application.h"


int main() {
	srand((unsigned int)time(NULL));

	Application* app = new Application();

	app->appMainLoop();

	//PAUSE();
	return 0;
}