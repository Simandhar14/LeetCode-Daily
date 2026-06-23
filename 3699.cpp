//top-down dp
class Solution {
public:
    const int M = 1e9 + 7;
    int solve(int n, int l, int r, int first, int second,
              vector<vector<vector<int>>>& dp) {
        if (n == 0)
            return 1;
        if (first != -1 && second != -1 && dp[n][first][second] != -1)
            return dp[n][first][second];
        int take = 0;
        for (int num = l; num <= r; num++) {
            if (first == -1) {
                take = (take + solve(n - 1, l, r, num, second, dp) % M) % M;
            } else if (second == -1 && num != first) {
                take = (take + solve(n - 1, l, r, first, num, dp) % M) % M;
            } else if (first != -1 && second != -1 && num != second &&
                       !((first < second && second < num) ||
                         (first > second && second > num))) {
                take = (take + solve(n - 1, l, r, second, num, dp) % M) % M;
            }
        }
        if (first != -1 && second != -1)
            dp[n][first][second] = take % M;
        return take % M;
    }
    int zigZagArrays(int n, int l, int r) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(r + 1, vector<int>(r + 1, -1)));
        return solve(n, l, r, -1, -1, dp) % M;
    }
};
