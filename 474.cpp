class Solution {
public:
int dp[101][101][601];
    int solve( vector<string>& strs,int m, int n, int i, int ones,
              int zeros) {
        if (i >= strs.size()) {
           return 0;
        }
        if(dp[ones][zeros][i]!=-1) return dp[ones][zeros][i];
        int len=strs[i].size();
        int count1=0,count0=0;
        for(char &ch:strs[i])
        {
            if(ch=='1') count1++;
            else count0++;
        }
        int newones = ones + count1;
        int newzeros = zeros + count0;
        int take = 0, skip = 0;
        if (newones <=n && newzeros <= m) {
            take = 1+solve(strs, m, n, i + 1, newones, newzeros);
        }
        skip = solve(strs, m, n, i + 1, ones, zeros);
        return dp[ones][zeros][i]=max({take, skip});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        sort(begin(strs), end(strs));
        return solve(strs, m, n, 0, 0, 0);
    }
};
