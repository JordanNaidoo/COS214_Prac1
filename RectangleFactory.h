#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "ShapeFactory.h"
#include "Rectangle.h"

class RectangleFactory : public ShapeFactory {

	public:
		Shape* createShape();

		void toString();
};

#endif
