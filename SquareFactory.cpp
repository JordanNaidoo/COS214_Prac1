#include "SquareFactory.h"

Shape* SquareFactory::createShape() {
	std::cout << "A Square was created" << std::endl;
	return new Square;
}

void SquareFactory::toString() {
	std::cout << "SquareFactory: Creating a Square" << std::endl;
}

