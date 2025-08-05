#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

class SquareFactory : ShapeFactory {


public:
	Shape* createShape();

	void toString();
};

#endif
