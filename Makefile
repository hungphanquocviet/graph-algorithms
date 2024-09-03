CC = g++
CFLAGS = -g

dfsr: dfs
	./dfs

dfs: clean dfs.o graph.o
	$(CC) $(CFLAGS) -std=c++2a -o dfs dfs.o graph.o

dfs.o: src/dfs.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/dfs.cpp

graph.o: src/graph.cpp include/graph.h
	$(CC) $(CFLAGS) -c src/graph.cpp

clean:
	rm -f dfs *.o