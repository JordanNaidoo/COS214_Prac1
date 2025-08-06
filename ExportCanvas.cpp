#include "ExportCanvas.h"


ExportCanvas::ExportCanvas(Canvas* c){
	if (c) canvas = c;
}

void ExportCanvas::exportToFile() {
	prepareCanvas();
	renderElements();
	saveToFile();
}

