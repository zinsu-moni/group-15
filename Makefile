# Makefile for Wage Calculator project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Source files
SRCS = main.cpp Employee.cpp InputValidator.cpp InputHandler.cpp WageCalculator.cpp Payslip.cpp Utils.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = WageCalculator

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean