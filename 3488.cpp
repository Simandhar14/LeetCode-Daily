//cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int num = nums[idx];
            if (mp[num].size() == 1)
                result[i] = -1;
            else {
                int minDist = INT_MAX;
                auto it = upper_bound(begin(mp[num]), end(mp[num]), idx);
                if (it != mp[num].end()) {
                    minDist = min(minDist, *it - idx);
                } else {
                    it = mp[num].begin();
                    if (*it != idx)
                        minDist = min(minDist, n - (idx - *it));
                }
                it = lower_bound(begin(mp[num]), end(mp[num]), idx);
                if (it != mp[num].begin()) {
                    it--;
                    minDist = min(minDist, idx - *it);
                } else {
                    it = mp[num].end();
                    it--;
                    if (*it != idx)
                        minDist = min(minDist, n - (*it - idx));
                }
                result[i] = minDist;
            }
        }
        return result;
    }
};
