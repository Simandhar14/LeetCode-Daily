//cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[201][201][201];

    int solve(int i, int gcd1, int gcd2, vector<int>& nums) {
        if (i == nums.size()) {
            return (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2);
        }

        if (dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];

        long long ans = 0;

        ans += solve(i + 1, gcd(gcd1, nums[i]), gcd2, nums);

        ans += solve(i + 1, gcd1, gcd(gcd2, nums[i]), nums);

        ans += solve(i + 1, gcd1, gcd2, nums);

        return dp[i][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};
