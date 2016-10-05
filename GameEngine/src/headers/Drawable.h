#pragma once
#include <SFML\Window.hpp>

namespace E2D {

	class Drawable {

	public:
		Drawable() : enabled(false), deleted(true) { };

		inline bool isEnabled() { return enabled; };
		inline void enable(bool _enabled) { enabled = _enabled; };

		inline bool isDeleted() { return deleted; };
		inline void setDeleted(bool _deleted) { deleted = _deleted; };

		virtual void draw(sf::Window* window) = 0;


	private:
		bool enabled;
		bool deleted;

	};

	class NullDrawable : public Drawable {

	public:
		NullDrawable() : Drawable() { };

		virtual void draw(sf::Window* window) { };

	};

}
