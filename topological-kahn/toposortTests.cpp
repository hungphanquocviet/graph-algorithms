#include "toposort.h"
#include <cassert>
#include <gtest.h>
#include <bits/stdc++.h>

using namespace std;

TEST(TopoTests, SimpleGraph) {
    TopologicalSort solver;

    int n = 4;
    vector<vector<int>> edges {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    vector<int> expected = {0, 1, 2, 3};

    EXPECT_EQ(expected, solver.sort(n, edges));
}

TEST(TopoTests, CyclicGraph) {
    TopologicalSort solver;

    int n = 4;
    vector<vector<int>> edges {{0, 1}, {0, 2}, {2, 0}, {2, 3}};
    vector<int> expected;
    vector<int> actual = solver.sort(n, edges);

    EXPECT_EQ(expected.size(), actual.size());
}