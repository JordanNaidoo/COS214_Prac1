#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas {
	private:
		void prepareCanvas() override;
		void renderElements() override;
		void saveToFile() override;

	public:
		PDFExporter(Canvas* c) : ExportCanvas(c) {};
};

#endif
