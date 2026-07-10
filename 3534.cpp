//cpp
class Solution {
public:
    int bfs(int u, int v, vector<vector<int>>& adj, int n) {
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(u);
        visited[u] = true;
        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                int node = que.front();
                que.pop();
                if (node == v)
                    return level;
                for (int& vNode : adj[node]) {
                    if (!visited[vNode]) {
                        visited[vNode] = true;
                        que.push(vNode);
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= maxDiff) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> result;
        for (auto& temp : queries) {
            int u = temp[0];
            int v = temp[1];
            int dist = bfs(u, v, adj, n);
            result.push_back(dist);
        }
        return result;
    }
};
