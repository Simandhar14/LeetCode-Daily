//bottom up
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();
        int dp[n][n];
        for (int start = (n / 2) - 1; start < n; start++) {
            for (int end = (n / 2) - 1; end >= 0; end--) {
                if (start == end)
                    dp[start][end] = piles[start];
                else
                    dp[start][end] = 0;
            }
        }
        for (int start = 0; start < n; start++) {
            for (int end = n - 1; end >= 0; end--) {
                int take1 = piles[start] + dp[start + 1][end - 1];
                int take3 = piles[start] + dp[start + 2][end];
                int leftChoice = min(take1, take3);
                int take2 = piles[end] + dp[start + 1][end - 1];
                int take4 = piles[end] + dp[ start][end - 2];
                int rightChoice = min(take2, take4);
                return dp[start][end] = max(leftChoice, rightChoice);
            }
        }
        return dp[0][n - 1];
    }
};

//top down
class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& piles, int start, int end) {
        if (start > end)
            return 0;
        if (start == end)
            return piles[start];
        if (dp[start][end] != -1)
            return dp[start][end];
        int take1 = piles[start] + solve(piles, start + 1, end - 1);
        int take3 = piles[start] + solve(piles, start + 2, end);
        int leftChoice = min(take1, take3);

        int take2 = piles[end] + solve(piles, start + 1, end - 1);
        int take4 = piles[end] + solve(piles, start, end - 2);
        int rightChoice = min(take2, take4);

        return dp[start][end] = max(leftChoice, rightChoice);
    }

    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        memset(dp, -1, sizeof(dp));
        int alice = solve(piles, 0, piles.size() - 1);
        return alice > total - alice;
    }
};
