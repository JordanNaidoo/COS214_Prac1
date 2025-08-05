#ifndef TEXTBOX_H
#define TEXTBOX_H

class Textbox : Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;
	string text;

public:
	Shape* clone();
};

#endif
