#ifndef TOPOSORT_H
#define TOPOSORT_H
#include <bits/stdc++.h>

/**
 * @class TopologicalSort
 * @brief Implements Topological Sort using Kahn's Algorithm.
 *
 * This class provides a method, `sort()`, which performs topological sorting
 * on the given nodes based on their in-degree count.
 *
 * One common application of topological sort is course scheduling, where the
 * sort method can be used to determine the correct order of courses based on
 * prerequisites.
 */
class TopologicalSort {
public:
    // Constructor, should be empty
    TopologicalSort();

    /**
     * Sort method, takes in 2 arguments:
     * @param n the number of nodes, labeling from 0 to n-1
     * @param edges the edge list
     * 
     * @return the sorted list of nodes, if there is a cycle, return empty list
     */
    std::vector<int> sort(int n, std::vector<std::vector<int>>& edges);
};

#endif
