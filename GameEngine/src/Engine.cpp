#include "headers\Engine.h"

unsigned int E2D::Engine::initialize() {
	graphics.initialize();

	/*std::shared_ptr<E2D::EventBus> eBus = E2D::EventBus::getInstance();
	eBus->subscribe<int>("test", [&](int message) {
		std::cout << "[CB] Message: " << message << std::endl;
	});

	eBus->publish("test", 50);*/

	std::cout << "[ENGINE] Initialized" << std::endl;
	return 0;
}

unsigned int E2D::Engine::start() {
	graphics.start();

	std::thread GAME_THREAD([&]() {
		while (graphics.isThreadClosed());

		std::cout << "[ENGINE] Thread started" << std::endl;
		while (!graphics.isThreadClosed()) {
			realtimeKeyboardCallback();
		}

		std::cout << "[ENGINE] Thread ended" << std::endl;
	});

	GAME_THREAD.join();
	return 0;
}
