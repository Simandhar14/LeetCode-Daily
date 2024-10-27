class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i,
              int j) {
        if (i >= m || j >= n)
            return 0;
        if (matrix[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solve(matrix,dp, i, j + 1);
        int down = solve(matrix,dp, i + 1, j);
        int diag = solve(matrix,dp, i + 1, j + 1);
        return dp[i][j]=1 + min({right, down, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(301, vector<int>(301, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    ans += solve(matrix, dp, i, j);
            }
        }
        return ans;
    }
};