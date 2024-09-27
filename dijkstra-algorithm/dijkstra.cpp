#include "dijkstra.h"
using namespace std;

/**
 * Dijkstra Algorithm practice
 * Problem definition: Given 4 parameters:
 * 
 * n: number of nodes, labeled from 0 to n-1 type int
 * edges: 2D array representing the edges type vector<vector<int>>
 * weight: 1D array representing the weights type vector<int>
 * int start: starting node
 * int end: ending node
 * 
 * We want to return the shortest distance from start
 * to end. If there is no path, return INT_MIN or INF
 * 
 */

Dijkstra::Dijkstra() {
    // Empty constructor
}

int Dijkstra::shortestPath(int n, std::vector<std::vector<int>>& edges, std::vector<int> weights, int start, int end) {
    using p = pair<int, int>; // <weight, dst>

    vector<vector<p>> adjList(n);

    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        int w = weights[i];

        adjList[src].push_back({w, dst});
    }

    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> weight(n, INT_MAX);

    weight[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currWeight = pq.top().first;
        int currNode = pq.top().second;

        pq.pop();
        
        if (currNode == end) {
            return currWeight;
        }

        for (int i = 0; i < adjList[currNode].size(); i++) {
            int neighbor = adjList[currNode][i].second;
            int neighborWeight = adjList[currNode][i].first;

            int newWeight = currWeight + neighborWeight;

            if (newWeight < weight[neighbor]) {
                weight[neighbor] = newWeight;
                pq.push({newWeight, neighbor});
            } 
        }

    }
    return INT_MIN;
}
