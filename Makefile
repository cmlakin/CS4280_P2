#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o parser.o scanner.o


parser: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o parser

main.o: main.cpp parser.h scanner.h token.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp

parser.o: parser.cpp parser.h preorder.h
	$(CC) $(CFLAGS) -c parser.cpp

preorder.o: preorder.cpp preorder.h
	$(CC) $(CFLAGS) -c preorder.cpp

clean:
	rm *.o P1
