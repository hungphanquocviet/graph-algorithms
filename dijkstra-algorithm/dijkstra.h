#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <bits/stdc++.h>

class Dijkstra {
public:
    Dijkstra();
    int shortestPath(int n, std::vector<std::vector<int>>& edges, std::vector<int> weights, int start, int end);
    
};
#endif