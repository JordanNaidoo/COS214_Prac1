#include "Textbox.h"

Textbox::Textbox(int length, int width, string colour, int position_x, int position_y, string text) : Shape(length, width, colour, position_x, position_y)
{
	this->text = text;
    std::cout << "Textbox created with text: " << text << std::endl;
}

Shape *Textbox::clone()
{
    std::cout << "You have made a copy of a Textbox" << std::endl;
    return new Textbox(*this);
}
