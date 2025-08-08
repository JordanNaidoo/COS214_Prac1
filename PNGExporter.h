#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas {
	private:
		void prepareCanvas() override;
		void renderElements() override;
		void saveToFile() override;
	public:
		PNGExporter(Canvas* c);
		~PNGExporter(){};
};

#endif
