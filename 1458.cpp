class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i >= nums1.size() || j >= nums2.size())
            return INT_MIN;
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        int take = INT_MIN, skip1 = INT_MIN, skip2 = INT_MIN;
        int product = nums1[i] * nums2[j];
        take=product;
        int next = solve(nums1, nums2, i + 1, j + 1);
        if (next != INT_MIN)
            take = max(take, product + next);
        skip1 = solve(nums1, nums2, i + 1, j);
        skip2 = solve(nums1, nums2, i, j + 1);
        return dp[i][j] = max({take, skip1, skip2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                dp[i][j] = INT_MIN;
        return solve(nums1, nums2, 0, 0);
    }
};
