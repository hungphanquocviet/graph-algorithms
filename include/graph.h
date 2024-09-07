#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

/**
 * Vertices should be labeled from 0...n
 */
class Graph {
    using edge = pair<double, int>;  // weight, neighbor
private:
    // adjList[a] = {w, b};
    int n;
    vector<vector<edge>> adjList;
    vector<int> inDegree;

public:
    /**
     * Initialize graph class with max node of value n
     * The given graph will have node from 0...n
     * 
     */
    Graph(int n) : inDegree(n+1), adjList(n+1), n(n) {
        cout << "Graph initialized with edge from 0 to " << n << "\n";
    }

    /**
     * Add a directed edge from a -> b
     * If the edge is unweighted, default weight will be 0.0
     * 
     * @param a vertex a
     * @param b vertex b
     * @param w edge weight, default is 0.0
     */
    void addDirectedEdge(int a, int b, double w = 0.0) {
        adjList[a].push_back({w, b});
        inDegree[b]++;
    }

    /**
     * Add an undirected edge from a -> b
     * If the edge is unweighted, default weight will be 0.0
     * 
     * @param a vertex a
     * @param b vertex b
     * @param w edge weight, default is 0.0
     */
    void addUndirectedEdge(int a, int b, double w = 0.0) {
        addDirectedEdge(a, b, w);
        addDirectedEdge(b, a, w);
    }

    /**
     * Get the size of the graph
     * @return size of the graph
     */
    int size() {
        return n;
    }

    /**
     * Clear the graph
     */
    void clear() {
        for (int i = 0; i <= n; i++) 
            adjList[i].clear();
        
        fill(inDegree.begin(), inDegree.end(), 0);
        cout << "Graph cleared" << "\n";
    }

    /**
     * Get the count of edges in the graph
     */
    int edgeCount() {
        int count = 0;

        for (auto& edges : adjList)
            count += edges.size();

        return count;
    }

    /**
     * Build unweighted graph from given sources and destinations
     * 
     * @param src the source vertices
     * @param dst the destination vertices
     * @param directed true if graph is directed, false if not
     * 
     * Note: We are assuming src and dst have same size
     */
    void buildGraph(vector<int>& src, vector<int>& dst, bool directed=true) {
        for (int i = 0; i < src.size(); i++) {
            if (directed)
                addDirectedEdge(src[i], dst[i]);
            else 
                addUndirectedEdge(src[i], dst[i]);
        }

        cout << "Finish building unweighted graph" << "\n";
    }

    /**
     * Build weighted graph from given sources and destinations and weights
     * 
     * @param src the source vertices
     * @param dst the destination vertices
     * @param weight the weights
     * @param directed true if graph is directed, false if not
     * 
     * Note: We are assuming src and dst have same size
     */
    void buildGraph(vector<int>& src, vector<int>& dst, vector<int>& weights, bool directed=true) {
        for (int i = 0; i < src.size(); i++) {
            if (directed)
                addDirectedEdge(src[i], dst[i], weights[i]);
            else 
                addUndirectedEdge(src[i], dst[i], weights[i]);
        }

        cout << "Finish building weighted graph" << "\n";
    }
    /**
     * Output the string representation of graph, in DOT language, following the convention:
     * graph G {
     *      1 -- 2  [weight=w1, label="w1"]
     *      2 -- 3  [weight=w2, label="w2"]
     *      ...
     * }
     * 
     * @return string representation of graph
     */
    string toString() const {
        stringstream ss;
        ss << "graph G {\n";
        for (int i = 0; i <= n; i++) {
            for (const auto& [weight, neighbor] : adjList[i]) {
                ss << "     " << i << " -- " << neighbor << " [weight=" << weight << ", label=\"" << weight << "\"];\n";
            }
        }
        ss << "}\n";
        return ss.str();
    }

    /**
     * Output to console string representation
     */
    friend std::ostream& operator<<(std::ostream &strm, const Graph &g) {
        return strm << g.toString();
    }
};
#endif