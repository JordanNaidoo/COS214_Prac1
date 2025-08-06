#include "RectangleFactory.h"

Shape* RectangleFactory::createShape() {
	std::cout << "A Rectangle was created" << std::endl;
	return new Rectangle;
}

void RectangleFactory::toString() {
	std::cout << "RectangleFactory: Creating a Rectangle" << std::endl;
}
