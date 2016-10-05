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
		template<E2D::Message T> void subscribe(std::string type, std::function<void(T message)> executor) {
			if (subscribers.find(type) == subscribers.end()) {
				subscribers[type] = std::vector<std::function<void(T message)>>(50);
			}

			subscribers[type][0] = executor;
		}

		template<E2D::Message T> void publish(std::string type, T message) {
			if (subscribers.find(type) != subscribers.end()) {
				subscribers[type][0](message);
			}
		}

	private:
		std::map< std::string, std::vector<std::function<void(E2D::Message message)>> > subscribers;

		// SINGLETON ---------------------------------------------------------------------------------
	public:
		~EventBus() { };

	public:
		static std::shared_ptr<E2D::EventBus> getInstance() {
			static std::shared_ptr<E2D::EventBus> instance(new E2D::EventBus);
			return instance;
		}


	private:
		EventBus() { };

	};

}
