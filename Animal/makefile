# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11
# Source files
SOURCES := main.cpp animal.cpp bear.cpp dog.cpp cat.cpp cow.cpp horse.cpp zoo.cpp
# Object files derived from source files
OBJECTS := $(SOURCES:.cpp=.o)
# Header files
HEADERS := animal.hpp bear.hpp dog.hpp cat.hpp cow.hpp horse.hpp zoo.hpp
# Executable name
EXECUTABLE := animal

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
