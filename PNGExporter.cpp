#include "PNGExporter.h"
using namespace std;

PNGExporter::PNGExporter(Canvas* c) : ExportCanvas(c) {}

void PNGExporter::prepareCanvas() {
    cout << "Preparing canvas for PNG export..." << endl;
}   

void PNGExporter::renderElements() {
    cout << "Rendering elements for PNG export..." <<endl;
}

void PNGExporter::saveToFile() {
    // cout<<"Where would you like to save the PNG file?"<<endl;
    string where = "Downloads";
    // cin >> where;
    cout << "Saving PNG file to " << where <<"..." << endl;
    cout<<"PNG file saved to "<<where<<endl;
}