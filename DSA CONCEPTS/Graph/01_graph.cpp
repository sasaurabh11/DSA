#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class graph
{
public:
    unordered_map<int, vector<int>> g;
    int numVertex;

    graph(int vertexSize)
    {
        numVertex = vertexSize;
    }

    void addedge(int source, int destanation, bool direction)
    {
        // direction 0 => undirected graph
        // direction 1 => directed graph
        // create an edge from source to destination
        g[source].push_back(destanation);
        if (direction == 0)
        {
            // create and edge from destination to source also
            // undirected graph
            g[destanation].push_back(source);
        }
    }

    void printgraph()
    {
        for (auto vertex : g)
        {
            cout << vertex.first << " -> ";
            for (auto connection : vertex.second)
                cout << connection << " ";
            cout << endl;
        }
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(numVertex, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (auto neighbour : g[currentVertex])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    void DFS(int s, vector<bool> &visited)
    {
        visited[s] = true;
        cout << s << " ";

        for (auto neighbour : g[s])
        {
            if (!visited[neighbour])
                DFS(neighbour,visited);
        }
    }
};

int main()
{
    // maine template define kiya hai to mujhe graph ko define karna padega ki uska type kya hai
    // graph<int> g;
    // g.addedge(0, 1, 0);
    // g.addedge(1, 2, 0);
    // g.addedge(1, 3, 0);
    // g.addedge(2, 3, 0);

    // g.printgraph();

    // cout << "BFS" << endl;
    // g.BFS(0);

    cout << "Enter num of Vertex: ";
    int vertexsize;
    cin >> vertexsize;

    graph g(vertexsize);

    cout << "Enter number of edges: ";
    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int source;
        int destination;

        cout << "Enter source and destination for edge " << i + 1 << " : ";
        cin >> source >> destination;

        g.addedge(source, destination, 0);
    }

    g.printgraph();
    cout << "\nBFS: ";
    g.BFS(0);

    vector<bool> visited(g.numVertex, false);
    cout << "\nDFS: ";
    g.DFS(0, visited);

    return 0;
}