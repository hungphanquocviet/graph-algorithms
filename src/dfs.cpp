#include "../include/graph.h"
#include <bits/stdc++.h>

using namespace std;

bool dfs(Graph& g, int src, int dst) {
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> src(n+1);
    vector<int> dst(n+1);
    vector<int> weight(n+1);

    for (int i = 0; i <= n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
    }

    Graph g(n);
    
    g.buildGraph(src, dst, weight);
    return 0;
}
