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

// ----------------------- GRAPH WEIGHTED -----------------------

class GraphWeighted
{
private:
    vector<Edge> edges;
    int V; // Number of vertex
    vector<vector<float>> adj;

public:
    GraphWeighted() {}
    GraphWeighted(int V_)
    {
        V = V_;
    };

    ~GraphWeighted(){};
    void set_nodes(int V_)
    {
        V = V_;

        // Fill the adjacency matrix.
        adj = vector<vector<float>>(V, vector<float>(V, INT16_MAX));
        for (int i = 0; i < V; i++)
        {
            adj[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i].src][edges[i].dst] = edges[i].weight;
        }
    }


    void add_edge(int src, int dst, float weight)
    {
        // Edge aux(src, dst, weight);
        edges.push_back(Edge(src, dst, weight));
    };

    void floydWarshall(int src, int dst)
    {
        /*
        floydWarshall algoritm recive two intergers, the start and finish of the path that we want. 
        */
        vector<vector<float>> dist(V, vector<float>(V, INT16_MAX));
        vector<vector<int>> next(V, vector<int>(V, -1));

        // setuo the distance matrix and next matrix, copy the adjacency matrix to distance and if isn't infinit add to next.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                dist[i][j] = adj[i][j];
                if (dist[i][j] != INT16_MAX)
                {
                    next[i][j] = j;
                }
            }
        }

        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        //change the value of the distance if the sum less than the original value and add to next de next of this node.
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }

        //Print the result, we use the path that we create in next. 
        int actualNode = src;
        int nextNode;
        while (actualNode != dst)
        {
            nextNode = next[actualNode][dst];
            cout << actualNode << " " <<  nextNode << " " << adj[actualNode][nextNode] << endl;
            actualNode = nextNode;
        }
    }
};