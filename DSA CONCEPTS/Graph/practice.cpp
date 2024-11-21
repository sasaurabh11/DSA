#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class graph
    {
        unordered_map<string, string> g;

        void addEdge(string src, string dest, bool direction)
        {
            g[src].push_back(dest);
            if (direction == 0)
                g[dest].push_back(src);
        }
    };

    string destCity(vector<vector<string>> &paths)
    {

        graph g;
        int n = paths.size();

        for (int i = 0; i < n; i++)
        {
            g.addEdge(paths[i][0], paths[i][1], 1);
        }
    }
};