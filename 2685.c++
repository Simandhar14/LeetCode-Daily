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

//brute force
class DSU {
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty)
            return;
        if (rank[parentx] > rank[parenty]) {
            parent[parenty] = parentx;
        } else if (rank[parenty] > rank[parentx]) {
            parent[parentx] = parenty;
        } else {
            parent[parentx] = parenty;
            rank[parenty]++;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ob(n);
        unordered_map<int, vector<int>> mp;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ob.Union(u, v);
        }
        for (int i = 0; i < n; i++) {
            int parent = ob.find(i);
            mp[parent].push_back(i);
        }
        int completed = 0;
        for (auto& temp : mp) {
            int len = temp.second.size();
            bool found = true;
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    int a = temp.second[i];
                    int b = temp.second[j];
                    vector<int> pair1 = {a, b};
                    vector<int> pair2 = {b, a};
                    if (find(edges.begin(), edges.end(), pair1) ==
                            edges.end() &&
                        find(edges.begin(), edges.end(), pair2) ==
                            edges.end()) {
                        found = false;
                        break;
                    }
                }
                if (!found)
                    break;
            }
            if (found)
                completed++;
        }
        return completed;
    }
};
