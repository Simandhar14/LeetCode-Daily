class Solution {
public:
int solve(int i,int j,vector<int>&arr,  unordered_map<int,int>&mp, vector<vector<int>>&dp)
{
    if(dp[i][j]!=-1) return dp[i][j];
    int target=arr[j]-arr[i];
    if(mp.count(target))
    {
        if(mp[target]<i)
        {
            return dp[i][j]=1+solve(mp[target],i,arr,mp,dp);
        }
    }
    return dp[i][j]=2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        int result=0;
        for(int j=1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int length=solve(j,k,arr,mp,dp);
                if(length>=3) result=max(result,length);
            }
        }
        return result;
    }
};

//Bottom up DP

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(n,2));
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        int result=0;
        for(int j=1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
              int target=arr[k]-arr[j];
              if(mp.count(target) && mp[target]<j)
              {
                int i=mp[target];
                dp[j][k]=dp[i][j]+1;
              }
              result=max(result,dp[j][k]);
            }
        }
        return result>=3 ? result : 0;
    }
};