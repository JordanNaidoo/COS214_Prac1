#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape {

public:
	Rectangle();
	Rectangle(int length, int width, string colour, int position_x, int position_y);
	std::string toString() const override;
	Shape* clone();
	std::string render();
};

#endif
