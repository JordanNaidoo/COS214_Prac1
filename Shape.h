#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;

public:
	Shape() {};
	virtual ~Shape() {};
	virtual std::string toString() const = 0;

	Shape(int length, int width, string colour, int position_x, int position_y)
	{
		this->length = length;
		this->width = width;
		this->colour = colour;
		this->position_x = position_x;
		this->position_y = position_y;
	}

	virtual Shape *clone() = 0;
	virtual std::string render() = 0;

	void setLength(int length)
	{
		this->length = length;
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	void setColour(string colour)
	{
		this->colour = colour;
	}

	void setPositionX(int position_x)
	{
		this->position_x = position_x;
	}

	void setPositionY(int position_y)
	{
		this->position_y = position_y;
	}

	int getLength() const
	{
		return length;
	}
	int getWidth() const
	{
		return width;
	}
	string getColour() const
	{
		return colour;
	}
	int getPositionX() const
	{
		return position_x;
	}
	int getPositionY() const
	{
		return position_y;
	}
};

#endif
