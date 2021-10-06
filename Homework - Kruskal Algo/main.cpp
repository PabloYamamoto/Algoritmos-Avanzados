/*

Santiago Kohn - A01
Pablo Yamamoto Magaña - A01022382

Kruskas algortihms

A program to find the minimun spannig tree in a weighted unidirected graph

The steps for implementing Kruskal's algorithm are as follows:

    1.- Sort all the edges from low weight to high -> Choose the edge with the least weight, if there are more than 1, choose anyone
    2.- Take the edge with the lowest weight and add it to the spanning tree. If adding the edge created a cycle, then reject this edge.
    3.- Keep adding edges until we reach all vertices. -> Repear steps 1 and 2 V-1

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>

using namespace std;

// ----------------------- GRAPH VERTEX WEIGHTED -----------------------

class GraphVertexWeighted
{
private:
    vector<pair<int, int>> adj;

public:
    ~GraphVertexWeighted(){};
    GraphVertexWeighted(){};

    vector<pair<int, int>> get_adj() { return adj; };
    void add_to_adj(int idx, int weight) { adj.push_back(make_pair(idx, weight)); };
};

// ----------------------- GRAPH WEIGHTED -----------------------

class GraphWeighted
{
private:
    vector<GraphVertexWeighted> nodes;
    vector<GraphVertexWeighted> mst; // Minimu Spanning Tree
    int *parent;
    int V; // Number of vertices

public:
    GraphWeighted(int V)
    {
        parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    };

    ~GraphWeighted(){};

    void add_edge(int src, int dst, float weight)
    {
        nodes[src].add_to_adj(dst, weight);
        nodes[dst].add_to_adj(src, weight);
    };

    // --------------------- Find Set ---------------------

    // --------------------- Union Set ---------------------

    // --------------------- Kruskal ---------------------

    void kruskal()
    {
    }

    // --------------------- Print mst ---------------------
};

int main(int argc, char *argv[])
{

    int number_of_E;     // Number of Edges
    vector<int> n_src;   // Origin Nodes
    vector<int> n_dest;  // Destintation Nodes
    vector<int> weights; // Weights of

    number_of_E = stoi(argv[1]);

    for (int i = 2; i < number_of_E + 2; i++)
    {
        n_src.push_back(stoi(argv[i]));
    }

    for (int i = number_of_E + 2; i < ((number_of_E * 2) + 2); i++)
    {
        n_dest.push_back(stoi(argv[i]));
    }

    for (int i = ((number_of_E * 2) + 2); i < ((number_of_E * 3) + 2); i++)
    {
        weights.push_back(stoi(argv[i]));
    }

    return 0;
}