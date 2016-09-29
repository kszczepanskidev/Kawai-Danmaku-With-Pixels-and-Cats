#include <ctime>
#include <memory>

#include "Includes.h"
#include "Application.h"


int main() {
	srand((unsigned int)time(NULL));

	auto app = make_unique<Application>();

	app->appMainLoop();

	return 0;
}