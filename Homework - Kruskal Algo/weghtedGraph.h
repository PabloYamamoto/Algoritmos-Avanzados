#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
    int src, dst;
    float weight;

    Edge(int src_, int dst_, float weight_)
    {
        src = src_;
        dst = dst_;
        weight = weight_;

    }
    ~Edge() {}

    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.weight < b.weight;
    }
};

// ----------------------- GRAPH VERTEX WEIGHTED -----------------------

class GraphVertexWeighted
{
private:
    vector<pair<int, float>> adj;

public:
    ~GraphVertexWeighted(){};
    GraphVertexWeighted(){};

    vector<pair<int, float>> get_adj() { return adj; };
    void add_to_adj(int idx, float weight) { adj.push_back(make_pair(idx, weight)); };
};

// ----------------------- GRAPH WEIGHTED -----------------------

class GraphWeighted
{
private:
    vector<GraphVertexWeighted> nodes;
    vector<Edge> edges;
    vector<Edge> mst; // Minimu Spanning Tree
    vector<int> parent;
    int V; // Number of vertices

public:
    GraphWeighted() {}
    GraphWeighted(int V)
    {
        V = V;

        for (int i = 0; i < V; i++)
        {
            parent.push_back(i);
        }
    };

    ~GraphWeighted(){};
    void set_nodes(int V_)
    {
        V = V_;

        for (int i = 0; i < V; i++)
        {
            parent.push_back(i);
        }
    }

    void add_edge(int src, int dst, float weight)
    {
        Edge aux(src, dst, weight);
        edges.push_back(aux);
        // nodes[src].add_to_adj(dst, weight);
        // nodes[dst].add_to_adj(src, weight);
    };

    // --------------------- Find Set ---------------------

    int find(int i)
    {
        if (i == parent[i])
            return i;
        return find(parent[i]);
    }

    // --------------------- Union Set ---------------------

    void union_set(int src, int dst)
    {
        parent[src] = parent[dst];
    }

    // --------------------- Kruskal -----------------------

    void kruskal()
    {
        stable_sort(edges.begin(), edges.end());
        
        int srcParent, dstParent;
        for (int i = 0; i < edges.size(); i++)
        {
            srcParent = find(edges[i].src);
            dstParent = find(edges[i].dst);

            if (srcParent != dstParent)
            {
                mst.push_back(edges[i]);
                union_set(srcParent, dstParent);
            }
        }
    }

    // ---------------------- Print ------------------------

    void print()
    {
        for (int i = 0; i < mst.size(); i++)
        {
            cout << mst[i].src << " " << mst[i].dst << " " << mst[i].weight << endl;
        }
        cout << endl;
    }
};