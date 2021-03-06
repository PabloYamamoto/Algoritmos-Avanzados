#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Edge
{
public:
    int src, dst;
    float weight;

    Edge() {}

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

struct compareByWeight
{
    bool operator()(Edge const &a, Edge const &b) const
    {
        return a.weight > b.weight;
    }
};

// ----------------------- GRAPH VERTEX WEIGHTED -----------------------

class GraphVertexWeighted
{
private:
    vector<Edge> adj;

public:
    ~GraphVertexWeighted(){};
    GraphVertexWeighted(){};

    vector<Edge> get_adj() { return adj; };
    void add_to_adj(Edge edge) { adj.push_back(edge); };
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
        int m = max(src, dst);
        if (m + 1 > nodes.size())
        {
            nodes.resize(m + 1);
        }

        Edge aux(src, dst, weight);
        edges.push_back(aux);

        nodes[src].add_to_adj(aux);
        nodes[dst].add_to_adj(aux);
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

    void Prim(int startNode)
    {
        vector<bool> reached(nodes.size(), 0);

        vector<Edge> edges(nodes[startNode].get_adj());

        // priority queue for de edges with the first adjacency edges.
        priority_queue<Edge, vector<Edge>, compareByWeight> pQueue(edges.begin(), edges.end());
        reached[startNode] = true;
        int actualNode;
        Edge lastEdge;

        for (int i = 0; i < nodes.size() - 1; i++)
        {
            // pass all the adjacency that we have already reached.
            do
            {
                lastEdge = pQueue.top();
                pQueue.pop();
            } while (reached[lastEdge.src] && reached[lastEdge.dst]);

            mst.push_back(lastEdge);

            if (reached[lastEdge.src])
                actualNode = lastEdge.dst;
            else
                actualNode = lastEdge.src;

            reached[actualNode] = true;

            // adjacency of actual node.
            vector<Edge> edges(nodes[actualNode].get_adj());

            // Push to priority queue all the adjacency.
            for (int j = 0; j < edges.size(); j++)
            {
                pQueue.push(edges[j]);
            }
        }

        stable_sort(mst.begin(), mst.end());
    }

    void printMST()
    {
        for (int i = 0; i < mst.size(); i++)
        {
            cout << mst[i].src << " " << mst[i].dst << " " << mst[i].weight << endl;
        }
        cout << endl;
    }
};