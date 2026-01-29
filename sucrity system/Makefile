# Makefile for Security System Project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OUTPUT_DIR = output
EXECUTABLE = $(OUTPUT_DIR)/security_system

# Source files
SOURCES = main.cpp LoginCheck.cpp Info.cpp Administrator.cpp
HEADERS = LoginCheck.hpp Info.hpp Administrator.hpp

# Object files (generated from source files)
OBJECTS = $(addprefix $(OUTPUT_DIR)/, $(SOURCES:.cpp=.o))

# Default target
all: $(EXECUTABLE)

# Link the executable
$(EXECUTABLE): $(OBJECTS) | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete: $(EXECUTABLE)"

# Compile source files to object files
$(OUTPUT_DIR)/%.o: %.cpp $(HEADERS) | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create output directory if it doesn't exist
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean build artifacts
clean:
	rm -rf $(OUTPUT_DIR)

# Rebuild everything
rebuild: clean all

# Phony targets (not file-based)
.PHONY: all run clean rebuild
