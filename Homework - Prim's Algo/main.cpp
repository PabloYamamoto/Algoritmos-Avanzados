/*
Santiago Kohn - A01029109
Pablo Yamamoto - A01022382

Prim's Algorithm 

Program to find minimum spanning tree.

The steps for implementing Prim's algorithm are as follows:

    1. start at any node in the graph.
    2. Find an edge e with minimum cost in the graph that connects. A reached node x to an unreached node y.
    3. Add the edge e found in the previous step to the Minimum cost Spanning Tree. Mark the unreached node y as reached.
    4. Repeat the steps 2 and 3 until all nodes in the graph have become reached.

Input:
*/

#include "weghtedGraph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int number_of_E = stoi(argv[1]); // Number of Edges
    //int number_of_N = 0;             // Number of nodes
    int src, dst;
    float weight;
    GraphWeighted graph;

    for (int i = 0; i < number_of_E; i++)
    {
        src = stoi(argv[i + 2]);
        dst = stoi(argv[i + number_of_E + 2]);
        weight = stof(argv[i + 2 * number_of_E + 2]);

        graph.add_edge(src, dst, weight);
    }

    graph.Prim(0); //starts in node 0.

    graph.printMST();

    return 0;
}
