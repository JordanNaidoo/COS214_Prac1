#include "Textbox.h"

Textbox::Textbox(int length, int width, string colour, int position_x, int position_y, string text) : Shape(length, width, colour, position_x, position_y)
{
	this->text = text;
}

Shape *Textbox::clone()
{
    return new Textbox(*this);
}
