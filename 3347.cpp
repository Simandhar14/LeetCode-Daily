class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxnum = *max_element(begin(nums), end(nums)) + k;
        map<int, int> mp; // difference array technique
        int ans = 1;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxnum);

            mp[l]++;
            mp[r + 1]--;

            mp[nums[i]] += 0; 
        }
        int cumsum = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int target = it->first;
            it->second += cumsum;

            int targetCount = freq[target];
            int requiredOperations = it->second - targetCount;
            int possibleOperations = min(requiredOperations, numOperations);
            ans = max(ans, targetCount + possibleOperations);
            cumsum = it->second;
        }
        return ans;
    }
};
