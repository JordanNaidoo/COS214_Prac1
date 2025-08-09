# sudo apt install valgrind 
# valgrind --leak-check=full ./demo

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS =

# Source files (all .cpp files in the project)
SOURCES = DemoMain.cpp \
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


# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
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

# Executable name
TARGET = demo

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Phony targets
.PHONY: all run clean rebuild
