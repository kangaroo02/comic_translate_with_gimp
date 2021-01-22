CC = gcc
CXX = g++

CFLAGS = -g -Wall
SRCS = main.cpp
PROG = FillTalkBoxapp

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)



# Find_path: Find_path.o
# 	$(CXX) -o Find_path Find_path.o


FillTalkBoxapp: main.o FillTalkBox.o
	$(CXX) -o FillTalkBoxapp main.o FillTalkBox.o $(LIBS)
main.o: main.c
	$(CXX) -c main.c
FillTalkBox.o: FillTalkBox.cpp FillTalkBox.h Find_path.cpp
	$(CXX) -c FillTalkBox.cpp

# Find_path.o: Find_path.cpp
# 	$(CXX) -c Find_path.cpp


clear:
	rm -f *.o

