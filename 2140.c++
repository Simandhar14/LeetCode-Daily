class Solution {
public:
int n;
long long solve(vector<vector<int>>& questions,int i,vector<long long>&dp)
{
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    long long take=questions[i][0]+solve(questions,i+questions[i][1]+1,dp);
    long long skip=solve(questions,i+1,dp);
    return dp[i]=max(take,skip);
}
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long>dp(n,-1);
        return solve(questions,0,dp);
    }
};
