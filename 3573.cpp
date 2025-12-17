class Solution {
public:
    /// 1->buy , 2->sell , 0->no state
    long long dp[1001][501][3];
    long long solve(vector<int>& prices, int k, int n, int i, int state) {
        if (k == 0) {
            if (state == 0)
                return 0;
            return LLONG_MIN / 2;
        }
        if (i >= n) {
            if (state == 0)
                return 0;
            return LLONG_MIN / 2;
        }
        if(dp[i][k][state]!=-1) return dp[i][k][state];
        long long ans = LLONG_MIN / 2;
        if (state == 0) {
            ans = max(ans, 1LL * prices[i] + solve(prices, k, n, i + 1, 1));
            ans = max(ans, 1LL * -prices[i] + solve(prices, k, n, i + 1, 2));
        } else if (state == 1) {
            ans =
                max(ans, 1LL * -prices[i] + solve(prices, k - 1, n, i + 1, 0));
        } else if (state == 2) {
            ans = max(ans, 1LL * prices[i] + solve(prices, k - 1, n, i + 1, 0));
        }
         ans = max(ans, solve(prices, k, n, i + 1, state)); 
        return dp[i][k][state]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, k, n, 0, 0);
    }
};
