#include "Memento.h"

Memento::Memento(std::vector<Shape*> elements) {
	shapes.clear(); //might rather add another function to add one thing to the vector
	for (Shape* el : elements) {
		if (el) shapes.push_back(el->clone());
	}
}

Memento::~Memento() {
	for (Shape* shp : shapes) delete shp; 
	shapes.clear(); 
}
