#include "Application.h"

bool fullscreen = false;

void Application::appMainLoop() {
	while (window->isOpen()) {
		appEvent();
		appUpdate();
		appDraw();
	}
}

void Application::appDraw() {
	window->clear(Color::Black);

	stManager->getActiveState()->draw(window, &sprites);

	window->display();
}

void Application::appUpdate() {
	stManager->getActiveState()->update();
}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		//if ()
		if (event.type == Event::KeyReleased || event.type == Event::TextEntered) {
			switch (event.key.code) {
			case Keyboard::Escape:
				stManager->setActiveState(stManager->getState(QUIT));
				break;
			default:
				stManager->getActiveState()->handleEvent(&event, stManager);
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
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("menu_bg"));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("game_bg"));
	sprites.emplace_back(sprite);

	sprite.setTextureRect(IntRect(0, 0, 700, 720));

	sprite.setTexture(texManager->getTexture("game_scroll1"));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("game_scroll2"));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("game_scroll3"));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("game_custom1"));
		sprite.setTextureRect(IntRect(0, 0, 157, 280));
		sprite.setPosition(932.f, 440.f);
	sprites.emplace_back(sprite);

	sprite.setTextureRect(IntRect(0, 0, 1280, 720));
	sprite.setPosition(0, 0.f);

	sprite.setTexture(texManager->getTexture("connect_bg"));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("player"));
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	sprites.emplace_back(sprite);

	sprite.setTexture(texManager->getTexture("bullet"));
	sprites.emplace_back(sprite);
}


Application::Application() {
	font.loadFromFile("resources/fonts/PressStart2P.ttf");

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
	//splashScreen(sprites[SPLASH]);
}

Application::~Application() {}
