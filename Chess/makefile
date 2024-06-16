# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11
# Source files
SOURCES := main.cpp chessBoard.cpp Figures/sources/figure.cpp Figures/sources/king.cpp Figures/sources/queen.cpp Figures/sources/bishop.cpp Figures/sources/knight.cpp Figures/sources/rook.cpp
# Object files derived from source files
OBJECTS := $(SOURCES:.cpp=.o)
# Header files
HEADERS := chessBoard.hpp Figures/headers/figure.hpp Figures/headers/king.hpp Figures/headers/queen.hpp Figurs/headers/bishop.hpp Figures/headers/knight.hpp Figures/headers/rook.hpp
# Executable name
EXECUTABLE := chess

.PHONY: all clean

# Default target
all: $(EXECUTABLE)

# Build rule for the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build rule for object files with explicit dependencies on header files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(EXECUTABLE)

# Include dependency files
-include $(SOURCES:.cpp=.d)
