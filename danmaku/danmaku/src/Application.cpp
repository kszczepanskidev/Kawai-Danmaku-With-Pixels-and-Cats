#include "Application.h"

void Application::appMainLoop() {
	while (window->isOpen()) {
		appEvent();
		appDraw();
	}
}

void Application::appDraw() {
	stManager->getActiveState()->draw(window);
	window->display();
}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		if (event.type == Event::KeyReleased) {
			switch (event.key.code) {
			case Keyboard::Escape:
				window->close();
				break;
			default:
				stManager->getActiveState()->handleEvent(&event);
				break;
			}
		}
	}
}

void Application::splashScreen(Sprite splash) {
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

void Application::initSprites() {
	Sprite sprite;

	sprites.clear();

	sprite.setTexture(texManager->getTexture("splashin"));
	sprites.push_back(sprite);
	
}


Application::Application() {
	font.loadFromFile("Verdana.ttf");

	stManager = new StateManager(font);
	texManager = new TextureManager();
	aniHandler = new AnimationHandler();

	/*camera = new View();
	camera->setCenter(Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	camera->setSize(Vector2f(1280, 720));*/

	window = new RenderWindow();
	window->create(VideoMode(1280, 720), "Kawai Danmaku With Pixels and Cats");
	window->clear(Color::Black);
	window->setFramerateLimit(60);
	//window->setView(*camera);
	
	Vector2i windowPos = window->getPosition();
	windowPos.y -= 15;
	window->setPosition(windowPos);

	/*	Loading tetures to sprites	*/
	initSprites();

	/* 'animated' splash screen	 */
	splashScreen(sprites[SPLASH]);
}

Application::~Application() {}
