//cpp
class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool Union(int x,int y)
    {
        int parentx=find(x);
        int parenty=find(y);
        if(parentx==parenty) return false;
        if(rank[parentx]>rank[parenty])
        {
            parent[parenty]=parentx;
        }else if(rank[parenty]>rank[parentx])
        {
            parent[parentx]=parenty;
        }else{
            parent[parentx]=parenty;
            rank[parenty]++;
        }
        return true;
    }
};
class Solution {
public:
bool check(int n,vector<vector<int>>&edges,int k,int mid)
{
    DSU dsu(n);
    vector<vector<int>> upgradeCandidates;

    for(auto &edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int s=edge[2];
        int m=edge[3];

        if(m==1)
        {
            if(s<mid) return false;
            dsu.Union(u,v);
        }
        else
        {
            if(s>=mid)
            {
                dsu.Union(u,v);
            }
            else if(2*s>=mid)
            {
                upgradeCandidates.push_back(edge);
            }
        }
    }

    for(auto &edge:upgradeCandidates)
    {
        int u=edge[0];
        int v=edge[1];

        if(dsu.find(u)!=dsu.find(v))
        {
            if(k<=0) return false;
            dsu.Union(u,v);
            k--;
        }
    }

    int root=dsu.find(0);

    for(int node=1;node<n;node++)
    {
        if(dsu.find(node)!=root)
            return false;
    }

    return true;
}
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int m=edge[3];
            if(m==1)
            {
                if(dsu.find(u)==dsu.find(v)) return -1;
                dsu.Union(u,v);
            }
        }

        int result=-1;
        int l=1;
        int r=2*1e5;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(n,edges,k,mid))
            {
                result=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
};
