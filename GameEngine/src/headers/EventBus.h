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
			static std::vector<std::function<void(E2D::ColorChangeMessage& message)>>::iterator it = colorChangeSubscribers.begin();

			if (it != colorChangeSubscribers.end()) {
				*it = executor;
				it++;
			}
		}

		void publishColorChange(E2D::ColorChangeMessage& message) {
			for (std::vector<std::function<void(E2D::ColorChangeMessage& message)>>::iterator it = colorChangeSubscribers.begin(); it != colorChangeSubscribers.end() && *it != nullptr; it++) {
				(*it)(message);
			}
		}

		// KEY PRESS ######################################################
		void subscribeKeyReleased(std::function<void(E2D::KeyReleasedMessage& message)> executor) {
			static std::vector<std::function<void(E2D::KeyReleasedMessage& message)>>::iterator it = keyReleasedSubscribers.begin();

			if (it != keyReleasedSubscribers.end()) {
				*it = executor;
				it++;
			}
		}

		void publishKeyReleased(E2D::KeyReleasedMessage& message) {
			for (std::vector<std::function<void(E2D::KeyReleasedMessage& message)>>::iterator it = keyReleasedSubscribers.begin(); it != keyReleasedSubscribers.end() && *it != nullptr; it++) {
				(*it)(message);
			}
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
		EventBus() : colorChangeSubscribers(50), keyReleasedSubscribers(50) { };

	};

}
