class Solution {
public:
void dfs( vector<bool>&recursion, vector<bool>&visited,vector<vector<int>>& graph,int u)
{
    visited[u]=true;
    recursion[u]=true;
    for(int v:graph[u])
    {
        if(!visited[v]) dfs(recursion,visited,graph,v);
        if(recursion[v]==true) return;
    }
    recursion[u]=false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>recursion(n,false);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(recursion,visited,graph,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!recursion[i]) ans.emplace_back(i);
        }
        return ans;
    }
};