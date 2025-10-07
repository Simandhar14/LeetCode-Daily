class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> mp;
        vector<int> zeros;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeros.push_back(i);
                continue;
            }
            if (mp.count(rains[i])) {
                int lastSeen = mp[rains[i]];
                auto it = upper_bound(begin(zeros), end(zeros), lastSeen); 
                if (it == zeros.end())
                    return {};
                ans[*it] = rains[i];
                zeros.erase(it);
            }
            mp[rains[i]] = i; 
        }

        for (auto it = begin(zeros); it != end(zeros); it++)
            ans[*it] = 1;

        return ans;
    }
};
