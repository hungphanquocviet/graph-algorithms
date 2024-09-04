CC = g++
CFLAGS = -g

dfsr: clean dfs
	./dfs

gen: clean generator
	./generator
	
dfs: clean dfs.o graph.o
	$(CC) $(CFLAGS) -std=c++2a -o dfs dfs.o graph.o

dfs.o: src/dfs.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/dfs.cpp

graph.o: src/graph.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/graph.cpp

generator: clean
	$(CC) $(CFLAGS) -std=c++2a -o generator utils/generator.cpp

clean:
	rm -f generator dfs *.o