#include "ExportCanvas.h"


ExportCanvas::ExportCanvas(Canvas* c){
	if (c) canvas = c;
}

void ExportCanvas::exportToFile() {
	std::cout<<"The canvas containing the following shapes will be exported:\n";
	std::cout << canvas->toString() << std::endl;
	prepareCanvas();
	renderElements();
	saveToFile();
}

