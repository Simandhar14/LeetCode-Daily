//cpp - using top down approach
class Solution {
public:
    int m, n;
    int solve(int i, int j, int val, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[i][j] ^ val;
        if (dp[i][j][val] != -1)
            return dp[i][j][val];
        int right = solve(i, j + 1, val ^ grid[i][j], grid, dp);
        int down = solve(i + 1, j, val ^ grid[i][j], grid, dp);
        int result = min(right, down);
        return dp[i][j][val] = result;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, -1)));
        int result = solve(0, 0, 0, grid, dp);
        return result;
    }
};
