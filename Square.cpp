#include "Square.h"

Square::Square()
{
    length = 2;
    width = 2;
    colour = "red";
    position_x = 0;
    position_y = 0;
}

Square::Square(int sidesize, string colour, int position_x, int position_y) : Shape(sidesize, sidesize, colour, position_x, position_y)
{
    std::cout << "Square created" << std::endl;
}

Shape *Square::clone()
{
    std::cout << "You have made a copy of a Square" << std::endl;
    return new Square(*this);
}

std::string Square::render()
{
    std::string output = "";
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length * 2); j++)
            output += "░";
        output += "\n";
    }
    return output;
}

std::string Square::toString() const
{
    return "Shape type: Square, length:" + std::to_string(length) +
           ", Colour: " + colour + ", Position: (" + std::to_string(position_x) + ", " + std::to_string(position_y) + ")";
}
