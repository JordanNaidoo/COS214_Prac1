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
		
		public:
		Memento(std::vector<Shape*> elements);
		virtual ~Memento() {}
};

#endif
