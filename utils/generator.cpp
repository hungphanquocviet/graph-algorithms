#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

/**
 * Graph Generator, use to generate graph in certain format. For experimentation
 * with different graph algorithms
 * 
 * -- Run generator w/ Makefile: make gen --
 * 
 * @author Hung Phan Quoc Viet
 * @date September 3, 2024
 */
using namespace std;

/**
 * Generate unweighted graph, in form:
 * n k
 * a1 b1 0
 * a2 b2 0
 * ...
 * ak bk 0
 * 
 * With n is the max label
 * k is the number of edges
 * 0 <= ak, bk <= n
 * 
 */
string generateUnweightedGraph(int n, int k) {
    return "this is for testing";
}

/**
 * Generate weighted graph, in form:
 * n k
 * a1 b1 w1
 * a2 b2 w2
 * ...
 * ak bk wk
 * 
 * With n is the max label
 * k is the number of edges
 * 0 <= ak, bk, wk <= n
 * 0 <= wk <= 9
 * 
 */
string generateWeightedGraph(int n, int k) {
    return "testing";
}

// Input expect: file_name.txt n k 0
int main() {
    string fileName;
    int n, k;

    // w stands for if graph is weighted or not.
    // 0 is not weighted, not 0 is weighted.
    int w;
    cin >> fileName >> n >> k >> w;
    string res = "";

    string dir = "../graphs/" + fileName;
    if (w == 0) {
        res += generateUnweightedGraph(n, k);
    }

    else {
        res += generateWeightedGraph(n, k);
    }

    ofstream graphFile(dir);

    graphFile << res;
    graphFile.close();

    cout << "hi" << "\n";
    return 0;
}