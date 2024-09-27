CC = g++
CFLAGS = -g -std=c++14 -fsanitize=undefined -fsanitize=address -fsanitize=leak

# File Path
GOOGLETEST ?= ../googletest
GOOGLETESTLIB = $(GOOGLETEST)/lib
GOOGLETESTINC = $(GOOGLETEST)/googletest/include
GOOGLETESTGTEST = $(GOOGLETEST)/googletest/include/gtest

test : clean toposortTests 
	./toposortTests

toposort.o : toposort.cpp toposort.h 
	$(CC) $(CFLAGS) -c toposort.cpp

toposortTests.o : toposort.cpp $(GOOGLETESTGTEST)/gtest.h 
	$(CC) $(CFLAGS) -I$(GOOGLETESTGTEST) -I$(GOOGLETESTINC) -c toposortTests.cpp

toposortTests : toposort.o toposortTests.o
	$(CC) $(CFLAGS) -L$(GOOGLETESTLIB) -o toposortTests toposortTests.o toposort.o -lgtest -lgtest_main
	
clean :
	rm -f toposort toposortTests *.o