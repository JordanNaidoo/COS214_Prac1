#include "Square.h"

Square::Square(int sidesize, string colour, int position_x, int position_y) : Shape(sidesize, sidesize, colour, position_x, position_y)
{
}

Shape *Square::clone()
{
    return new Square(*this);
}
