#include <iostream>
#include "Canvas.h"
#include "Caretaker.h"
#include "Shape.h"
#include "Memento.h"
#include "Rectangle.h" 
#include "Square.h" 
using namespace std;

int main()
{

    //Memento testing: //////////////////////////////////////////////////
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

    return 0;
}