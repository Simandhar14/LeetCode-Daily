class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j,
              int prev) {
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] <= prev)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = 0, updiag = 0, downdiag = 0;
        if (prev == -1) {
            right = solve(grid, dp, i, j + 1, grid[i][j]);
            updiag = solve(grid, dp, i - 1, j + 1, grid[i][j]);
            downdiag = solve(grid, dp, i + 1, j + 1, grid[i][j]);
        } else {
            right = 1 + solve(grid, dp, i, j + 1, grid[i][j]);
            updiag = 1 + solve(grid, dp, i - 1, j + 1, grid[i][j]);
            downdiag = 1 + solve(grid, dp, i + 1, j + 1, grid[i][j]);
        }
        return dp[i][j] = max({right, updiag, downdiag});
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int result = 0;
        for (int i = 0; i < m; i++) {
            int ans = solve(grid, dp, i, 0, -1);
            result = max(result, ans);
        }
        return result;
    }
};