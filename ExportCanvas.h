#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

class ExportCanvas {

private:
	Canvas* canvas;

public:
	void exportToFile();

private:
	void prepareCanvas();

	void renderElements();

	virtual void saveToFile() = 0;
};

#endif
