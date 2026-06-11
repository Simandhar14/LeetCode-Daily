//cpp
class Solution {
public:
    const int M = 1e9 + 7;
    typedef long long ll;
    ll power(ll base, ll exponent) {
        if (exponent == 0)
            return 1;
        ll half = power(base, exponent / 2);
        ll result = (half * half) % M;
        if (exponent % 2 == 1)
            result = (result * base) % M;
        return result % M;
    }
    int findDepth(unordered_map<int, vector<int>>& mp, int root, int parent) {
        int result = 0;
        for (auto& v : mp[root]) {
            if (v != parent) {
                int depth = 1 + findDepth(mp, v, root);
                result = max(result, depth);
            }
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int nodes = mp.size();
        int depth = findDepth(mp, 1, -1);
        return power(2, depth - 1) % M;
    }
};
