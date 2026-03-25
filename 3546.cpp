//cpp
class Solution {
public:
    bool solve(vector<vector<int>>& grid,int m, int n,bool flag) {
        long long totalSum = 0;
        vector<long long> sum(m, 0);
        for (int i = 0; i < m; i++) {
            long long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += flag==true ? grid[i][j] : grid[j][i];
                totalSum += flag==true ? grid[i][j] : grid[j][i];
            }
            sum[i] = rowSum;
        }
        long long cumSum = 0;
        for (int i = 0; i < m; i++) {
            cumSum += sum[i];
            if (cumSum == totalSum - cumSum)
                return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid,m,n,true) || solve(grid,n,m,false);
    }
};
