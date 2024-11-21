class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
            vector<vector<pair<int, int>>> adjList(n);
            for (auto& val : edges) {
                int u = val[0], v = val[1], length = val[2];
                adjList[u].push_back({v, length});
                adjList[v].push_back({u, length});
            }

            vector<int> ans(n, -1);
            priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
            pq.push({0, 0, true}); // {time, node, reachable}

            while (!pq.empty()) {
                auto [time, node, reachable] = pq.top();
                pq.pop();
                if (!reachable || (ans[node] != -1 && ans[node] <= time)) continue;
                ans[node] = time;

                for (auto& neighbor : adjList[node]) {
                    int nextNode = neighbor.first;
                    int nextTime = time + neighbor.second;

                    bool nextReachable = (nextTime < disappear[nextNode] || disappear[nextNode] == -1);
                    pq.push({nextTime, nextNode, nextReachable});
                }
            }

            return ans;
        }
};