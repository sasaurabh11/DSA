#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> g;
    int numVertices;

    graph(int num)
    {
        numVertices = num;
    }

    void addEdge(int src, int dest, int weight, bool direction)
    {
        g[src].push_back(make_pair(dest, weight));
        // 0 denotes undirected graph
        if (direction == 0)
        {
            g[dest].push_back({src, weight});
        }
    }

    void print_graph()
    {
        for (auto node : g)
        {
            cout << node.first << " -> ";
            for (auto list : node.second)
            {
                cout << "{ " << list.first << ", " << list.second << " }, ";
            }
            cout << endl;
        }
    }

    void shortesDistDijsktra(int src, int n)
    {
        set<pair<int, int>> st;
        vector<int> dist(n+1, INT_MAX);

        // intial step
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // erase the element which is fetched
            st.erase(st.begin());

            // neighbour traversal
            for (auto nbr : g[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // yaha galti karunga
                    // mujhe distance bhi update karna hai aur agar set me present hai to use bhi update karna hai

                    auto findPuraneSetvalue_nbr = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found then remove
                    if (findPuraneSetvalue_nbr != st.end())
                    {
                        st.erase(findPuraneSetvalue_nbr);
                    }

                    // updation in distance array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout << "Printing distance : ";
        for (auto val : dist)
            cout << val << " ";
        cout << endl;
    }

    void DijsktraUsingHeap(int src, int n) {
        vector<int> dist(n + 1, INT_MAX);

        // Priority queue to select the node with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto topElement = pq.top();
            int nodeDistance = topElement.first;
            int node = topElement.second;

            pq.pop();

            for(auto nbr : g[node]) {
                int nbrValue = nbr.first;
                int nbrWeight = nbr.second;

                // relax the edge
                if(dist[node] + nbrWeight < dist[nbrValue]) {
                    dist[nbrValue] = dist[node] + nbrWeight;
                    pq.push({dist[nbrValue], nbrValue});
                }
            }
        }

        cout << "Printing distance : ";
        for (auto val : dist)
            cout << val << " ";
        cout << endl;
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

        g.addEdge(source, destination, weight, 0);
    }

    g.print_graph();

    g.DijsktraUsingHeap(6, vertexsize);
    return 0;
}

// 6
// 9
// 1 6 14
// 1 3 9
// 1 2 7
// 6 5 9
// 6 3 2
// 3 2 10
// 3 4 11
// 2 4 15
// 5 4 6