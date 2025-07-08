class Solution {
public:
int solve(vector<vector<int>>& events, int k,int i,vector<vector<int>>&dp)
{
    if(k==0 || i>=events.size()) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int take=0;
    int nottake=0;
    int nextidx=events.size();
    for(int j=i+1;j<events.size();j++)
    {
        if(events[j][0]>events[i][1])
        {
            nextidx=j;
            break;
        }
    }
    take+=events[i][2]+solve(events,k-1,nextidx,dp);
    nottake+=solve(events,k,i+1,dp);
    return dp[i][k]=max(take,nottake);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        int i=0;
        return solve(events,k,i,dp);
    }
};
