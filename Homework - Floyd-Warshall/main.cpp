/*

Santiago Kohn - A0129109
Pablo Yamamoto Magaña - A01022382


Floyd-Warshall

Find the shortest path of every pair of vertex.

The steps to implement the algorithm are:

    1. Create the adjacency matrix.
    2. Create distance matrix to build the path.
    3. iterate al nodes three times and check of the k node is shroter than the original.

Input:
    16 2 3 1 1 0 4 6 5 4 1 6 2 1 6 0 0 3 6 2 5 2 7 2 7 5 3 0 7 7 4 7 4 17 52 36 32 26 37 40 28 35 29 58 34 19 93 16 38 2 5
    n,  n values for source node, n values for destination node, n values for the weight of the edge, and two values for the path that we want.

Output:
    2 3 17
    3 6 52
    6 4 93
    4 5 35

    The edges that create the shortest path between the two nodes.
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <typeinfo>
#include "weghtedGraph.h"

using namespace std;

int main(int argc, char *argv[])
{
    int number_of_E = stoi(argv[1]); // Number of Edges
    int number_of_N = 0;             // Number of nodes
    int src, dst;
    float weight;
    GraphWeighted graph;

    for (int i = 0; i < number_of_E; i++)
    {
        src = stoi(argv[i + 2]);
        dst = stoi(argv[i + number_of_E + 2]);
        weight = stof(argv[i + 2 * number_of_E + 2]);

        graph.add_edge(src, dst, weight);

        number_of_N = max(number_of_N, max(src, dst));
    }
    graph.set_nodes(number_of_N+1);

    graph.floydWarshall(stoi(argv[argc-2]), stoi(argv[argc-1]));

    return 0;
}