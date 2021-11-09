/*

Santiago Kohn - A0129109
Pablo Yamamoto Magaña - A01022382

Ford-Fulkerson for Maximum Flow in Networks

Find the shortest path of every pair of vertex.

The steps to implement the algorithm are:

    1. Find a path from the start to the finish.
    2. Find the augment flow in the path.
    3. Sum to the max flow variable.
    4. Reapeat until there are not path between start and finish.

Input:
    16 2 3 1 1 0 4 6 5 4 1 6 2 1 6 0 0 3 6 2 5 2 7 2 7 5 3 0 7 7 4 7 4 17 52 36 32 26 37 40 28 35 29 58 34 19 93 16 38 2 5
    n,  n values for source node, n values for destination node, n values for the weight of the edge, and two values for the path that we want.

Output:
    17 
    The maximum flow possible.
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

    int start = stoi(argv[argc-2]);
    int finish = stoi(argv[argc-1]);

    cout << graph.fordFulkerson(start, finish) << endl;
    return 0;
}