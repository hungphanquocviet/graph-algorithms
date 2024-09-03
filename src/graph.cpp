#include "../include/graph.h"

Graph::Graph(int n) : n(n), adjList(n+1), inDegree(n+1, 0) {}

void Graph::buildGraph(vector<int>& src, vector<int>& dst, vector<int>& weight) {
    for (int i = 0; i <= n; i++) {
        int a = src[i];
        int b = dst[i];
        int w = weight[i];

        adjList[a].push_back({w, b});

        inDegree[b]++;
    }
}

vector<int> Graph::getNeighborsWithoutWeight(int source) {
    vector<int> res;
    for (auto& neighbor : adjList) {
        for (auto& it : neighbor)
            res.push_back(it.second);
    }

    return res;
}

vector<pair<int, int>> Graph::getNeighborsWithWeight(int source) {
    return adjList[source];
}

int Graph::getInDegree(int node) {
    return inDegree[node];
}

void Graph::increaseInDegree(int node) {
    inDegree[node]++;
}

void Graph::decreaseInDegree(int node) {
    inDegree[node]--;
}