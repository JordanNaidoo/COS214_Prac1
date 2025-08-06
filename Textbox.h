#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "ShapeFactory.h"

class Textbox : public Shape {

private:
	string text;

public:
	Textbox();
	Textbox(int length, int width, string colour, int position_x, int position_y, string text);
	Shape* clone();
	std::string render();
	void setText(string text);
};

#endif
