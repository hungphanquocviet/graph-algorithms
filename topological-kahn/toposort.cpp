#include "toposort.h"

using namespace std;

TopologicalSort::TopologicalSort() {
    // Leave empty
}

vector<int> TopologicalSort::sort(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n);
    vector<int> inDeg(n, 0);

    for (auto& edge : edges) {
        int src = edge[0];
        int dst = edge[1];

        adjList[src].push_back(dst);
        inDeg[dst]++;
    }

    queue<int> queue;

    for (int i = 0; i < inDeg.size(); i++) {
        if (inDeg[i] == 0)
            queue.push(i);
    }

    vector<int> res;
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        res.push_back(current);
        for (auto& neighbor : adjList[current]) {
            inDeg[neighbor]--;
            if (inDeg[neighbor] == 0)
                queue.push(neighbor);
        }
    }

    return res.size() == n ? res : std::vector<int>();
}
