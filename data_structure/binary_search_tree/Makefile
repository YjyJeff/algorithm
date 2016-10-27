G++ = g++
FLAGS = -std=c++11 -g -W -I.
CC = ${G++} ${FLAGS}
all : main
main : bst.o main.o
	$(CC) -o main bst.o main.o
main.o: main.cpp
	$(CC) -c main.cpp
bst.o : bst.cpp bst.h
	$(CC) -c bst.cpp 
clean :
	rm -fr *.o main
