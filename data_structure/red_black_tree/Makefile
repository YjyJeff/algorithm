G++ = g++
FLAGS = -std=c++11 -g -W -I.
CC = ${G++} ${FLAGS}
read_black_tree : main
main : RBTree.o main.o
	$(CC) -o main RBTree.o main.o
main.o: main.cpp
	$(CC) -c main.cpp
RBTree.o : RBTree.cpp RBTree.h
	$(CC) -c RBTree.cpp
clean :
	rm -fr *.o main
