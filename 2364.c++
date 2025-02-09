class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long n = nums.size();
        long long total_pairs = (n * (n - 1)) / 2;  
        long long not_bad_pairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            not_bad_pairs += mp[key];  
            mp[key]++;  
        }

        return total_pairs - not_bad_pairs;
    }
};
