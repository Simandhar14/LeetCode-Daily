class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> leftFreq;
        unordered_map<int, int> rightFreq;
        int n = nums.size();
        long long specialTriplets = 0;
        for (int& num : nums)
            rightFreq[num]++;
        for (int i = 0; i < n; i++) {
            rightFreq[nums[i]]--;
            int num = nums[i] * 2;
            specialTriplets += (1LL * leftFreq[num] * rightFreq[num]) % MOD;
            leftFreq[nums[i]]++;
        }
        return specialTriplets % MOD;
    }
};
