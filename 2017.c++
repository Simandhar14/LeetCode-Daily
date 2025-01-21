class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum =
            accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemainSum=0;
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            firstRowRemainSum-=grid[0][i];
            long long bestpath=max(firstRowRemainSum,secondRowRemainSum);
            ans=min(ans,bestpath);
            secondRowRemainSum+=grid[1][i];
        }
        return ans;
    }
};