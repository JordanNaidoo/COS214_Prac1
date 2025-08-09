#include "PDFExporter.h"
using namespace std;

PDFExporter::PDFExporter(Canvas* c) : ExportCanvas(c) {}

void PDFExporter::prepareCanvas() {

    cout << "Preparing canvas for PDF export..." << endl;
}   

void PDFExporter::renderElements() {
   
    cout << "Rendering elements for PDF export..." <<endl;
}

void PDFExporter::saveToFile() {
    
    cout<<"Where would you like to save the PDF file?"<<endl;
    string where;
    cin >> where;
    cout << "Saving PDF file to " << where << "..." << endl;
    cout<<"PDF file saved to "<<where<<endl;
}
