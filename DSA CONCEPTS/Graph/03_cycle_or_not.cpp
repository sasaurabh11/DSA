#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int numVertex;
    unordered_map<int, vector<int>> g;
    graph(int vertexSize)
    {
        numVertex = vertexSize;
    }

    void addEdge(int src, int dest, bool direction)
    {
        g[src].push_back(dest);
        if (direction == 0)
            g[dest].push_back(src);
    }

    void printgraph()
    {
        for (auto vertex : g)
        {
            cout << vertex.first << " -> ";
            for (auto list : vertex.second)
                cout << list << " ";
            cout << endl;
        }
    }

    void cycle_or_not(int s)
    {
        vector<bool> visited(numVertex, false);
        vector<int> parent(numVertex, INT_MAX);

        queue<int> q;

        visited[s] = true;
        q.push(s);
        parent[s] = -1;

        bool check = false;
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
                    parent[neighbour] = currentVertex;
                }
                else if (visited[neighbour] && parent[currentVertex] != neighbour)
                {
                    check = true;
                    break;
                }
            }
        }
        if (check)
            cout << "Cycle present!" << endl;
        else
            cout << "Cycle not present" << endl;
    }

    bool cycle_or_notUsingDFS(int s,vector<int> &parent, vector<bool> &visited)
    {
        visited[s] = true;
        cout << s << " ";

        for (auto neighbour : g[s])
        {
            if (!visited[neighbour])
            {
                parent[neighbour] = s;
                bool ans = cycle_or_notUsingDFS(neighbour, parent, visited);
                if (ans)
                    return true;
            }
            else if (visited[neighbour] && parent[s] != neighbour)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
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

        g.addEdge(source, destination, 0);
    }

    g.printgraph();

    cout << "Cycle present or not " << endl;
    g.cycle_or_not(0);

    // vector<bool> visited(g.numVertex, false);
    // vector<int> parent(g.numVertex);
    // cout << "Cycle present or not " << endl;
    // bool ans = false;
    // for (int i = 0; i < g.numVertex; i++)
    // {
    //     parent[i] = -1;
    //     if (!visited[i])
    //     {
    //         ans = g.cycle_or_notUsingDFS(i, parent, visited);
    //         if (ans == true)
    //             break;
    //     }
    // }
    // if (ans)
    //     cout << "cycle present!";
    // else
    //     cout << "Cycle absent";

    return 0;
}