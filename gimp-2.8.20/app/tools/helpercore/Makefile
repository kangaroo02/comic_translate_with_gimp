CC = gcc
CXX = g++

CFLAGS = -g -Wall
SRCS = main.cpp
PROG = FillTalkBoxapp

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

FillTalkBoxapp: main.o FillTalkBox.o
	$(CXX) -o FillTalkBoxapp main.o FillTalkBox.o $(LIBS)
main.o: main.c
	$(CXX) -c main.c
FillTalkBox.o: FillTalkBox.cpp FillTalkBox.h
	$(CXX) -c FillTalkBox.cpp

clear:
	rm -f *.o

