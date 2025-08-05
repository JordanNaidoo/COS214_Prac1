#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "ShapeFactory.h"

class Textbox : public Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;
	string text;

public:
	Textbox(int length, int width, string colour, int position_x, int position_y, string text);
	Shape* clone();
};

#endif
