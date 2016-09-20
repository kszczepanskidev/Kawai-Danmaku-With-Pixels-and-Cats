#include "Application.h"

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
	stManager->getActiveState()->update(stManager);
}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
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

		/*if (Keyboard::isKeyPressed(Keyboard::Delete))
			window->setFramerateLimit(0);
		else
			window->setFramerateLimit(60);*/
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

	texManager = new TextureManager();
	stManager = new StateManager(font, texManager);
	aniHandler = new AnimationHandler();

	window = new RenderWindow();
	window->create(VideoMode(1280, 720), "Kawai Danmaku With Pixels and Cats");
	window->clear(Color::Black);
	//window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
	
	Vector2i windowPos = window->getPosition();
	windowPos.y -= 15;
	window->setPosition(windowPos);
}

Application::~Application() {}
