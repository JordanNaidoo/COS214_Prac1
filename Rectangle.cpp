#include "Rectangle.h"

Rectangle::Rectangle()
{
    length = 4;
    width = 2;
    colour = "blue";
    position_x = 0;
    position_y = 0;
}

Rectangle::Rectangle(int length, int width, string colour, int position_x, int position_y) : Shape(length, width, colour, position_x, position_y)
{
    std::cout << "Rectangle created" << std::endl;
}

Shape *Rectangle::clone()
{
    std::cout << "You have made a copy of a Rectangle" << std::endl;
    return new Rectangle(*this);
}

std::string Rectangle::render()
{
    std::string output = "";
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < (length*2) ; j++)
            output += "░";
        output += "\n";
    }
    return output;
}
