class Solution {
public:
int components=0;
int dfs(unordered_map<int,vector<int>>&mp,vector<int>&values,int k,vector<bool>&visited,int u)
{
    visited[u]=true;
    long long val=values[u];
    for(int &v:mp[u])
    {
        if(!visited[v])
        {
            val+=dfs(mp,values,k,visited,v);
        }
    }
    if(val%k==0) {
        components++;
        return 0;
    }
    return val%k;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp;
        for(auto &temp:edges)
        {
            int u=temp[0];
            int v=temp[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        dfs(mp,values,k,visited,0);
        return components;
    }
};
