# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Output directory
OUT_DIR = out

# All cpp source files
SRCS = $(wildcard *.cpp)

# Generate list of targets: out/eg0_array out/eg1_pointer ...
TARGETS = $(patsubst %.cpp,$(OUT_DIR)/%,$(SRCS))

# Default target
all: $(TARGETS)

# Build rule: compile each .cpp into its own executable in out/
$(OUT_DIR)/%: %.cpp
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up build files
clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
