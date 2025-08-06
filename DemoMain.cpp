#include <iostream>
#include <vector>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
#include "Canvas.h"
#include "Memento.h"
#include "Caretaker.h"

//to do
// - export option --> png or pdf

Canvas* canvas; // Canvas instance to manage shapes
Caretaker* caretaker; // Caretaker to manage mementos

void displayMenu() {
    std::cout << "\n=== OpenCanvas Operations ===" << std::endl;
    std::cout << "1. Add Shape" << std::endl;
    std::cout << "2. Undo" << std::endl;
    std::cout << "3. Export Canvas" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice (1-4): ";
}

void displayShapeMenu() {
    std::cout << "\n=== Choose Shape Type ===" << std::endl;
    std::cout << "1. Rectangle" << std::endl;
    std::cout << "2. Square" << std::endl;
    std::cout << "3. Textbox" << std::endl;
    std::cout << "Enter your choice (1-3): ";
}

void displayShapeDetails(Shape* shape, const std::string& shapeType) {
    std::cout << "\n=== Current " << shapeType << " Details ===" << std::endl;
    std::cout << "1. Length: " << shape->getLength() << std::endl;
    std::cout << "2. Width: " << shape->getWidth() << std::endl;
    std::cout << "3. Colour: " << shape->getColour() << std::endl;
    std::cout << "4. Position X: " << shape->getPositionX() << std::endl;
    std::cout << "5. Position Y: " << shape->getPositionY() << std::endl;
    
    // Special case for Textbox - show text option
    if (shapeType == "Textbox") {
        Textbox* textbox = dynamic_cast<Textbox*>(shape);
        if (textbox) {
            std::cout << "6. Text: " << textbox->getText() << std::endl;
            std::cout << "7. Finish editing" << std::endl;
            std::cout << "Enter which attribute to change (1-7): ";
        }
    } else {
        std::cout << "6. Finish editing" << std::endl;
        std::cout << "Enter which attribute to change (1-6): ";
    }
}

void editShapeAttribute(Shape* shape, int choice, const std::string& shapeType) {
    switch(choice) {
        case 1: {
            int newLength;
            std::cout << "Enter new length: ";
            std::cin >> newLength;
            shape->setLength(newLength);
            std::cout << "Length updated to " << newLength << std::endl;
            break;
        }
        case 2: {
            int newWidth;
            std::cout << "Enter new width: ";
            std::cin >> newWidth;
            shape->setWidth(newWidth);
            std::cout << "Width updated to " << newWidth << std::endl;
            break;
        }
        case 3: {
            std::string newColour;
            std::cout << "Enter new colour: ";
            std::cin >> newColour;
            shape->setColour(newColour);
            std::cout << "Colour updated to " << newColour << std::endl;
            break;
        }
        case 4: {
            int newX;
            std::cout << "Enter new X position: ";
            std::cin >> newX;
            shape->setPositionX(newX);
            std::cout << "X position updated to " << newX << std::endl;
            break;
        }
        case 5: {
            int newY;
            std::cout << "Enter new Y position: ";
            std::cin >> newY;
            shape->setPositionY(newY);
            std::cout << "Y position updated to " << newY << std::endl;
            break;
        }
        case 6: {
            // Special case for Textbox text editing
            if (shapeType == "Textbox") {
                Textbox* textbox = dynamic_cast<Textbox*>(shape);
                if (textbox) {
                    std::string newText;
                    std::cout << "Enter new text: ";
                    std::cin.ignore(); // Clear the newline from previous input
                    std::getline(std::cin, newText); // Allow spaces in text
                    textbox->setText(newText);
                    std::cout << "Text updated to: " << newText << std::endl;
                }
            }
            break;
        }
    }
}

Shape* createShape(int shapeChoice) {
    Shape* newShape = nullptr;
    
    switch(shapeChoice) {
        case 1: {
            RectangleFactory* factory = new RectangleFactory();
            factory->toString(); // Print creating message
            newShape = factory->createShape();
            delete factory;
            break;
        }
        case 2: {
            SquareFactory* factory = new SquareFactory();
            factory->toString(); // Print creating message
            newShape = factory->createShape();
            delete factory;
            break;
        }
        case 3: {
            TextboxFactory* factory = new TextboxFactory();
            factory->toString(); // Print creating message
            newShape = factory->createShape();
            delete factory;
            break;
        }
        default:
            std::cout << "Invalid shape choice!" << std::endl;
    }
    
    return newShape;
}

void addShape() {
    Memento* currentState = canvas->captureCurrent();
    caretaker->storeMemento(currentState);
    
    displayShapeMenu();
    int shapeChoice;
    std::cin >> shapeChoice;
    
    if (shapeChoice < 1 || shapeChoice > 3) {
        std::cout << "Invalid choice! Please try again." << std::endl;
        return;
    }
    
    Shape* newShape = createShape(shapeChoice);
    if (!newShape) {
        std::cout << "Failed to create shape!" << std::endl;
        return;
    }
    
    std::string shapeTypes[] = {"Rectangle", "Square", "Textbox"};
    std::string currentShapeType = shapeTypes[shapeChoice - 1];
    
    // Add shape to canvas using Canvas class method
    bool success = canvas->addShape(newShape);
    if (success) {
        std::cout << currentShapeType << " added to canvas!" << std::endl;
    } else {
        std::cout << "Failed to add " << currentShapeType << " to canvas!" << std::endl;
        delete newShape;
        return;
    }
    
    // Ask if user wants to edit details
    char editChoice;
    std::cout << "Would you like to edit the details of this " << currentShapeType << "? (y/n): ";
    std::cin >> editChoice;
    
    if (editChoice == 'y' || editChoice == 'Y') {
        int attributeChoice;
        int maxChoice = (currentShapeType == "Textbox") ? 7 : 6;
        int editMaxChoice = (currentShapeType == "Textbox") ? 6 : 5;
        
        do {
            displayShapeDetails(newShape, currentShapeType);
            std::cin >> attributeChoice;
            
            if (attributeChoice >= 1 && attributeChoice <= editMaxChoice) {
                editShapeAttribute(newShape, attributeChoice, currentShapeType);
            } else if (attributeChoice == maxChoice) {
                std::cout << "Finished editing " << currentShapeType << "." << std::endl;
                break;
            } else {
                std::cout << "Invalid choice! Please try again." << std::endl;
            }
        } while (attributeChoice != maxChoice);
    }
    
    // Show final shape
    std::cout << "\nFinal " << currentShapeType << ":" << std::endl;
    std::cout << newShape->render() << std::endl;
}

void undoLastAction() {
    // Ask caretaker for the most recent memento
    Memento* lastState = caretaker->retrieveMemento();
    
    if (!lastState) {
        std::cout << "No actions to undo!" << std::endl;
        return;
    }
    
    // Tell canvas to undo using the memento
    canvas->undoAction(lastState);
    std::cout << "Last action undone." << std::endl;
}

void exportCanvas() {
    std::cout << "\n=== Canvas Export ===" << std::endl;
    std::cout << "Canvas export functionality will display all shapes." << std::endl;
    std::cout << "Note: Canvas contents cannot be displayed directly with current Canvas implementation." << std::endl;
    std::cout << "Consider adding a displayCanvas() method to the Canvas class for full export functionality." << std::endl;
    
    // Future implementation for PNG/PDF export
    std::cout << "Export formats (PNG/PDF) will be implemented in future versions." << std::endl;
}

int main()
{
    std::cout << "Welcome to OpenCanvas!" << std::endl;
    
    // Initialize canvas and caretaker
    canvas = new Canvas();
    caretaker = new Caretaker();
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addShape();
                break;
            case 2:
                undoLastAction();
                break;
            case 3:
                exportCanvas();
                break;
            case 4:
                std::cout << "Thank you for using OpenCanvas! Goodbye!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1-4." << std::endl;
        }
    }
    
    // Clean up memory
    delete canvas; // Canvas destructor will clean up all shapes
    delete caretaker; // Caretaker destructor will clean up all mementos
    
    return 0;
}

