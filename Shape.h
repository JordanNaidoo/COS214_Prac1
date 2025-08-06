#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape {
	protected:
		int length;
		int width;
		string colour;
		int position_x;
		int position_y;

	public:
		Shape(){};
		virtual ~Shape(){};
		Shape(int length, int width, string colour, int position_x, int position_y) {
			this->length = length;
			this->width = width;
			this->colour = colour;
			this->position_x = position_x;
			this->position_y = position_y;
		}

		virtual Shape* clone() = 0;
		virtual std::string render() = 0;
	
		void setLength(int length) {
			this->length = length;
		}
		
		void setWidth(int width) {
			this->width = width;
		}
		
		void setColour(string colour) {
			this->colour = colour;
		}
		
		void setPositionX(int position_x) {
			this->position_x = position_x;
		}
		
		void setPositionY(int position_y) {
			this->position_y = position_y;
		}
		
};

#endif
