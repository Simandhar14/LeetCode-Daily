//cpp
class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int solve(int i, int j, int open, vector<vector<char>>& grid,
              vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j][open] != -1)
            return dp[i][j][open];
        int newopen = open;
        if (grid[i][j] == '(')
            newopen++;
        else
            newopen--;
        if (newopen < 0)
            return 0;
        if (i == m - 1 && j == n - 1) {
            return newopen == 0 ? 1 : 0;
        }

        int result = 0;
        for (auto& d : dir) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (solve(newi, newj, newopen, grid, dp)) {
                result = 1;
                break;
            }
        }
        return dp[i][j][open] = result;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(m + n, -1)));
        if (grid[0][0] == ')')
            return false;
        return solve(0, 0, 0, grid, dp);
    }
};
