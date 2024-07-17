CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

TARGET = benchmark_app
SOURCES = main.cpp LSMTree.cpp SSTable.cpp BTree.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
