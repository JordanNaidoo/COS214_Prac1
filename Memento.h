#ifndef MEMENTO_H
#define MEMENTO_H
#include "Shape.h"
#include "Canvas.h"
#include <vector>

class Canvas;
class Memento {

	private:
		std::vector<Shape*> shapes;
		friend class Canvas;
		Memento(std::vector<Shape*> elements);

	public:
		Memento() {}
		virtual ~Memento() {}
};

#endif
