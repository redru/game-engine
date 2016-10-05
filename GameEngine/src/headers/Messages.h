#pragma once

namespace E2D {

	class Message { };

	class ColorChangeMessage : public Message {

	public:
		ColorChangeMessage(unsigned short int _r, unsigned short int _g, unsigned short int _b, unsigned short int _a) : r(_r), g(_g), b(_b), a(_a) { };

		unsigned short int r;
		unsigned short int g;
		unsigned short int b;
		unsigned short int a;
		

	};

}
