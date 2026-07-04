//BFS
class Solution {
public:
    typedef pair<int, int> p;
    int bfs(int u, unordered_map<int, vector<pair<int, int>>>& mp, int n) {
        vector<int> result(n + 1, INT_MAX);
        queue<int> que;
        que.push(1);
        while (!que.empty()) {
            auto u = que.front();
            que.pop();
            for (auto& vec : mp[u]) {
                int v = vec.first;
                int cost = vec.second;
                if (cost < result[v]) {
                    result[v] = cost;
                    que.push(v);
                }
            }
        }
        return *min_element(begin(result), end(result));
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<p>> mp;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            mp[u].push_back({v, cost});
            mp[v].push_back({u, cost});
        }
        return bfs(1, mp, n);
    }
};

//DFS
class Solution {
public:
    typedef pair<int, int> p;
    void dfs(int u, unordered_map<int, vector<pair<int, int>>>& mp,
             vector<int>& result) {
        for (auto& vec : mp[u]) {
            int v = vec.first;
            int cost = vec.second;
            if (cost < result[v]) {
                result[v] = cost;
                dfs(v, mp, result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<p>> mp;
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            mp[u].push_back({v, cost});
            mp[v].push_back({u, cost});
        }
        vector<int> result(n + 1, INT_MAX);
        dfs(1, mp, result);
        return *min_element(begin(result), end(result));
    }
};
