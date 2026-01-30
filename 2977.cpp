class Solution {
public:
 typedef long long ll;
    typedef pair<ll, string> p;
    ll BIG_VALUE = 1e10;
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;
    vector<ll> dp;
    unordered_map<string, vector<pair<string, ll>>> mp;
    ll dijkstra(string& source, string& target) {
        if (dijkstraMemo[source].count(target)) {
            return dijkstraMemo[source][target];
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<string, ll> visited;
        visited[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (u == target)
                break;
            for (auto& temp : mp[u]) {
                string v = temp.first;
                ll wt = temp.second;
                if (!visited.count(v) || cost + wt < visited[v]) {
                    visited[v] = cost + wt;
                    pq.push({cost + wt, v});
                }
            }
        }
        ll finalCost = visited.count(target) ? visited[target] : BIG_VALUE;

        return dijkstraMemo[source][target] = finalCost;
    }
    ll solve(string& source, string& target, int i, set<int>& substrLen) {
        if (i >= target.length())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        ll mincost=BIG_VALUE;
        if (source[i] == target[i]) {
            ll nextcost = solve(source, target, i + 1, substrLen);
            if (nextcost != BIG_VALUE)
                mincost = min(mincost,nextcost);
        }
        for (auto& len : substrLen) {
            if (i + len > source.length())
                break;
            string src = source.substr(i, len);
            string targ = target.substr(i, len);
            if(!mp.count(src)) continue;
            ll cost = dijkstra(src, targ);
            if (cost != BIG_VALUE) {
                mincost =min(mincost,
                    cost + solve(source, target, i + len, substrLen));
            }
        }
        return dp[i] = mincost;
    }
    long long minimumCost(string& source, string& target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        dp.assign(1001, -1);
        int n = original.size();
        for (int i = 0; i < n; i++) {
            mp[original[i]].push_back({changed[i], cost[i]});
        }
        set<int> substrLen;
        for (int i = 0; i < n; i++) {
            substrLen.insert(original[i].length());
        }
        ll result = solve(source, target, 0, substrLen);
        return result == BIG_VALUE ? -1 : result;
    }
};
