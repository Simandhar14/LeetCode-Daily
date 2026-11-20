//cpp
class Solution {
public:
    int n;
    int solve(int i, int inc, vector<int>& nums, vector<vector<int>>& dp) {
        int result = 0;
        int currval = nums[i] + inc;
        if (dp[i][inc] != -1)
            return dp[i][inc];
        auto it = lower_bound(begin(nums) + i + 1, end(nums), currval + 1);
        if (it != end(nums) && *it == currval + 1) {
            int index = it - begin(nums);
            result = max(result, 1 + solve(index, 0, nums, dp));
        }
        it = lower_bound(begin(nums) + i + 1, end(nums), currval);
        if (it != end(nums) && *it == currval) {
            int index = it - begin(nums);
            result = max(result, 1 + solve(index, 1, nums, dp));
        }
        return dp[i][inc] = result;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            int op1 = 1 + solve(i, 0, nums, dp);
            int op2 = 1 + solve(i, 1, nums, dp);
            result = max({result, op1, op2});
        }
        return result;
    }
};
