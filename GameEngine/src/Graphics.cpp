#include "headers\Graphics.h"

void E2D::Graphics::initialize() {
	std::shared_ptr<E2D::EventBus> eBus = E2D::EventBus::getInstance();
	eBus->subscribeColorChange([&](E2D::ColorChangeMessage message) -> void {
		std::cout << "[CB] Message: " << message.r << message.g << message.b << message.a << std::endl;
	});

	std::cout << "[GRAPHICS] Initialized" << std::endl;
}

void E2D::Graphics::start() {
	std::thread GRAPHICS_THREAD([&]() {
		std::cout << "[GRAPHICS] Thread started" << std::endl;
		threadClosed = false;

		std::shared_ptr<E2D::EventBus> eBus = E2D::EventBus::getInstance();

		window = std::make_shared<sf::RenderWindow>();
		window->create(sf::VideoMode(800, 600), "2D Engine");

		std::vector<sf::Keyboard::Key> keysReleased(30);
		unsigned short int keysReleasedCounter = 0;

		while (window->isOpen()) {
			
			sf::Event event;

			while (window->pollEvent(event)) {

				if (event.type == sf::Event::Closed)
					window->close();

				if (event.type == sf::Event::KeyReleased) {
					if (keysReleasedCounter < 30) {
						keysReleased[keysReleasedCounter] = event.key.code;
						keysReleasedCounter++;
					}
				}
					
			}

			if (keysReleasedCounter != 0) {
				keysReleased[keysReleasedCounter] = sf::Keyboard::End;
				keysReleasedCounter = 0;

				eBus->publishKeyPress(E2D::KeyReleasedMessage(keysReleased));
			}

			clearScreen();
			drawElements();

			window->display();
		}

		std::cout << "[GRAPHICS] Thread ended" << std::endl;
		threadClosed = true;
	});

	GRAPHICS_THREAD.detach();
}

void E2D::Graphics::drawElements() {

}

void E2D::Graphics::clearScreen() {
	window->clear(sf::Color::Black);
}
