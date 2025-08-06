#include "ExportCanvas.h"


ExportCanvas::ExportCanvas(Canvas* c){
	if (canvas) canvas = c;
}

void ExportCanvas::exportToFile() {
	prepareCanvas();
	renderElements();
	saveToFile();
}

