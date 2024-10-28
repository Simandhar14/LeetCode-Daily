class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int root = (int)sqrt(nums[i]);
            if (root * root == nums[i] && mp.find(root) != mp.end()) {
                mp[nums[i]] = 1 + mp[root];
            } else {
                mp[nums[i]] = 1;
            }
            result = max(mp[nums[i]], result);
        }
        return result <= 1 ? -1 : result;
    }
};