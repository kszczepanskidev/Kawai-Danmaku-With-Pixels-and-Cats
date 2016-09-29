#include "Application.h"
#include <iomanip>
//#include <memory>
Clock update_clock;

void Application::appMainLoop() {
	
	while (window->isOpen()) {
		appEvent();
		appUpdate();
		appDraw();
	}
}

void Application::appDraw() {
	window->clear(Color::Black);

	stManager->getActiveState()->draw(window);

	window->display();
}

void Application::appUpdate() {
	Time elapsed_time = update_clock.getElapsedTime();
	
	if (elapsed_time.asSeconds() >= 0.01666) {
		stManager->getActiveState()->update(stManager);
		update_clock.restart();
	}
}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		if (event.type == Event::Closed)
			window->close();

		/*if (event.type == Event::KeyReleased) {
			switch (event.key.code) {
			case Keyboard::Escape:
				stManager->setActiveState(stManager->getState(QUIT));
				break;
			}
		}*/
		if (event.type == Event::KeyReleased || event.type == Event::KeyPressed || event.type == Event::TextEntered)
			stManager->getActiveState()->handleEvent(&event, stManager);
	}
}

void Application::splashScreen() {
	Sprite splash;
	
	splash.setTexture(texManager->getTexture("splashin"));

	Uint8 light = 10;
	/*	fade in */
	while (light < 210) {
		splash.setColor(Color(light, light, light));
		window->draw(splash);
		window->display();
		sleep(seconds(0.01f));
		light += 2;
	}
	sleep(seconds(0.05f));

	/*	fade out */
	while (light > 0) {
		splash.setColor(Color(light, light, light));
		window->draw(splash);
		window->display();
		sleep(seconds(0.01f));
		light -= 3;
	}
}

Application::Application() {
	font.loadFromFile("resources/fonts/PressStart2P.ttf");

	texManager = make_unique<TextureManager>();
	stManager = make_unique<StateManager>(font, texManager);
	aniHandler = make_unique<AnimationHandler>();

	window = make_unique<RenderWindow>();
	window->create(VideoMode(1280, 720), "Kawai Danmaku With Pixels and Cats");
	window->clear(Color::Black);
	//window->setVerticalSyncEnabled(true);
	
	//Vector2i windowPos = window->getPosition();
	//windowPos.y -= 15;
	window->setPosition((window->getPosition()).y - 15);

	splashScreen();
}

Application::~Application() {}
