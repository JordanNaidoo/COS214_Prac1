#include "Square.h"

Square::Square(int sidesize, string colour, int position_x, int position_y) : Shape(sidesize, sidesize, colour, position_x, position_y)
{
    std::cout << "Square created" << std::endl;
}

Shape *Square::clone()
{
    std::cout << "You have made a copy of a Square" << std::endl;
    return new Square(*this);
}
