#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int numVertex;
    unordered_map<int, vector<pair<int, int>>> g;
    graph(int vertexSize)
    {
        numVertex = vertexSize;
    }

    void addEdge(int src, int dest, int weight, bool direction)
    {
        g[src].push_back({dest, weight});
        if (direction == 0)
            g[dest].push_back({src, weight});
    }

    void printgraph()
    {
        for (auto vertex : g)
        {
            cout << vertex.first << " -> ";
            for (auto list : vertex.second)
                cout << "{" << list.first << "," << list.second << "},";
            cout << endl;
        }
    }

    void sortest_Path(int source, int dest)
    {
        vector<bool> visited(numVertex, false);
        vector<int> parent(numVertex, INT_MAX);

        queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            
            for (auto neighbour : g[currentVertex])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    parent[neighbour.first] = currentVertex;
                }
            }
        }

        stack<int> st;
        int node = dest;
        int count = 0;
        
        while (node != -1)
        {
            st.push(node);
            node = parent[node];
            count++;
        }

        cout << "sortest path : ";
        while (!st.empty())
        {
            cout << st.top() << "->";
            st.pop();
        }
        cout << endl
             << count << endl;
    }

    void topologicalSort(int s, vector<int> &visited, stack<int> &st)
    {
        visited[s] = true;

        for (auto neighbour : g[s])
        {
            if (!visited[neighbour.first])
            {
                topologicalSort(neighbour.first, visited, st);
            }
        }
        st.push(s);
    }

    void sortestPathWeighted(int src, int dest)
    {
        vector<int> visited(numVertex, false);

        stack<int> TopoOrder;
        for (int i = 0; i < numVertex; i++)
        {
            if (!visited[i])
            {
                topologicalSort(i, visited, TopoOrder);
            }
        }

        vector<int> distance(numVertex, INT_MAX);
        distance[src] = 0;

        while (!TopoOrder.empty())
        {
            int TopElement = TopoOrder.top();
            TopoOrder.pop();

            if (distance[TopElement] != INT_MAX)
            {
                for (auto neighbour : g[TopElement])
                {
                    if(distance[TopElement] + neighbour.second < distance[neighbour.first]){
                        distance[neighbour.first] = distance[TopElement] + neighbour.second;
                    }
                    //distance[neighbour.first] = min(distance[neighbour.first], distance[source] + neighbour.second);
                }
            }
            
        }

        cout << "Sortest Path : " << endl;
        cout << distance[dest];
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
        int weight;

        cout << "Enter source and destination for edge and also weight " << i + 1 << " : ";
        cin >> source >> destination >> weight;

        g.addEdge(source, destination, weight, 1);
    }

    g.printgraph();

    int source;
    int destination;

    // cout << "Enter source and destination ";
    // cin >> source >> destination;
    // g.sortest_Path(source, destination);

    cout << "Enter source and destination ";
    cin >> source >> destination;
    g.sortestPathWeighted(source, destination);
    return 0;
}