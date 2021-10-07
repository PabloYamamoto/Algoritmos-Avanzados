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
#include <set>
#include <typeinfo>
//#include "weightedGraph.h"

using namespace std;

struct Edge
{
    int src;
    int dest;
    float weight;

    Edge(int src_, int dest_, float weight_)
    {
        src = src_;
        dest = dest_;
        weight = weight_;
    }
};

bool compareWeight(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

bool isCycle(int src, int dest, vector<int> &union_find)
{
    if (union_find[src] != union_find[dest])
    {
        int find = union_find[src];

        for (int j = 0; j < union_find.size(); j++)
        {
            if (union_find[j] == find)
                union_find[j] = union_find[dest];
        }
        return true;
    };
    return false;
}

void kruskal(vector<Edge> edges, int n_edges, int n_nodes)
{
    vector<int> union_find;
    vector<Edge> ans; 

    sort(edges.begin(), edges.end(), compareWeight);

    for (int i = 0; i < n_nodes; i++)
    {
        union_find.push_back(i);
    }

    for (int i = 0; i < n_edges; i++)
    {
        if (isCycle(edges[i].src, edges[i].dest ,union_find))
        {
            ans.push_back(edges[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].src << " " << ans[i].dest << " " << ans[i].weight << endl;
    }
}

int main(int argc, char *argv[])
{

    int number_of_E = stoi(argv[1]);       // Number of Edges
    set<int> nodes;
    vector<Edge> edges;
    
    for (int i = 0; i < number_of_E; i++)
    {
        Edge a(stoi(argv[i + 2]), stoi(argv[i + number_of_E + 2]), stof(argv[i + 2 * number_of_E + 2]));
        edges.push_back(a);
        nodes.insert(a.src);
        nodes.insert(a.dest);
    }

    kruskal(edges, number_of_E, nodes.size());

    return 0;
}