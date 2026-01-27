//cpp
class Solution {
public:
    typedef pair<int, int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, INT_MAX);
        vector<vector<p>>adj(n);
        for (auto& temp : edges) {
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto temp = pq.top();
            int cost = temp[0];
            int u = temp[1];
            pq.pop();
            for (auto& arr : adj[u]) {
                int v = arr.first;
                int w = arr.second;
                int newcost = cost + w;
                if (newcost < visited[v]) {
                    visited[v] = newcost;
                    pq.push({newcost, v});
                }
            }
        }
        return visited[n - 1]==INT_MAX ? -1 : visited[n-1];
    }
};
