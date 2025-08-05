#include "Rectangle.h"

Rectangle::Rectangle(int length, int width, string colour, int position_x, int position_y) : Shape(length, width, colour, position_x, position_y)
{
    std::cout << "Rectangle created" << std::endl;
}

Shape *Rectangle::clone()
{
    std::cout << "You have made a copy of a Rectangle" << std::endl;
    return new Rectangle(*this);
}
