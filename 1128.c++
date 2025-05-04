class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<pair<int, int>, int, pair_hash> mp;
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            pair<int, int> temp = a<b ? make_pair(a, b) : make_pair(b, a) ;
            if (mp.find(temp) != mp.end())
            {
                pairs+=mp[temp];
            }
            mp[temp]++;
        }
        return pairs;
    }
};
