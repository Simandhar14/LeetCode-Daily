class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxsum = INT_MIN;
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            mp[nums[j]]++;
            while (mp[nums[j]] == 2) {
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
