#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

int main()
{
    Rectangle *temp = new Rectangle;
    std::cout<<"Welcome to my youtube channel"<<std::endl;
    temp->setColour("green");
    temp->setLength(10);
    temp->setWidth(3);
    std::cout << temp->render() << std::endl;
    return 0;
}