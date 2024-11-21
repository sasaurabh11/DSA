#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> mp;

int t = 0;

void dfs(int node, int par, vector<int> graph[]) {
    // entering the node
    mp[node].first = t;
    t++;
    
    for(auto child : graph[node]) {
        if(child != par) {
            dfs(child, node, graph);
        }
    }

    mp[node].second = t;
    t++;
    //leaving the node
}

void solve() {
    int n;
    cin >> n;

    vector<int> graph[n];

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1, graph);
}

int main() {
    solve();

    return 0;
}