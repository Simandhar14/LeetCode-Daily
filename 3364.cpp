//cpp
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int result = INT_MAX;
        int n = nums.size();
        for (int i = 0; i <= n - l; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r && sum > 0)
                    result = min(result, sum);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
