class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& triangle, int row, int i) {
        if (row >= triangle.size())
            return 0;
        if(dp[row][i]!=INT_MAX) return dp[row][i];
        int sum = triangle[row][i];
        int take1 = solve(triangle, row + 1, i);
        if (row + 1 < triangle.size() && i + 1 < triangle[row + 1].size()) {
            int take2 = solve(triangle, row + 1, i + 1);
            return dp[row][i]=sum + min({take1, take2});
        }
        return dp[row][i]=sum + take1;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        dp.resize(row, vector<int>(row, INT_MAX));
        return solve(triangle, 0, 0);
    }
};
