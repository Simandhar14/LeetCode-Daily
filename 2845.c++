class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long result = 0;
        int count = 0;
        unordered_map<int, long long> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k)
                count++;

            int rem = count % modulo;
            int target = (rem - k + modulo) % modulo;

            if (mp.find(target) != mp.end()) {
                result += mp[target];
            }

            mp[rem]++;
        }

        return result;
    }
};
