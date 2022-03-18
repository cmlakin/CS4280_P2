#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o testScanner.o scanner.o
TARGET = P1

scanner: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o scanner

main.o: main.cpp testScanner.h scanner.h token.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: testScanner.cpp testScanner.h
	$(CC) $(CFLAGS) -c testScanner.cpp

clean:
	rm *.o P1
