#include "Canvas.h"


Canvas::Canvas() {}

Canvas::~Canvas() {
	for (Shape* s : shapes)
		delete s;
	shapes.clear();
}

int Canvas::getShapeCount() const {
	return shapes.size();
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

std::string Canvas::toString() const {
	if (shapes.empty()) return "Canvas is empty."; 
	std::string output = "Canvas contains:\n";
	for (const Shape* s : shapes) {
		output += "- " + s->toString() + "\n";
	}
	return output;
}
