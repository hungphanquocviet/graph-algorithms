CC = g++
CFLAGS = -g -std=c++14 -fsanitize=undefined -fsanitize=address -fsanitize=leak

# File Path
GOOGLETEST ?= ../../../../googletest
GOOGLETESTLIB = $(GOOGLETEST)/lib
GOOGLETESTINC = $(GOOGLETEST)/googletest/include
GOOGLETESTGTEST = $(GOOGLETEST)/googletest/include/gtest

test : dijkstraTests 
	./dijkstraTests

dijkstra.o : dijkstra.cpp dijkstra.h 
	$(CC) $(CFLAGS) -c dijkstra.cpp

dijkstraTests.o : dijkstraTests.cpp $(GOOGLETESTGTEST)/gtest.h 
	$(CC) $(CFLAGS) -I$(GOOGLETESTGTEST) -I$(GOOGLETESTINC) -c dijkstraTests.cpp

dijkstraTests : dijkstra.o dijkstraTests.o
	$(CC) $(CFLAGS) -L$(GOOGLETESTLIB) -o dijkstraTests dijkstraTests.o dijkstra.o -lgtest -lgtest_main


	
clean :
	rm -f dijkstra dijkstraTests *.o