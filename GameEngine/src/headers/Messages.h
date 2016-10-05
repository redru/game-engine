#pragma once

namespace E2D {

	namespace MESSAGES {
		const unsigned short int COLOR_CHANGE = 0x00;
		const unsigned short int KEY_RELEASED = 0x01;
	}

	class Message {
	
	public:
		Message(unsigned short int _type) : type(_type) { };
		inline unsigned short int getType() { return type; };

	private:
		unsigned short int type;
	
	};

	class ColorChangeMessage : public Message {

	public:
		ColorChangeMessage(unsigned short int _r, unsigned short int _g, unsigned short int _b, unsigned short int _a) : r(_r), g(_g), b(_b), a(_a), Message(MESSAGES::COLOR_CHANGE) { };

		unsigned short int r;
		unsigned short int g;
		unsigned short int b;
		unsigned short int a;

	};

	class KeyReleasedMessage : public Message {

	public:
		KeyReleasedMessage(std::vector<sf::Keyboard::Key> _keys) : keys(_keys), Message(MESSAGES::KEY_RELEASED) { };

		std::vector<sf::Keyboard::Key> keys;

	};

}
