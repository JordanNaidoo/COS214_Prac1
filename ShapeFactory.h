#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include <iostream>

class ShapeFactory {
	protected:
		virtual Shape* createShape() = 0;
	
		virtual void toString() = 0;
	public:
		virtual ~ShapeFactory() {}
	};

#endif
