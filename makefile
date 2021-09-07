CXX = c++
CXXFLAGS = -O3 -Wall
INCLUDE = -I $(shell find . -name "*.hpp")
SOURCES = $(shell find . -name "*.cpp")
OBJ = $(SOURCES:.cpp=.o)
TARGET = superfood

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJ) -o $@

clean:
	rm -rf **/*.o

