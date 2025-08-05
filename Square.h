#ifndef SQUARE_H
#define SQUARE_H

class Square : Shape {

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
