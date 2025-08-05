#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

class RectangleFactory : ShapeFactory, ShapeFactory {


public:
	Shape* createShape();

	void toString();
};

#endif
