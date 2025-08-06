#include "TextboxFactory.h"

Shape* TextboxFactory::createShape() {
	std::cout << "A Textbox was created" << std::endl;
	return new Textbox; 
}

void TextboxFactory::toString() {
	std::cout << "TextboxFactory: Creating a Textbox..." << std::endl;
}
