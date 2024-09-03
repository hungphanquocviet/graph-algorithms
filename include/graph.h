#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

/**
 * Vertices should be labeled from 0...n
 */
class Graph {
private:
    // adjList[a] = {w, b};
    vector<vector<pair<int, int>>> adjList;
    vector<int> inDegree;

public:
    void addEdge(vector<int> src, vector<int> dst, vector<int> weight);

    vector<int> getNeighborsWithoutWeight(int source);
    vector<pair<int, int>> getNeighborsWithWeight(int source);
    
    int getInDegree(int node);
    void increaseInDegree(int node);
    void decreaseInDegree(int node);
};
#endif