CFLAGS = -g -Wall
CC = g++


compile: main.o Sorting.o
	$(CC) $(CFLAGS) -o main main.o Sorting.o

DoublyLinkedList:Sorting.o
	$(CC) $(CFLAGS) -c Sorting.cpp

main:main.o
	$(CC) $(CFLAGS) -c main.cpp

clean:
	-rm -f a.out *.o core atest
	-rm -f *.class
	-rm -f main 