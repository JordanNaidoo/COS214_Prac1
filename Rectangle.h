#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape {

private:
	int length;
	int width;
	std::string colour;
	int position_x;
	int position_y;

public:
	Rectangle(int length, int width, string colour, int position_x, int position_y);
	Shape* clone();
};

#endif
