#include "Rectangle.h"

Rectangle::Rectangle(int length, int width, string colour, int position_x, int position_y) : Shape(length, width, colour, position_x, position_y)
{
}

Shape *Rectangle::clone()
{
    return new Rectangle(*this);
}
