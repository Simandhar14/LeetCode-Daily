class Solution {
public:
void dfs( unordered_map<int,vector<int>>&adj,int u,int &edges,int &nodes, vector<bool>&visitednodes)
{
    if(!visitednodes[u])
    {
        visitednodes[u]=true;
        edges=edges+adj[u].size();
        nodes++;
    }
    for(int &v:adj[u])
    {
        if(!visitednodes[v])
        {
            
            dfs(adj,v,edges,nodes,visitednodes);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int completecomponent=0;
      vector<bool>visitednodes(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visitednodes[i])
            {
                int edges=0;
                int nodes=0;
                dfs(adj,i,edges,nodes,visitednodes);
                int formula=(nodes*(nodes-1))/2;
                if(edges/2==formula) completecomponent++;
            }
        }
        return completecomponent;
    }
};
