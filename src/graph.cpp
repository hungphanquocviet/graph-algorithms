#include "graph.h"

Graph::Graph(int n) : n(n), adjList(n+1), inDegree(n+1, 0) {}

void Graph::addEdge(vector<int> src, vector<int> dst, vector<int> weight) {

}

vector<int> Graph::getNeighborsWithoutWeight(int source) {

}

vector<pair<int, int>> Graph::getNeighborsWithWeight(int source) {

}

int Graph::getInDegree(int node) {

}

void Graph::increaseInDegree(int node) {

}

void Graph::decreaseInDegree(int node) {

}