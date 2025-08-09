# sudo apt install valgrind 
# valgrind --leak-check=full ./demo

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS =

SOURCES = TestingMain.cpp \
          Rectangle.cpp \
          RectangleFactory.cpp \
          Square.cpp \
          SquareFactory.cpp \
          Textbox.cpp \
          TextboxFactory.cpp \
          Canvas.cpp \
          Memento.cpp \
          Caretaker.cpp \
          ExportCanvas.cpp \
          PNGExporter.cpp \
          PDFExporter.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = Canvas.h \
          Caretaker.h \
          ExportCanvas.h \
          Memento.h \
          PNGExporter.h \
          Rectangle.h \
          RectangleFactory.h \
          Shape.h \
          ShapeFactory.h \
          Square.h \
          SquareFactory.h \
          Textbox.h \
          TextboxFactory.h

TARGET = demo

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild
