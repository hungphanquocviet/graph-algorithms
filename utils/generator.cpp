#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <filesystem>

/**
 * Graph Generator, use to generate graph in certain format. For experimentation
 * with different graph algorithms
 * 
 * -- Run generator w/ Makefile: make gen --
 * Input format: filename vertex_count edge_count weighted_0_or_1
 * 
 * @author Hung Phan Quoc Viet
 * @date September 3, 2024
 */
using namespace std;
namespace fs = std::filesystem;

/**
 * Generate weighted graph, with the format:
 * n k
 * a1 b1 w1
 * ...
 * ak bk wk
 * 
 * 1 <= wk <= 20
 * 0 <= ak, bk <= n
 * 
 * @param vCount vertex count
 * @param eCount edge count, corespond to vertex
 * 
 * @return the weighted graph in given format 
 */
string generateWeightedGraph(int vCount, int eCount) {

}

/**
 * Generate unweighted graph, with the format:
 * n k
 * a1 b1
 * ...
 * ak bk
 * 
 * 0 <= ak, bk <= n
 * 
 * @param vCount vertex count
 * @param eCount edge count, corespond to vertex
 * 
 * @return the unweighted graph in given format 
 */
string generateUnweightedGraph(int vCount, int eCount) {
    return "testing";
}

/**
 * Generate the graph to put into a .txt file
 * note: Directed/Undirected will be determined when use the graph files
 * 
 * @param vCount vertex count
 * @param eCount edges count, corespond to vertex
 * @param weighted 0 if unweighted graph, 1 if weighted
 * @return the string representation of graph file with the format
 */
string generateGraph(int vCount, int eCount, bool weighted = 0) {
    if (weighted) 
        return generateWeightedGraph(vCount, eCount);
    else 
        return generateUnweightedGraph(vCount, eCount);
}

/**
 * Saves a string to a file in a specified directory.
 *
 * @param directory The directory where the file will be saved.
 * @param filename The name of the file.
 * @param content The string content to save to the file.
 */
void saveToFileInDirectory(const string& directory, const string& filename, const string& content) {
    // Create the directory if it doesn't exist
    if (!fs::exists(directory)) {
        if (fs::create_directories(directory)) {
            cout << "Directory created: " << directory << endl;
        } else {
            cerr << "Failed to create directory: " << directory << endl;
            return;
        }
    }

    // Full path to the file
    string filePath = directory + "/" + filename;

    // Open the file in the specified directory and write the content
    ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        cout << "File saved successfully: " << filePath << endl;
    } else {
        cerr << "Unable to open file: " << filePath << endl;
    }
}

/**
 * Input should be:
 * filename vertex_count edge_count weighted
 * 0 is unweighted, 1 is weighted
 * 
 */
int main() {
    string directory = "graphs";
    string filename;
    int vCount, eCount;
    bool weighted;
    
    // Get the input
    cin >> filename >> vCount >> eCount >> weighted;

    // Get the result
    string res = generateGraph(vCount, eCount, weighted);

    // Save to directory
    saveToFileInDirectory(directory, filename, res);
    return 0;
}