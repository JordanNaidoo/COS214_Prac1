#include "Canvas.h"
#include "Shape.h"
#include "Memento.h"

Canvas::Canvas() {}

Canvas::~Canvas() {
	for (Shape* s : shapes)
		delete s;
	shapes.clear();
}

bool Canvas::addShape(Shape* shape) {
	if (shape) {
		shapes.push_back(shape);  
		return true;
	}
	return false;
}

Memento* Canvas::captureCurrent() {
	return new Memento(shapes);
}

void Canvas::undoAction(Memento* prev) {
	if (prev) {
		for (Shape* s : shapes) delete s; 
		shapes.clear(); 

		for (Shape* s : prev->shapes) {
			if (s) 
				shapes.push_back(s->clone()); 	
		}
		delete prev; 
	}
}
