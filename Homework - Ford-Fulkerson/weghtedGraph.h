#include <iostream>
#include <vector>
#include <queue>
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
        adj = vector<vector<float>>(V, vector<float>(V, 0));
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

    bool bfs(vector<vector<float> > graph, int s, int f, vector<int> &parent)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        parent[s] = -1;
        visited[s] = true;

        //Check if its a path from start to finish.
        while (!q.empty())
        {
            int actualNode = q.front();

            for (int i = 0; i < V; i++)
            {
                if (graph[actualNode][i] != 0 && !visited[i])
                {
                    if (i == f)
                    {
                        parent[i] = actualNode;
                        return true; // return true if get the finich node.
                    }
                    q.push(i);
                    parent[i] = actualNode;
                    visited[i] = true;
                }
            }
            q.pop();
        }

        return false;
    }

    float fordFulkerson(int s, int f)
    {
        vector<vector<float> > graphFC(adj); // graph to modify the flow and capacity.
        vector<int> parent(V, -1); // to check the paths with the bfs
        float max_flow = 0;

        while(bfs(graphFC, s, f, parent))
        {
            float flow = graphFC[parent[f]][f];
            int i = f; // iterator for the path.
            while (parent[i] != -1)
            {
                flow = min(flow, graphFC[parent[i]][i]); // find the augment flow
                i = parent[i];
            }

            i = f;
            while (parent[i] != -1)
            {
                graphFC[parent[i]][i] -= flow;
                graphFC[i][parent[i]] += flow;
                i = parent[i];
            }
            
            max_flow += flow;
        }

        return max_flow;
    }
};