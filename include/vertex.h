#ifndef VERTEX_H
#define VERTEX_H

#include <bits/stdc++.h>

using namespace std;

class Vertex{

public:
    Vertex(int val);
    int getVal();
    int getInDegree();
    int setIndegree();
    int getNeighbors(int src);
    
private:
    int val;
    int inDegree;
    
    // adjList[a] = {w, b};
    // a, b: node, w is weight.
    vector<vector<pair<int, int>>> adjList;


};

#endif