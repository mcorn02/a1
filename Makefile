#Team Names: Michael Corn and Simmon Quan

#Edoras Usernames: cssc1415 and cssc1450

#Class Info: CS 480 Operating Systems, Summer Session 2 2025

#Assignment #1: Concurrent Thread Chatbots

#File Name: README
	

CXX = g++
CXXFLAGS = -Wall -std=c++11 -pthread
TARGET = bots

all: $(TARGET)

$(TARGET): bots.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) bots.cpp

clean:
	rm -f $(TARGET) QUOTE.txt
