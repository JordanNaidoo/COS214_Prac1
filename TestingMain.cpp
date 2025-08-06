#include <iostream>
using namespace std;

#include "Canvas.h"
#include "Caretaker.h"
#include "Shape.h"
#include "Memento.h"
#include "Rectangle.h"
#include "Square.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
#include "Textbox.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"

void testShapeCreation()
{
    Rectangle *temp = new Rectangle;
    temp->setColour("green");
    temp->setLength(10);
    temp->setWidth(3);
    temp->setPositionX(5);
    temp->setPositionY(200);
    std::cout << temp->render() << std::endl;
    std::cout << temp->toString() << std::endl;

    Textbox *temp2 = new Textbox;
    temp2->setColour("green");
    temp2->setLength(10);
    temp2->setWidth(3);
    temp2->setText("Hello World");
    std::cout << temp2->render() << std::endl;
    std::cout << temp2->toString() << std::endl;
}
void testShapeFactory()
{
    std::cout << "=== Factory Pattern Testing ===" << std::endl;
    std::cout << std::endl;

    std::cout << "1. Testing Rectangle Factory:" << std::endl;
    RectangleFactory *rectFactory = new RectangleFactory();
    rectFactory->toString();
    Shape *rectangle = rectFactory->createShape();
    if (rectangle)
    {
        rectangle->setColour("red");
        rectangle->setLength(10);
        rectangle->setWidth(5);
        rectangle->setPositionX(0);
        rectangle->setPositionY(0);
        std::cout << "Rectangle created: \n"
                  << rectangle->render() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "2. Testing Square Factory:" << std::endl;
    SquareFactory *squareFactory = new SquareFactory();
    squareFactory->toString();
    Shape *square = squareFactory->createShape();
    if (square)
    {
        square->setColour("blue");
        square->setLength(7);
        square->setWidth(7);
        square->setPositionX(10);
        square->setPositionY(10);
        std::cout << "Square created: \n"
                  << square->render() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "3. Testing Textbox Factory:" << std::endl;
    TextboxFactory *textboxFactory = new TextboxFactory();
    textboxFactory->toString();
    Shape *textbox = textboxFactory->createShape();
    if (textbox)
    {
        textbox->setColour("green");
        textbox->setLength(15);
        textbox->setWidth(3);
        textbox->setPositionX(20);
        textbox->setPositionY(5);
        std::cout << "Textbox created: \n"
                  << textbox->render() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "4. Testing Factory Pattern Polymorphism:" << std::endl;

    std::cout << "Testing RectangleFactory through polymorphism: ";
    RectangleFactory *polyFactory1 = new RectangleFactory();
    polyFactory1->toString();
    Shape *polyShape1 = polyFactory1->createShape();
    if (polyShape1)
    {
        polyShape1->setColour("orange");
        polyShape1->setLength(6);
        polyShape1->setWidth(6);
        std::cout << "Shape created: \n"
                  << polyShape1->render() << std::endl;
        delete polyShape1;
    }
    delete polyFactory1;

    std::cout << "Testing SquareFactory through polymorphism: ";
    SquareFactory *polyFactory2 = new SquareFactory();
    polyFactory2->toString();
    Shape *polyShape2 = polyFactory2->createShape();
    if (polyShape2)
    {
        polyShape2->setColour("pink");
        polyShape2->setLength(4);
        polyShape2->setWidth(4);
        std::cout << "Shape created: \n"
                  << polyShape2->render() << std::endl;
        delete polyShape2;
    }
    delete polyFactory2;

    std::cout << "Testing TextboxFactory through polymorphism: ";
    TextboxFactory *polyFactory3 = new TextboxFactory();
    polyFactory3->toString();
    Shape *polyShape3 = polyFactory3->createShape();
    if (polyShape3)
    {
        polyShape3->setColour("cyan");
        polyShape3->setLength(12);
        polyShape3->setWidth(2);
        std::cout << "Shape created: \n"
                  << polyShape3->render() << std::endl;
        delete polyShape3;
    }
    delete polyFactory3;
    std::cout << std::endl;

    std::cout << "5. Testing Clone functionality:" << std::endl;
    Shape *originalRect = rectFactory->createShape();
    if (originalRect)
    {
        originalRect->setColour("purple");
        originalRect->setLength(8);
        originalRect->setWidth(4);
        std::cout << "Original: \n"
                  << originalRect->render() << std::endl;

        Shape *clonedRect = originalRect->clone();
        // change details of the cloned rectangle
        if (clonedRect)
        {
            std::cout << "Cloned: \n"
                      << clonedRect->render() << std::endl;
            clonedRect->setColour("yellow");
            clonedRect->setLength(5);
            std::cout << "Changed details of the cloned rectangle: \n"
                      << clonedRect->render() << std::endl;
            delete clonedRect;
        }
        delete originalRect;
    }
    std::cout << std::endl;

    delete rectangle;
    delete square;
    delete textbox;
    delete rectFactory;
    delete squareFactory;
    delete textboxFactory;

    std::cout << "=== Factory Testing Complete ===" << std::endl;
}

void mementotest()
{
    testShapeFactory();
}
void test2()
{

    // Memento testing: //////////////////////////////////////////////////
    Canvas canvas;
    Caretaker caretaker;

    canvas.addShape(new Rectangle(10, 20, "red", 0, 0));
    caretaker.storeMemento(canvas.captureCurrent());
    cout << "Shapes after first add: " << canvas.getShapeCount() << endl;

    // Add second shape and save state
    canvas.addShape(new Square(30, "blue", 5, 5));
    caretaker.storeMemento(canvas.captureCurrent());
    cout << "Shapes after second add: " << canvas.getShapeCount() << endl;

    // Add third shape and save state
    canvas.addShape(new Rectangle(15, 25, "green", 2, 2));
    caretaker.storeMemento(canvas.captureCurrent());
    cout << "Shapes after third add: " << canvas.getShapeCount() << endl;

    // Undo to previous state (should remove last shape)
    canvas.undoAction(caretaker.retrieveMemento());
    cout << "Shapes after first undo: " << canvas.getShapeCount() << endl;

    // Undo again (should remove second shape)
    canvas.undoAction(caretaker.retrieveMemento());
    cout << "Shapes after second undo: " << canvas.getShapeCount() << endl;

    // Undo again (should remove first shape, back to empty)
    canvas.undoAction(caretaker.retrieveMemento());
    cout << "Shapes after third undo: " << canvas.getShapeCount() << endl;

    cout << "Memento pattern extensive test complete." << endl;
}

void exportTest()
{
    Canvas exportCanvas;
    exportCanvas.addShape(new Rectangle(10, 20, "red", 0, 0));
    exportCanvas.addShape(new Square(30, "blue", 5, 5));

    // Export to PDF
    PDFExporter pdfExporter(&exportCanvas);
    pdfExporter.exportToFile();

    // Export to PNG
    PNGExporter pngExporter(&exportCanvas);
    pngExporter.exportToFile();
}

int main()
{
    // exportTest();
    testShapeCreation();

}
