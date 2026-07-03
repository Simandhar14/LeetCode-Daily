//cpp
class Solution {
public:
    typedef pair<long long, int> p;
    long long solve(long long mid, unordered_map<int, vector<p>>& adj,
                    long long k, vector<bool>& online) {
        if (!online[0])
            return -1;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        int n = online.size();
        vector<long long> result(n, LLONG_MAX);
        result[0] = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            long long remaink = temp.first;
            int u = temp.second;
            if (remaink > result[u])
                continue;
            if (u == n - 1)
                return mid;
            for (auto& vec : adj[u]) {
                int v = vec.second;
                long long cost = vec.first;
                if (remaink + cost > k || cost < mid || !online[v])
                    continue;
                if (remaink + cost < result[v]) {
                    result[v] = remaink + cost;
                    pq.push({remaink + cost, v});
                }
            }
        }
        return -1;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        unordered_map<int, vector<p>> adj;
        for (auto& temp : edges) {
            int u = temp[0];
            int v = temp[1];
            int cost = temp[2];
            adj[u].push_back({cost, v});
        }
        long long left = 0;
        long long right = k;
        long long result = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (solve(mid, adj, k, online) >= mid) {
                result = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return result;
    }
};
