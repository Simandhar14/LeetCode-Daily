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

//better approach with just O(max(row)) space

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int row=n-2;row>=0;row--)
        {
            vector<int>temp=triangle[row+1];
            for(int col=0;col<=row;col++)
            {
                triangle[row][col]+=min(temp[col],temp[col+1]);
            }
            temp=triangle[row];
        }
        return triangle[0][0];
    }
};
