#include "headers\Engine.h"

int main() {
	std::shared_ptr<E2D::Engine> engine = E2D::Engine::getInstance();
	std::cout << "Engine count: " << engine.use_count() << std::endl;

	engine->initialize();

	engine->setRealtimeKeyboardCallback([]() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			// std::cout << "[KEY CALLBACK] R key has been pressed" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			// std::cout << "[KEY CALLBACK] G key has been pressed" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			// std::cout << "[KEY CALLBACK] B key has been pressed" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			// std::cout << "[KEY CALLBACK] A key has been pressed" << std::endl;
		}
	});

	std::shared_ptr<E2D::EventBus> eBus = E2D::EventBus::getInstance();
	eBus->subscribeKeyPress([](E2D::KeyReleasedMessage message) -> void {
		for (std::vector<sf::Keyboard::Key>::iterator it = message.keys.begin(); it != message.keys.end() && *it != sf::Keyboard::End; it++) {
			sf::Keyboard::Key& key(*it);
			std::cout << "[KEY CALLBACK] " << key << " key has been pressed" << std::endl;
		}
	});

	engine->start();

	return 0;
}
