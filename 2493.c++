class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<int> que;
        vector<bool> visited(n+1, false);
        que.push(currNode);
        visited[currNode] = true;

        int level = 1; 
        while(!que.empty()) {

            int size = que.size();
            while(size--) {
                int curr = que.front();
                que.pop();

                for(int &ngbr : adj[curr]) {
                    if(visited[ngbr])
                        continue;
                    
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++; 
        }

        return level-1;
    }

    bool check(unordered_map<int, vector<int>>& adj, vector<int>& color, int u,
               int currcolor) {
        color[u] = currcolor;
        for (int v : adj[u]) {
            if (color[v] == color[u])
                return false;
            if (color[v] == -1 && !check(adj, color, v, 1 - currcolor))
                return false;
        }
        return true;
    }
    int findmaxgroup(unordered_map<int, vector<int>>& adj, int u,
                     vector<bool>& visited, vector<int>& levels) {
        int maxgroup = levels[u];
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                maxgroup = max(maxgroup, findmaxgroup(adj, v, visited, levels));
            }
        }
        return maxgroup;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto temp : edges) {
            int u = temp[0];
            int v = temp[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1 && !check(adj, color, i, 1))
                return -1;
        }
        vector<int> levels(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            levels[i] = bfs(adj, i, n);
        }
        vector<bool> visited(n + 1, false);
        int maxgroups = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                maxgroups += findmaxgroup(adj, i, visited, levels);
            }
        }
        return maxgroups;
    }
};