#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;

public:
	Shape* clone();
};

#endif
