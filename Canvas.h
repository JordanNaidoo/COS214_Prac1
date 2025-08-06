#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"
#include <vector>

class Canvas {

	private:
		std::vector<Shape*> shapes;
	public:
		Canvas();
		~Canvas();
		Memento* captureCurrent(); //create memento
		bool addShape(Shape* shape);
		void undoAction(Memento* prev); //set memento
		int getShapeCount() const; 
};

#endif
