#include "headers\Engine.h"

int main() {
	std::shared_ptr<E2D::Engine> engine = E2D::Engine::getInstance();
	std::cout << "Engine count: " << engine.use_count() << std::endl;

	engine->initialize();

	engine->setRealtimeKeyboardCallback([]() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			std::cout << "[KEY CALLBACK] A key has been pressed" << std::endl;
		}
	});

	engine->start();

	return 0;
}
