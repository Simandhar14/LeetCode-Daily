//cpp
class Solution {
public:
    int solve(int n, vector<int>& perfectSq, int alice,
              vector<vector<int>>& dp) {
        if (n == 0) {
            return !alice;
        }
        if (dp[n][alice] != -1)
            return dp[n][alice];
        int i = 0;
        while (i<perfectSq.size() && perfectSq[i] <= n) {
            int stones = perfectSq[i];
            int ans = solve(n - stones, perfectSq, !alice,dp);
            if (alice && ans)
                return dp[n][alice] = true;
            if (!alice && !ans)
                return dp[n][alice] = false;
            i++;
        }
        return dp[n][alice] = !alice;
    }

    bool winnerSquareGame(int n) {
        if (n == 1)
            return true;
        int sq = sqrt(n);
        if (sq * sq == n)
            return true;
        vector<int> perfectSq;
        for (int i = 1; i <= n; i++) {
            if (i * i > n)
                break;
            perfectSq.push_back(i * i);
        }
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(n, perfectSq, 1, dp);
    }
};
