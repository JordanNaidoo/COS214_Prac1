#ifndef MEMENTO_H
#define MEMENTO_H
#include "Shape.h"

class Memento {

private:
	Shape* shapes;
	friend class Canvas;

public:
	Memento() {}
	virtual ~Memento() {}
	Memento(Shape* elements);
};

#endif
