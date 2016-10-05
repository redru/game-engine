#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Drawable.h"

namespace E2D {

	class CentralObjectStorage {

	public:
		inline void addDrawable(Drawable& drawable);

	private:
		std::vector<E2D::Drawable*> drawables;

		// SINGLETON ---------------------------------------------------------------------------------
	public:
		~CentralObjectStorage() {
			for (std::vector<E2D::Drawable*>::iterator it = drawables.begin(); it < drawables.end(); it++) {
				if (*it != nullptr)
					delete *it;
			}
		};

	public:
		static std::shared_ptr<E2D::CentralObjectStorage> getInstance() {
			static std::shared_ptr<E2D::CentralObjectStorage> instance(new E2D::CentralObjectStorage);
			return instance;
		}

	private:
		CentralObjectStorage() { };

	};

}
