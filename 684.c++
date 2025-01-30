//DFS
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, int dest,
             vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, dest, visited);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> redundant;
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (adj.empty() || adj.find(u) == adj.end() ||
                adj.find(v) == adj.end()) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                vector<bool> visited(n + 1, false);
                dfs(adj, u, v, visited);
                if (visited[v]) {
                    redundant.push_back(u);
                    redundant.push_back(v);
                }
                else {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        return redundant;
    }
};