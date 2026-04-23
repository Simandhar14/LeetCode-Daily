//cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        unordered_map<int, pair<int, long long>> mp;
        for (int i = 0; i < n; ++i) {
            auto& [count, sumIdx] = mp[nums[i]];
            res[i] += (long long)count * i - sumIdx;
            count++;
            sumIdx += i;
        }
        mp.clear();
        for (int i = n - 1; i >= 0; --i) {
            auto& [count, sumIdx] = mp[nums[i]];
            res[i] += sumIdx - (long long)count * i;
            count++;
            sumIdx += i;
        }
        return res;
    }
};
