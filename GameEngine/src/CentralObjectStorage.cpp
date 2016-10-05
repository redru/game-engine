#include "headers\CentralObjectStorage.h"

void E2D::CentralObjectStorage::addDrawable(Drawable& drawable) {
	for (std::vector<E2D::Drawable*>::iterator it = drawables.begin(); it < drawables.end(); it++) {
		E2D::Drawable*& tmp(*it);

		if (tmp == nullptr) {
			*tmp = drawable;
			break;
		}
	}
}
