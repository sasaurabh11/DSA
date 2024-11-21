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

    bool cycle_or_not_directed(int s, vector<bool> &visited, vector<bool> &recursionCallStack)
    {
        visited[s] = true;
        recursionCallStack[s] = true;

        bool ans = false;
        for (auto neighbour : g[s])
        {
            if (visited[neighbour] != true)
            {
                ans = cycle_or_not_directed(neighbour, visited, recursionCallStack);
                if (ans == true)
                    return true;
            }
            if (visited[neighbour] && recursionCallStack[neighbour] == true)
                return true;
        }
        
        recursionCallStack[s] = false;
        return false;
    }

    void topoSortbfs(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculate for everyNode
        for (auto i : g)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // inserting 0 indegree Node
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto nbr : g[frontNode])
            {
                //indegree 1 minus karna padega kyoki hame phir se 0 karna padega
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
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

        g.addEdge(source, destination, 1);
    }

    g.printgraph();

    // cout << "Cycle or not using dfs in Directed graph : ";
    // vector<bool> recursionCallStack(g.numVertex, false);
    // vector<bool> visited(g.numVertex, false);
    // bool ans = false;
    // for (int i = 0; i < g.numVertex; i++)
    // {
    //     ans = g.cycle_or_not_directed(i, visited, recursionCallStack);
    //     if (ans == true)
    //     {
    //         break;
    //     }
    // }

    // if (ans)
    //     cout << "Cycle detected!" << endl;
    // else
    //     cout << "Cycle not detected" << endl;

    vector<int> ans;
    g.topoSortbfs(vertexsize, ans);

    for (auto i : ans)
        cout << i << " ";

    if(ans.size() == vertexsize)    
        cout << "Cycle not present , valid Topo sort" << endl;
    else
        cout << "Cycle present or invalid Topo sort" << endl;

    return 0;
}