CXX = g++
CXXFLAGS = -Wall -std=c++11 -pthread
TARGET = bots

all: $(TARGET)

$(TARGET): bots.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) bots.cpp

clean:
	rm -f $(TARGET) QUOTE.txt
