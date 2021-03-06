/*

Santiago Kohn - A0129109
Pablo Yamamoto Magaña - A01022382

Kruskas algortihms

A program to find the minimun spannig tree in a weighted unidirected graph

The steps for implementing Kruskal's algorithm are as follows:

    1.- Sort all the edges from low weight to high -> Choose the edge with the least weight, if there are more than 1, choose anyone
    2.- Take the edge with the lowest weight and add it to the spanning tree. If adding the edge created a cycle, then reject this edge.
    3.- Keep adding edges until we reach all vertices. -> Repear steps 1 and 2 V-1

Input: 

    1. number of edges. INT
    2. N source of the edges. INT
    3. N destination of the edges. INT
    4. N weight of the edges. INT
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

    graph.kruskal();

    graph.print();

    return 0;
}