#pragma once
#include "Graphics.h"

namespace E2D {

	class Engine {

	public:
		unsigned int initialize();
		unsigned int start();

	private:
		E2D::Graphics graphics;
		std::function<void()> realtimeKeyboardCallback;

		// GETTERS / SETTERS ---------------------------------------------------
	public:
		inline void setRealtimeKeyboardCallback(std::function<void()> _realtimeKeyboardCallback) { realtimeKeyboardCallback = _realtimeKeyboardCallback; };

		// SINGLETON ---------------------------------------------------------------------------------
	public:
		~Engine() { };

	public:
		static std::shared_ptr<E2D::Engine> getInstance() {
			static std::shared_ptr<E2D::Engine> instance(new E2D::Engine);
			return instance;
		}


	private:
		Engine() { };

	};

}
