class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0) dp[i][j]=i+j;
                else if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=min(1+dp[i-1][j],1+dp[i][j-1]);
                }
            }
        }
        int i=m,j=n;
        string ans="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
               ans=str1[i-1]+ans;
                i--;
                j--;
            }else if(dp[i-1][j]<dp[i][j-1])
            {
                ans=str1[i-1]+ans;
                i--;
            }else{
                ans=str2[j-1]+ans;
                j--;
            }
        }
        while(i>0)
        {
            ans=str1[i-1]+ans;
            i--;
        }
        while(j>0)
        {
            ans=str2[j-1]+ans;
            j--;
        }
        return ans;
    }
};