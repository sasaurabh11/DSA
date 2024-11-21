#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, vector<T>> graph;

    void addedge(T source, T destanation, bool direction)
    {
        // direction 0 => undirected graph
        // direction 1 => directed graph
        // create an edge from source to destination
        graph[source].push_back(destanation);
        if (direction == 0)
        {
            // create and edge from destination to source also
            // undirected graph
            graph[destanation].push_back(source);
        }
    }

    void printgraph()
    {
        for (auto vertex : graph)
        {
            cout << vertex.first << " -> ";
            for (auto connection : vertex.second)
                cout << connection << " ";
            cout << endl;
        }
    }

    void BFS(T startVertex)
    {
        vector<bool> visited(100, false);
        queue<T> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            T currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (auto neighbour : graph[currentVertex])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main()
{
    // maine template define kiya hai to mujhe graph ko define karna padega ki uska type kya hai
    graph<int> g;
    g.addedge(0, 1, 0);
    g.addedge(1, 2, 0);
    g.addedge(1, 3, 0);
    g.addedge(2, 3, 0);

    g.printgraph();

    cout << "BFS" << endl;
    g.BFS(0);
    return 0;
}