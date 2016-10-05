#pragma once
#include <iostream>
#include <map>
#include <array>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "Messages.h"

namespace E2D {

	class EventBus {

	public:
		// COLOR CHANGE ###################################################
		void subscribeColorChange(std::function<void(E2D::ColorChangeMessage& message)> executor) {
			colorChangeSubscribers[0] = executor;
		}

		void publishColorChange(E2D::ColorChangeMessage& message) {
			colorChangeSubscribers[0](message);
		}

		// KEY PRESS ######################################################
		void subscribeKeyPress(std::function<void(E2D::KeyReleasedMessage& message)> executor) {
			keyReleasedSubscribers[0] = executor;
		}

		void publishKeyPress(E2D::KeyReleasedMessage& message) {
			keyReleasedSubscribers[0](message);
		}

	private:
		std::vector<std::function<void(E2D::ColorChangeMessage& message)>> colorChangeSubscribers;
		std::vector<std::function<void(E2D::KeyReleasedMessage& message)>> keyReleasedSubscribers;

		// SINGLETON ---------------------------------------------------------------------------------
	public:
		~EventBus() { };

	public:
		static std::shared_ptr<E2D::EventBus> getInstance() {
			static std::shared_ptr<E2D::EventBus> instance(new E2D::EventBus);
			return instance;
		}

	private:
		EventBus() : colorChangeSubscribers(50), keyReleasedSubscribers(50){ };

	};

}
