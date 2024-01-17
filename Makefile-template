# Makefile for a simple C++ project

# The C++ compiler to use
CXX = g++

# Compiler flags, e.g., -std=c++11 for C++11 standards
CXXFLAGS = 

# Directory for header files
INCDIR = ./include

# Directory for object files
SRCDIR = ./src

# Directory for executables
BINDIR = ./bin

# The final executable name
TARGET = $(BINDIR)/LinearRegression

# Automatically find all CPP files in the src directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Replace .cpp from SOURCES with .o to get OBJECTS
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)

# Rule for making the final executable
# Depends on all object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $(TARGET) $(OBJECTS)

# Rule for making object files
# Each .o file depends on its corresponding .cpp file
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean rule
# Removes all object files and the final executable
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

# Declare 'clean' as a phony target to avoid confusion with any file of the same name
.PHONY: clean