#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> graph;

    void addedge(int source, int destanation, int weight, bool direction)
    {
        graph[source].push_back({destanation, weight});
        if (direction == 0)
        {
            // create and edge from destination to source also
            // undirected graph
            graph[destanation].push_back({source, weight});
        }
    }

    void printgraph()
    {
        for (auto vertex : graph)
        {
            cout << vertex.first << " -> ";
            for (auto connection : vertex.second)
                cout <<"{"<< connection.first << ", " << connection.second << "} ";
            cout << endl;
        }
    }
};

int main()
{
    graph g;
    g.addedge(0, 1, 3, 0);
    g.addedge(1, 2, 2, 0);
    g.addedge(1, 3, 4, 0);
    g.addedge(2, 3, 5, 0);

    g.printgraph();

    return 0;
}