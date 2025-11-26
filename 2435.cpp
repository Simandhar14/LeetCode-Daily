class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(vector<vector<int>>& grid, int rem, int i, int j,int k, vector<vector<vector<int>>>&dp) {
        if (i >=grid.size() || j >=grid[0].size() || i < 0 || j < 0)
            return 0;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        int newrem = (grid[i][j] + rem) % k;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (newrem == 0)
                return 1;
            return 0;
        }
        int down = (solve(grid,  newrem, i + 1, j,k,dp) % MOD);
        int right = (solve(grid,  newrem, i, j + 1,k,dp) % MOD);
        return dp[i][j][rem]=(down + right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
       vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid, 0, 0, 0,k,dp);
    }
};
