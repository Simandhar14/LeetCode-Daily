class Solution {
public:
int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,skip1=0,skip2=0;
        if(s1[i]==s2[j])
        {
            take+=(2*((s1[i]-'a')+97)+solve(s1,s2,i+1,j+1));
        }
        skip1=solve(s1,s2,i+1,j);
        skip2=solve(s1,s2,i,j+1);
        return dp[i][j]=max({take,skip1,skip2});
    }
    int minimumDeleteSum(string s1, string s2) {
        int totalsum = 0;
        for (int i = 0; i < s1.size(); i++) {
            totalsum += (s1[i] - 'a')+97;
        }
        for (int j = 0; j < s2.size(); j++) {
            totalsum += (s2[j] - 'a')+97;
        }
        memset(dp,-1,sizeof(dp));
        return totalsum-solve(s1,s2,0,0);
    }
};
