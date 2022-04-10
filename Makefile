#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o parser.o scanner.o treeprint.o


parser: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o parser

main.o: main.cpp parser.h scanner.h token.h treeprint.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp

parser.o: parser.cpp parser.h treeprint.h
	$(CC) $(CFLAGS) -c parser.cpp

treeprint.o: treeprint.cpp treeprint.h
	$(CC) $(CFLAGS) -c treeprint.cpp

clean:
	rm *.o parser
