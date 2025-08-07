#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "Canvas.h"

class ExportCanvas{
	private:
		virtual void prepareCanvas()=0;
		virtual void renderElements()=0;
		virtual void saveToFile() = 0;
	protected:
		Canvas* canvas;	

	public:
		ExportCanvas(Canvas* c);
		~ExportCanvas(){
			if (canvas) {
				delete canvas;
				canvas = nullptr;
			}
		};
		void exportToFile();
};

#endif
