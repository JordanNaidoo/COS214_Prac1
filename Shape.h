#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape {
	private:
		int length;
		int width;
		string colour;
		int position_x;
		int position_y;

	public:
		Shape(int length, int width, string colour, int position_x, int position_y) {
			this->length = length;
			this->width = width;
			this->colour = colour;
			this->position_x = position_x;
			this->position_y = position_y;
		}
		virtual Shape* clone() = 0;
};

#endif
