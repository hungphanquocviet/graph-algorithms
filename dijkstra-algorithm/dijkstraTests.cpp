#include "dijkstra.h"
#include <cassert>
#include <gtest.h>
#include <bits/stdc++.h>

using namespace std;

TEST(DijkstraTest, simpleTest) {
    Dijkstra solver;

    int n = 6;
    vector<vector<int>> edges{{0, 1}, {0,3}, {0,2}, {2, 1}, {2, 4}, {1, 3}, {3, 4}};
    vector<int> weights{5, 10, 4, 1, 9, 1, 1};

    EXPECT_EQ(6, solver.shortestPath(n, edges, weights, 0, 3)) << "nuh";

}

TEST(DijkstraTest, simpleTest2) {
    Dijkstra solver;

    int n = 4;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}, {2, 3}};
    vector<int> weights{1, 2, 4, 1};

    EXPECT_EQ(4, solver.shortestPath(n, edges, weights, 0, 3)) << "nuh";
}

TEST(DijkstraTest, noPath) {
    Dijkstra solver;

    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    vector<int> weights = {1, 2};
    int start = 0;
    int end = 3;
    int expected = INT_MIN; // No path from 0 to 3
    EXPECT_EQ(expected, solver.shortestPath(n, edges, weights, start, end)) << "nuh";
}

TEST(DijkstraTest, OnlyOneNode) {
    Dijkstra solver;

    int n = 1;
    vector<vector<int>> edges = {};
    vector<int> weights = {};
    int start = 0;
    int end = 0;
    int expected = 0; // Start and end are the same

    EXPECT_EQ(expected, solver.shortestPath(n, edges, weights, start, end)) << "nuh";
}

TEST(DijkstraTest, MultiplePaths) {
    Dijkstra solver;

    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}
    };
    vector<int> weights = {2, 4, 1, 7, 3, 2, 1}; // Corresponding weights for edges
    int start = 0;
    int end = 4;

    int expected = 5; // Shortest path: 5

    EXPECT_EQ(expected, solver.shortestPath(n, edges, weights, start, end)) << "nuh";
}

TEST(DijkstraTest, NoPathsConnectedGraph) {
    Dijkstra solver;

    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}
    };
    vector<int> weights = {2, 4, 1, 7, 3, 2, 1}; // Corresponding weights for edges
    int start = 3;
    int end = 2;

    int expected = INT_MIN; // Shortest path: 5

    EXPECT_EQ(expected, solver.shortestPath(n, edges, weights, start, end)) << "nuh";
}