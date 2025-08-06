#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "Canvas.h"

class ExportCanvas{
	private:
		Canvas *canvas;
		virtual void prepareCanvas()=0;
		virtual void renderElements()=0;
		virtual void saveToFile() = 0;

	public:
		ExportCanvas(Canvas* c);
		~ExportCanvas(){};
		void exportToFile();
};

#endif
