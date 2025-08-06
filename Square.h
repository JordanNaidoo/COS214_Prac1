#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {

public:
	Square();
	Square(int sidesize, string colour, int position_x, int position_y);
	std::string toString() const override;
	Shape* clone();
	std::string render();
};

#endif
