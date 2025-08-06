#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "ShapeFactory.h"

class Textbox : public Shape {

private:
	string text;

public:
	Textbox();
	Textbox(int length, int width, string colour, int position_x, int position_y, string text);
	std::string toString() const override;
	Shape* clone();
	std::string render();
	void setText(string text);
	string getText() const {
		return text;
	}
	
};

#endif
