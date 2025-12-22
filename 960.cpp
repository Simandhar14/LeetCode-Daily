class Solution {
public:
int dp[101][101];
    int solve(vector<string>& strs, int prev, int col) {
        if (col >= strs[0].size())
            return 0;
        int take=0, skip = 0;
        if(prev!=-1 && dp[prev][col]!=-1) return dp[prev][col];
        bool flag = true;
        if (prev != -1) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][prev] > strs[i][col]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            take = 1 + solve(strs, col, col + 1);  
        } 
        skip = solve(strs, prev, col + 1);
        if(prev!=-1) dp[prev][col]=max(take,skip);
        return max(take,skip);
    }
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].size();
        memset(dp,-1,sizeof(dp));
        int maxlis=solve(strs, -1,0);
        return len - maxlis;
    }
};
