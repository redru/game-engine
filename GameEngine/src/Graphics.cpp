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
		window->create(sf::VideoMode(1280, 720), "2D Engine");

		std::vector<sf::Keyboard::Key> keysReleased(30);
		unsigned short int keysReleasedCounter = 0;

		while (window->isOpen()) {
			
			sf::Event event;

			while (window->pollEvent(event)) {

				if (event.type == sf::Event::Closed)
					window->close();

				// Add released keys to KeyVector
				if (event.type == sf::Event::KeyReleased) {
					if (keysReleasedCounter < 30) {
						keysReleased[keysReleasedCounter] = event.key.code; // Set key code inside keysReleased
						keysReleasedCounter++; // Increment keysReleasedCounter +1
					}
				}
					
			}

			// If there were keys released
			if (keysReleasedCounter != 0) {
				keysReleased[keysReleasedCounter] = sf::Keyboard::Unknown; // Add "Unknown" key marker to the end
				keysReleasedCounter = 0; // Reset keysReleased counter

				eBus->publishKeyReleased(E2D::KeyReleasedMessage(keysReleased)); // Publish keyReleased message
			}

			// Clear screen function
			clearScreen(sf::Color::Black);

			// Draw all elements
			drawElements();

			// Swap buffers
			window->display();
		}

		std::cout << "[GRAPHICS] Thread ended" << std::endl;
		threadClosed = true;
	});

	GRAPHICS_THREAD.detach();
}

void E2D::Graphics::drawElements() {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);
	
	window->draw(rectangle);
}

void E2D::Graphics::clearScreen(sf::Color color) {
	window->clear(color);
}
