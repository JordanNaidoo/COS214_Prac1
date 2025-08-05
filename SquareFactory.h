#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"

class SquareFactory : public ShapeFactory {


public:
	Shape* createShape();
	void toString();
};

#endif
