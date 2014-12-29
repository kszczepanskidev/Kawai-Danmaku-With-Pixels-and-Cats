#include "Application.h"


void Application::appMainLoop() {
	while (window->isOpen()) {
		appEvent();
		appDraw();
	}
}

void Application::appDraw() {}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		if (event.type == Event::KeyReleased) {
			switch (event.key.code) {
			case Keyboard::Escape:
				window->close();
				break;
			case Keyboard::Return:
				window->clear(Color::Black);
				window->display();
				break;
			}
		}
	}
}


Application::Application() {
	stManager = new StateManager();
	texManager = new TextureManager();
	aniHandler = new AnimationHandler();

	/*camera = new View();
	camera->setCenter(Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	camera->setSize(Vector2f(1280, 720));*/

	window = new RenderWindow();
	window->create(VideoMode(1280, 720), "Kawai Danmaku With Pixels and Cats");
	window->setFramerateLimit(60);
	//window->setView(*camera);
	Vector2i windowPos = window->getPosition();
	windowPos.y -= 15;
	window->setPosition(windowPos);

	/* test stuff shit */
	Sprite sprite;
	sprite.setTexture(texManager->getTexture("splashin"));

	window->clear(Color::Color(200, 200, 200, 255));
	window->draw(sprite);
	window->display();






}


Application::~Application() {}
