//cpp
class Solution {
public:
int solve(int i,int j,int k,vector<vector<int>>& grid)
{
    set<int>st;
    for(int row=i;row<i+k;row++)
    {
        for(int col=j;col<j+k;col++)
        {
            st.insert(grid[row][col]);
        }
    }
    if(st.size()==1) return 0;
    int diff=INT_MAX;
    for(auto it=st.begin();it!=st.end();it++)
    {
        int num1=*it;
        auto nextit=next(it);
        if(nextit==st.end()) return diff;
        int num2=*nextit;
        diff=min(diff,abs(num2-num1));
    }
    return diff;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i+k<=m;i++)
        {
            for(int j=0;j+k<=n;j++){
                int minDiff=solve(i,j,k,grid);
                ans[i][j]=minDiff;
            }
        }
        return ans;
    }
};
