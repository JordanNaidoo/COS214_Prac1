#ifndef SHAPE_H
#define SHAPE_H

class Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;

public:
	virtual Shape* clone() = 0;
};

#endif
