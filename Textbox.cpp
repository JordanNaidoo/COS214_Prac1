#include "Textbox.h"

Textbox::Textbox()
{
    length = 4;
    width = 2;
    colour = "white";
    position_x = 0;
    position_y = 0;
    text = "Enter text here";
}

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

std::string Textbox::render()
{
    std::string output = "";
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < (length*2) ; j++)
            output += "░";
        output += "\n";
    }
    return output + toString() + "\n";
}

void Textbox::setText(string text)
{
    this->text = text;
}

std::string Textbox::toString() const
{
    return "Shape type: Textbox, length:" + std::to_string(length) + ", width:" + std::to_string(width) +
           ", Colour: " + colour + ", Position: (" + std::to_string(position_x) + ", " + std::to_string(position_y) + ") Text: " + ((text!="Enter text here" )? text:"*empty*");
}

