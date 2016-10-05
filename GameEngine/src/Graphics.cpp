#include "headers\Graphics.h"

void E2D::Graphics::initialize() {
	std::shared_ptr<E2D::EventBus> eBus = E2D::EventBus::getInstance();
	eBus->subscribe<E2D::ColorChangeMessage>("colorChange", [&](E2D::ColorChangeMessage message) {
		std::cout << "[CB] Message: " << message.r << message.g << message.b << message.a << std::endl;
	});

	std::cout << "[GRAPHICS] Initialized" << std::endl;
}

void E2D::Graphics::start() {
	std::thread GRAPHICS_THREAD([&]() {
		std::cout << "[GRAPHICS] Thread started" << std::endl;
		threadClosed = false;

		window = std::make_shared<sf::RenderWindow>();
		window->create(sf::VideoMode(800, 600), "2D Engine");

		while (window->isOpen()) {
			sf::Event event;
			while (window->pollEvent(event)) {

				if (event.type == sf::Event::Closed)
					window->close();
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
