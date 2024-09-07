CC = g++
CFLAGS = -g

dfs: clean dfsj
	./dfs

gen: clean generator
	./generator

graph: clean graphcpp
	./graph

graphcpp: graph.o
	$(CC) $(CFLAGS) -std=c++2a -o graph graph.o

dfsj: clean dfs.o graph.o
	$(CC) $(CFLAGS) -std=c++2a -o dfs dfs.o graph.o

dfs.o: src/dfs.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/dfs.cpp

graph.o: src/graph.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/graph.cpp

generator: clean
	$(CC) $(CFLAGS) -std=c++2a -o generator utils/generator.cpp

clean:
	rm -f generator dfs graph *.o