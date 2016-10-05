#pragma once
#include <iostream>
#include <thread>
#include <memory>
#include <SFML\Graphics.hpp>
#include "EventBus.h"

namespace E2D {

	class Graphics {

	public:
		Graphics() : threadClosed(true) { };

		void initialize();
		void start();

	private:
		void drawElements();
		void clearScreen();

	private:
		std::shared_ptr<sf::RenderWindow> window;
		
		bool threadClosed;

		// GETTERS / SETTERS ---------------------------------------------------
	public:
		inline bool isThreadClosed() { return threadClosed; };

	};

};
